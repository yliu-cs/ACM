// Author: Tony5t4rk Time: 2019-10-02 14:57:13 
#include <bits/stdc++.h>
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int t;
  std::cin >> t;
  for (int cas = 1; cas <= t; ++cas) {
    int n;
    std::cin >> n;
    while (n % 2 == 0) n /= 2;
    while (n % 5 == 0) n /= 5;
    if (n != 1) std::cout << "Yes" << '\n';
    else std::cout << "No" << '\n';
  }
  return 0;
}
