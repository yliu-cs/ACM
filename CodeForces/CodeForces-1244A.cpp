// Author: Tony5t4rk Time: 2019-10-13 17:07:20 
#include <bits/stdc++.h>
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int t;
  std::cin >> t;
  while (t--) {
    int a, b, c, d, k;
    std::cin >> a >> b >> c >> d >> k;
    int cnt = (a + c - 1) / c + (b + d - 1) / d;
    if (cnt > k) std::cout << -1 << '\n';
    else std::cout << (a + c - 1) / c << ' ' << (b + d - 1) / d << '\n';
  }
  return 0;
}
