#include <bits/stdc++.h>
#include <bits/extc++.h>
const int maxn = 5e5 + 5;

int pre[maxn];
int sz[maxn];

int Find(int x) {
  return pre[x] == x ? x : pre[x] = Find(pre[x]);
}

void Union(int x, int y) {
  int xx = Find(x), yy = Find(y);
  if (xx == yy) return;
  pre[xx] = yy;
  sz[yy] += sz[xx];
}

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr); std::cout.tie(nullptr);

  int n, m; std::cin >> n >> m;
  for (int i = 1; i <= n; ++i) {
    sz[i] = 1;
    pre[i] = i;
  }
  for (int i = 1; i <= m; ++i) {
    int k; std::cin >> k;
    int o;
    if (k) std::cin >> o;
    for (int j = 1; j < k; ++j) {
      int x; std::cin >> x;
      Union(x, o);
    }
  }

  for (int i = 1; i <= n; ++i) std::cout << sz[Find(i)] << ' ';
  std::cout << '\n';
  return 0;
}

