#include <bits/stdc++.h>

int main () {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int t;
  std::cin >> t;
  while (t--) {
    int a, b;
    std::cin >> a >> b;
    if (std::__gcd(a, b) == 1) {
      std::cout << "Finite" << '\n';
    }
    else {
      std::cout << "Infinite" << '\n';
    }
  }
  return 0;
}

