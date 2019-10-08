// Author: Tony5t4rk Time: 2019-10-06 23:06:19 
#include <bits/stdc++.h>
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int t;
  std::cin >> t;
  while (t--) {
    int n;
    std::cin >> n;
    if (n & 1) std::cout << 1 << '\n';
    else {
      if (n == 2) std::cout << 2 << '\n';
      else std::cout << 0 << '\n';
    }
  }
  return 0;
}
