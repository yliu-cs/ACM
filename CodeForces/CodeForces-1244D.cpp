// Author: Tony5t4rk Time: 2019-10-13 17:52:37 
#include <bits/stdc++.h>
const long long inf = 1e18 + 5;
const int maxn = 1e5 + 5;
int n;
int c[5][maxn];
std::vector<int> g[maxn];
int deg[maxn];
int rt;
int ansv[maxn], co[maxn];
long long ans, sum;
void Dfs(int u, int p, int f1, int f2) {
  sum += c[f1][u];
  co[u] = f1;
  for (auto &v : g[u]) {
    if (v == p) continue;
    for (int i = 1; i <= 3; ++i) {
      if (i != f1 && i != f2) Dfs(v, u, i, f1);
    }
  }
}
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cin >> n;
  for (int k = 1; k <= 3; ++k) for (int i = 1; i <= n; ++i) std::cin >> c[k][i];
  for (int i = 1, u, v; i < n; ++i) {
    std::cin >> u >> v;
    ++deg[u]; ++deg[v];
    g[u].push_back(v);
    g[v].push_back(u);
  }
  for (int i = 1; i <= n; ++i) if (deg[i] > 2) {
    std::cout << -1 << '\n';
    return 0;
  }
  for (int i = 1; i <= n; ++i) {
    if (deg[i] == 1) {
      rt = i;
      break;
    }
  }
  ans = inf;
  for (int i = 1; i <= 3; ++i) {
    for (int j = 1; j <= 3; ++j) {
      if (i == j) continue;
      sum = 0;
      for (int k = 1; k <= n; ++k) co[k] = 0;
      Dfs(rt, 0, i, j);
      if (sum < ans) {
        ans = sum;
        for (int k = 1; k <= n; ++k) ansv[k] = co[k];
      }
    }
  }
  std::cout << ans << '\n';
  for (int i = 1; i <= n; ++i) std::cout << ansv[i] << ' ';
  return 0;
}
