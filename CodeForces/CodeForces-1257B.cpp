#include <bits/stdc++.h>

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int t;
  std::cin >> t;
  while (t--) {
    long long x, y;
    std::cin >> x >> y;
    if (x == 1 || x == 3) {
      if (x < y) {
        std::cout << "NO" << '\n';
      }
      else {
        std::cout << "YES" << '\n';
      }
    }
    else if (x == 2) {
      if (y <= 3) {
        std::cout << "YES" << '\n';
      }
      else {
        std::cout << "NO" << '\n';
      }
    }
    else {
      std::cout << "YES" << '\n';
    }
  }
  return 0;
}

