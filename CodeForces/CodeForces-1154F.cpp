#include <bits/stdc++.h>

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr); std::cout.tie(nullptr);

  int n, m, k; std::cin >> n >> m >> k;
  std::vector<int> arr(n + 1, 0), pref(n + 1, 0);
  for (int i = 1; i <= n; ++i) std::cin >> arr[i];
  std::sort(arr.begin(), arr.end());
  for (int i = 1; i <= n; ++i) pref[i] = pref[i - 1] + arr[i];
  std::map<int, int> mp;
  for (int i = 1, a, b; i <= m; ++i) {
    std::cin >> a >> b;
    if (a <= k) mp[a] = std::max(mp[a], b);
  }

  std::vector<int> dp(k + 1);
  for (int i = 1; i <= k; ++i) {
    dp[i] = pref[i];
    for (int j = 0; j < i; ++j) {
      dp[i] = std::min(dp[i], dp[j] + pref[i] - pref[j + mp[i - j]]);
    }
  }
  
  std::cout << dp[k] << '\n';
  return 0;
}

