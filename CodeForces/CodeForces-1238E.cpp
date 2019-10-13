// Author: Tony5t4rk Time: 2019-10-10 17:05:35 
#include <bits/stdc++.h>
const int inf = 1e9 + 5;
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int n, m;
  std::cin >> n >> m;
  std::string str;
  std::cin >> str;
  std::vector<std::vector<int>> adj(m, std::vector<int>(m, 0));
  for (int i = 1; i < n; ++i) {
    int u = str[i] - 'a', v = str[i - 1] - 'a';
    ++adj[u][v]; ++adj[v][u];
  }
  std::vector<int> dp(1 << m, inf);
  dp[0] = 0;
  for (int i = 0; i < (1 << m); ++i) {
    for (int j = 0; j < m; ++j) if (i & (1 << j)) dp[i] = std::min(dp[i], dp[i ^ (1 << j)]);
    for (int j = 0; j < m; ++j) if (i & (1 << j)) for (int k = 0; k < m; ++k) if (!(i & (1 << k))) dp[i] += adj[j][k];
  }
  std::cout << dp[(1 << m) - 1] << '\n';
  return 0;
}
