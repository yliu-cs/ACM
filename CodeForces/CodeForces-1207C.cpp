#include <bits/stdc++.h>

const long long INF = 1e18 + 5;

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int t;
  std::cin >> t;
  while (t--) {
    long long n, a, b;
    std::cin >> n >> a >> b;
    std::string s;
    std::cin >> s;
    std::vector<std::vector<long long>> dp(n + 1, std::vector<long long>(2, INF));
    dp[0][0] = b;
    for (int i = 1; i <= n; ++i) {
      if (s[i - 1] == '1') {
        dp[i][1] = dp[i - 1][1] + a + 2 * b;
      }
      else {
        dp[i][0] = std::min(dp[i - 1][0] + a + b, dp[i - 1][1] + 2 * a + b);
        dp[i][1] = std::min(dp[i - 1][0] + 2 * a + 2 * b, dp[i - 1][1] + a + 2 * b);
      }
    }
    std::cout << dp[n][0] << '\n';
  }
  return 0;
}

