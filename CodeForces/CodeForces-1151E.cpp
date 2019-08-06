#include <bits/stdc++.h>

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr); std::cout.tie(nullptr);

  int n; std::cin >> n;
  std::vector<long long> arr(n + 2, 0);
  for (int i = 1; i <= n; ++i) std::cin >> arr[i];

  long long ans = 0;
  for (int i = 1; i <= n + 1; ++i) {
    if (arr[i - 1] < arr[i]) ans += (arr[i] - arr[i - 1]) * (n - arr[i] + 1);
    else ans += (arr[i - 1] - arr[i]) * arr[i];
  }

  std::cout << ans << '\n';
  return 0;
}

