#include <bits/stdc++.h>
const int maxn = 1e6 + 5;

struct SegTree {
  struct node {
    long long sz, v;
    node() {sz = v = 0ll;}
  };

  node tree[maxn << 2];

  node Unite(const node &k1, const node &k2) {
    node ret;
    ret.sz = k1.sz + k2.sz;
    ret.v = k1.v + k2.v;
    return ret;
  }

  void Pull(int o) {
    tree[o] = Unite(tree[o << 1], tree[o << 1 | 1]);
  }

  void Modify(int o, int l, int r, int idx, long long v) {
    if (l == idx && r == idx) {
      tree[o].sz += v;
      tree[o].v += idx * v;
      return;
    }
    int m = (l + r) >> 1;
    if (idx <= m) Modify(o << 1, l, m, idx, v);
    if (idx > m) Modify(o << 1 | 1, m + 1, r, idx, v);
    Pull(o);
  }
  void Modify(int idx, long long v) {
    Modify(1, 1, maxn - 1, idx, v);
  }

  long long Query(int o, int l, int r, int k) {
    if (l == r) return std::min((long long)k, tree[o].sz) * l;
    int m = (l + r) >> 1;
    if (k <= tree[o << 1].sz) return Query(o << 1, l, m, k);
    else return tree[o << 1].v + Query(o << 1 | 1, m + 1, r, k - tree[o << 1].sz);
  }
  long long Query(int k) {
    return Query(1, 1, maxn - 1, k);
  }
}tree;

struct tariff {int l, r, c, p;};

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr); std::cout.tie(nullptr);

  int n, k, m; std::cin >> n >> k >> m;
  std::vector<tariff> t(m);
  std::map<int, std::vector<int>> add, del;
  for (int i = 0; i < m; ++i) {
    std::cin >> t[i].l >> t[i].r >> t[i].c >> t[i].p;
    add[t[i].l].emplace_back(i);
    del[t[i].r].emplace_back(i);
  }

  long long ans = 0;
  for (int i = 1; i <= n; ++i) {
    for (int &idx : add[i]) tree.Modify(t[idx].p, t[idx].c);
    ans += tree.Query(k);
    for (int &idx : del[i]) tree.Modify(t[idx].p, -t[idx].c);
  }

  std::cout << ans << '\n';
  return 0;
}

