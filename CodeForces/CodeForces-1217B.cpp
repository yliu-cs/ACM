#include <bits/stdc++.h>

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int t;
  std::cin >> t;
  while (t--) {
    int n, x;
    std::cin >> n >> x;
    std::vector<int> diff(n), d(n), h(n);
    for (int i = 0; i < n; ++i) {
      std::cin >> d[i] >> h[i];
      diff[i] = d[i] - h[i];
    }
    std::sort(d.begin(), d.end());
    std::reverse(d.begin(), d.end());
    std::sort(diff.begin(), diff.end());
    std::reverse(diff.begin(), diff.end());
    int ans = 1;
    x -= d[0];
    if (x > 0) {
      if (diff[0] <= 0) {
        std::cout << -1 << '\n';
        continue;
      }
      ans += (x + diff[0] - 1) / diff[0];
    }
    std::cout << ans << '\n';
  }
  return 0;
}

