#include <bits/stdc++.h>

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int t;
  std::cin >> t;
  while (t--) {
    int c, sum;
    std::cin >> c >> sum;
    if (sum < c) {
      std::cout << sum << '\n';
      continue;
    }
    int x = sum / c;
    int lst = sum - x * c;
    long long ans = 0;
    for (int i = 0; i < c; ++i) {
      if (lst) {
        ans += (x + 1) * (x + 1);
        --lst;
        continue;
      }
      ans += x * x;
    }
    std::cout << ans << '\n';
  }
  return 0;
}

