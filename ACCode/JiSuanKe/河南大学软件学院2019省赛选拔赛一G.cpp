#include <bits/stdc++.h>

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr); std::cout.tie(nullptr);

  long long a, b, x, y;
  std::cin >> a >> b >> x >> y;
  a = 1ll * a * 5; b = 1ll * b * 5;
  long long v1 = a * x, v2 = b * y;
  if (v1 > v2) std::cout << "First" << '\n';
  else if (v1 < v2) std::cout << "Second" << '\n';
  else if (a == b) std::cout << "Oh my ga" << '\n';
  else std::cout << "Same" << '\n';
  return 0;
}
