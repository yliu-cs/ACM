#include <bits/stdc++.h>
int main() {
  int t;
  std::cin >> t;
  while (t--) {
    long long n;
    std::cin >> n;
    if (n % 2 == 0) {
      if (((n / 2) - 1) % 3 == 1) std::cout << n - 1 << '\n';
      else std::cout << n / 2 << '\n';
    }
    else {
      if (((n + 1) / 2 - 1) % 3 == 0) std::cout << n - ((((n + 1) / 2) - 1) / 3) * 2ll << '\n';
      else std::cout << (((n + 1) / 2) - 1) / 3 << '\n';
    }
  }
  return 0;
}
