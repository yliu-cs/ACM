// Author: Tony5t4rk Time: 2019-10-28 12:36:13 
#include <bits/stdc++.h>
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int a, b;
  std::cin >> a >> b;
  if (a == 9 && b == 1) std::cout << a << ' ' << b << 0 << '\n';
  else if (a + 1 == b) std::cout << a << ' ' << b << '\n';
  else if (a == b) std::cout << a << 1 << ' ' << b << 2 << '\n';
  else std::cout << -1 << '\n';
  return 0;
}
