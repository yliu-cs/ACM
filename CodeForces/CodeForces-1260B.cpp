#include <bits/stdc++.h>

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int t;
  std::cin >> t;
  while (t--) {
    int a, b;
    std::cin >> a >> b;
    int diff = std::abs(a - b);
    if (diff == 0) {
      if (a % 3 == 0) {
        std::cout << "YES" << '\n';
      }
      else {
        std::cout << "NO" << '\n';
      }
    }
    else {
      int x = std::min(a, b) - diff, y = std::max(a, b) - 2 * diff;
      if (x < 0 || y < 0) {
        std::cout << "NO" << '\n';
      }
      else if (x % 3 == 0 && y % 3 == 0) {
        std::cout << "YES" << '\n';
      }
      else {
        std::cout << "NO" << '\n';
      }
    }
  }
  return 0;
}

