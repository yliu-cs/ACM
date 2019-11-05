#include <bits/stdc++.h>
typedef long long ll;

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr); std::cout.tie(nullptr);

  ll n, x; std::cin >> n >> x;
  std::vector<ll> arr(n + 1);
  for (int i = 1; i <= n; ++i) std::cin >> arr[i];

  std::vector<std::vector<ll>> dp(n + 1, std::vector<ll>(3, 0));
  ll ans = 0;
  for (int i = 1; i <= n; ++i) {
    dp[i][0] = std::max(arr[i], dp[i - 1][0] + arr[i]);
    dp[i][1] = std::max(arr[i] * x, std::max(dp[i - 1][1] + arr[i] * x, dp[i - 1][0] + arr[i] * x));
    dp[i][2] = std::max(arr[i], std::max(dp[i - 1][1] + arr[i], dp[i - 1][2] + arr[i]));
    ans = std::max(ans, std::max(dp[i][0], std::max(dp[i][1], dp[i][2])));
  }

  std::cout << ans << '\n';
  return 0;
}

