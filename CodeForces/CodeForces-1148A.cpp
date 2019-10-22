// Author: Tony5t4rk Time: 2019-10-22 15:51:07 
#include <bits/stdc++.h>
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  long long a, b, c;
  std::cin >> a >> b >> c;
  std::cout << std::min(a, b) * 2 + c * 2 + std::min(1ll, std::max(a, b) - std::min(a, b)) << '\n';
  return 0;
}
