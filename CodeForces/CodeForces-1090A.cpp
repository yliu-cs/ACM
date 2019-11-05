#include <bits/stdc++.h>

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr); std::cout.tie(nullptr);

  int n; std::cin >> n;
  std::vector<int> arr(n), cnt(n);
  int tar = 0;
  for (int i = 0, k; i < n; ++i) {
    std::cin >> k;
    cnt[i] = k;
    int max = 0;
    for (int i = 0, x; i < k; ++i) {
      std::cin >> x;
      max = std::max(max, x);
    }
    tar = std::max(tar, max);
    arr[i] = max;
  }

  long long ans = 0;
  for (int i = 0; i < n; ++i) ans += 1ll * (tar - arr[i]) * cnt[i];

  std::cout << ans << '\n';
  return 0;
}

