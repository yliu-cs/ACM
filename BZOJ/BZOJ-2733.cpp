#include <bits/stdc++.h>
#include <bits/extc++.h>
typedef __gnu_pbds::tree<int, int, std::less<int>, __gnu_pbds::splay_tree_tag, __gnu_pbds::tree_order_statistics_node_update> splay_tree;
const int maxn = 1e5 + 5;

int n, m;
int pre[maxn];
int sz[maxn];
splay_tree tree[maxn];
int q;

int Find(int x) {
  return pre[x] == x ? x : pre[x] = Find(pre[x]);
}

void Merge(int x, int y) {
  int anc_x = Find(x), anc_y = Find(y);
  if (anc_x == anc_y) return;
  if (sz[anc_x] > sz[anc_y]) {
    std::swap(x, y);
    std::swap(anc_x, anc_y);
  }
  for (splay_tree::iterator it = tree[anc_x].begin(); it != tree[anc_x].end(); ++it) {
    tree[anc_y][it->first] = it->second;
  }
  pre[anc_x] = anc_y;
  sz[anc_y] += sz[anc_x];
  tree[anc_x].clear();
}

int Query(int x, int k) {
  int anc_x = Find(x);
  if (k > (int)tree[anc_x].size()) return -1;
  return tree[anc_x].find_by_order(k - 1)->second;
}

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0); std::cout.tie(0);

  std::cin >> n >> m;
  for (int i = 1; i <= n; ++i) {
    pre[i] = i;
    sz[i] = 1;
  }

  for (int i = 1, rk; i <= n; ++i) {
    std::cin >> rk;
    tree[i][rk] = i;
  }

  for (int i = 1, u, v; i <= m; ++i) {
    std::cin >> u >> v;
    Merge(u, v);
  }

  std::cin >> q;
  for (int i = 1; i <= q; ++i) {
    char op; std::cin >> op;
    if (op == 'B') {
      int u, v; std::cin >> u >> v;
      Merge(u, v);
    }
    else if (op == 'Q') {
      int x, k; std::cin >> x >> k;
      std::cout << Query(x, k) << '\n';
    }
  }
  return 0;
}

