#include <bits/stdc++.h>
typedef long long ll;

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr); std::cout.tie(nullptr);

  ll n, x; std::cin >> n >> x;
  std::vector<ll> a(n + 1);
  for (int i = 1; i <= n; ++i) std::cin >> a[i];

  std::vector<std::vector<ll>> dp(n + 1, std::vector<ll>(2, 0));
  std::vector<ll> suf_dp(n + 1, 0);
  int s1 = 0, s2 = 0;

  suf_dp[n] = a[n];
  for (int i = n - 1; i >= 1; --i) {
    if (suf_dp[i + 1] >= 0) suf_dp[i] = suf_dp[i + 1] + a[i];
    else suf_dp[i] = a[i];
  }

  ll ans = 0;
  for (int i = 1; i <= n; ++i) {
    if (dp[i - 1][0] >= 0) dp[i][0] = dp[i - 1][0] + a[i];
    else dp[i][0] = a[i];
    if (dp[i - 1][1] >= 0) dp[i][1] = dp[i - 1][1] + a[i] * x;
    else dp[i][1] = a[i] * x;
    ans = std::max(ans, dp[i][0]);
    ans = std::max(ans, dp[i][0] + dp[s2][1]);
    ans = std::max(ans, dp[i][1]);
    ans = std::max(ans, dp[i][1] + dp[s1][0]);
    if (i + 1 <= n) ans = std::max(ans, dp[i][1] + dp[s1][0] + suf_dp[i + 1]);
    if (dp[i][0] < 0) s2 = i; if (dp[i][1] < 0) s1 = i;
  }
  
  std::cout << ans << '\n';
  return 0;
}

