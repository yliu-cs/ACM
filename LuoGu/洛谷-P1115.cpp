#include <bits/stdc++.h>
const int maxn = 2e5 + 5;
const long long inf = 1e10 + 5;

int n;
long long arr[maxn];
long long dp[maxn];
long long ans;

int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i) scanf("%lld", &arr[i]);
  dp[1] = arr[1];
  ans = -inf;
  for (int i = 2; i <= n; ++i) {
    dp[i] = std::max(dp[i - 1] + arr[i], arr[i]);
    ans = std::max(ans, dp[i]);
  }
  printf("%lld\n", ans);
  return 0;
}