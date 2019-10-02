// Author: Tony5t4rk Time: 2019-10-02 10:35:55 
#include <bits/stdc++.h>
const int maxn = 1e5 + 5;
int n, m;
std::set<int> g[maxn];
int ans[maxn];
std::vector<int> group[4];
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cin >> n >> m;
  for (int i = 1, u, v; i <= m; ++i) {
    std::cin >> u >> v;
    g[u].emplace(v);
    g[v].emplace(u);
  }
  for (int i = 1; i <= 3; ++i) {
    int fi = 0;
    for (int j = 1; j <= n; ++j) {
      if (!ans[j]) {
        fi = j;
        break;
      }
    }
    if (!fi) {
      std::cout << -1 << '\n';
      return 0;
    }
    ans[fi] = i;
    for (int j = 1; j <= n; ++j) {
      if (fi != j && !ans[j] && g[fi].find(j) == g[fi].end()) ans[j] = i;
    }
  }
  for (int i = 1; i <= n; ++i) {
    if (!ans[i]) {
      std::cout << -1 << '\n';
      return 0;
    }
    else group[ans[i]].emplace_back(i);
  }
  int cnt = 0;
  for (int i = 1; i <= 3; ++i) {
    for (int j = i + 1; j <= 3; ++j) {
      for (auto &v1 : group[i]) {
        for (auto &v2 : group[j]) {
          if (g[v1].find(v2) == g[v1].end()) {
            std::cout << -1 << '\n';
            return 0;
          }
          else ++cnt;
        }
      }
    }
  }
  if (cnt != m) {
    std::cout << -1 << '\n';
    return 0;
  }
  for (int i = 1; i <= n; ++i) std::cout << ans[i] << ' ';
  return 0;
}
