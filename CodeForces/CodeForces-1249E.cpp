// Author: Tony5t4rk Time: 2019-10-24 10:07:25 
#include <bits/stdc++.h>
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int n, c;
  std::cin >> n >> c;
  std::vector<int> a(n, 0), b(n, 0);
  for (int i = 1; i < n; ++i) std::cin >> a[i];
  for (int i = 1; i < n; ++i) std::cin >> b[i];
  std::vector<int> ans(n, 0);
  std::vector<std::vector<int>> dp(n, std::vector<int>(2, 0));
  dp[0][1] = c;
  for (int i = 1; i < n; ++i) {
    dp[i][0] = std::min(dp[i - 1][0] + a[i], dp[i - 1][1] + a[i]);
    dp[i][1] = std::min(dp[i - 1][0] + c + b[i], dp[i - 1][1] + b[i]);
    ans[i] = std::min(dp[i][0], dp[i][1]);
  }
  for (auto &v : ans) std::cout << v << ' ';
  std::cout << '\n';
  return 0;
}
