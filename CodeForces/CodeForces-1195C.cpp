#include <bits/stdc++.h>

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int n;
  std::cin >> n;
  std::vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    std::cin >> a[i];
  }
  std::vector<int> b(n);
  for (int i = 0; i < n; ++i) {
    std::cin >> b[i];
  }
  std::vector<std::vector<long long>> dp(2, std::vector<long long>(n));
  dp[0][0] = a[0];
  dp[1][0] = b[0];
  long long ans = std::max(dp[0][0], dp[1][0]);
  for (int i = 1; i < n; ++i) {
    dp[0][i] = std::max(a[i] + dp[1][i - 1], dp[0][i - 1]);
    dp[1][i] = std::max(b[i] + dp[0][i - 1], dp[1][i - 1]);
    ans = std::max(dp[0][i], dp[1][i]);
  }
  std::cout << ans << '\n';
  return 0;
}

