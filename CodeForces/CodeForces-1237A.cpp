// Author: Tony5t4rk Time: 2019-10-16 22:36:00 
#include <bits/stdc++.h>
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int n;
  std::cin >> n;
  int f = 0;
  for (int i = 0, x; i < n; ++i) {
    std::cin >> x;
    if (x % 2 == 0) std::cout << x / 2 << '\n';
    else if (f == 0) {
      if (x > 0) {
        std::cout << x / 2 << '\n';
        f = 1;
      }
      else {
        std::cout << x / 2 << '\n';
        f = -1;
      }
    }
    else {
      if (x > 0) {
        if (f == 1) std::cout << (x + 1) / 2 << '\n';
        else std::cout << x / 2 << '\n';
      }
      else {
        if (f == 1) std::cout << x / 2 << '\n';
        else std::cout << (x - 1) / 2 << '\n';
      }
      f = 0;
    }
  }
  return 0;
}
