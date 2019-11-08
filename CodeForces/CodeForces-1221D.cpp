#include <bits/stdc++.h>

const int N = 3e5 + 5;

int t, n, a[N], b[N];
long long dp[N][3];

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cin >> t;
  while (t--) {
    std::cin >> n;
    for (int i = 1; i <= n; ++i) {
      std::cin >> a[i] >> b[i];
    }
    for (int i = 1; i <= n; ++i) {
      if (a[i] == a[i - 1]) {
        dp[i][0] = std::min(dp[i - 1][1], dp[i - 1][2]);
        dp[i][1] = std::min(dp[i - 1][0], dp[i - 1][2]) + b[i];
        dp[i][2] = std::min(dp[i - 1][0], dp[i - 1][1]) + 2ll * b[i];
      }
      else if (a[i] == a[i - 1] + 1) {
        dp[i][0] = std::min(dp[i - 1][0], dp[i - 1][2]);
        dp[i][1] = std::min(dp[i - 1][0], dp[i - 1][1]) + b[i];
        dp[i][2] = std::min({dp[i - 1][0], dp[i - 1][1], dp[i - 1][2]}) + 2ll * b[i];
      }
      else if (a[i] == a[i - 1] - 1) {
        dp[i][0] = std::min({dp[i - 1][0], dp[i - 1][1], dp[i - 1][2]});
        dp[i][1] = std::min(dp[i - 1][1], dp[i - 1][2]) + b[i];
        dp[i][2] = std::min(dp[i - 1][0], dp[i - 1][2]) + 2ll * b[i];
      }
      else if (a[i] == a[i - 1] + 2) {
        dp[i][0] = std::min(dp[i - 1][0], dp[i - 1][1]);
        dp[i][1] = std::min({dp[i - 1][0], dp[i - 1][1], dp[i - 1][2]}) + b[i];
        dp[i][2] = std::min({dp[i - 1][0], dp[i - 1][1], dp[i - 1][2]}) + 2ll * b[i];
      }
      else if (a[i] == a[i - 1] - 2) {
        dp[i][0] = std::min({dp[i - 1][0], dp[i - 1][1], dp[i - 1][2]});
        dp[i][1] = std::min({dp[i - 1][0], dp[i - 1][1], dp[i - 1][2]}) + b[i];
        dp[i][2] = std::min(dp[i - 1][1], dp[i - 1][2]) + 2ll * b[i];
      }
      else {
        dp[i][0] = std::min({dp[i - 1][0], dp[i - 1][1], dp[i - 1][2]});
        dp[i][1] = std::min({dp[i - 1][0], dp[i - 1][1], dp[i - 1][2]}) + b[i];
        dp[i][2] = std::min({dp[i - 1][0], dp[i - 1][1], dp[i - 1][2]}) + 2ll * b[i];
      }
    }
    std::cout << std::min({dp[n][0], dp[n][1], dp[n][2]}) << '\n';
  }
  return 0;
}

