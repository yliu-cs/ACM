// Author: Tony5t4rk Time: 2019-10-13 23:06:42 
#include <bits/stdc++.h>
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  long long n, p, w, d;
  std::cin >> n >> p >> w >> d;
  long long y = 0;
  while (y < w && (p - d * y) % w != 0) ++y;
  if (y < w) {
    long long x = (p - d * y) / w, z = n - x - y;
    if (x >= 0 && z >= 0) std::cout << x << ' ' << y << ' ' << n - x - y << '\n';
    else std::cout << -1 << '\n';
  }
  else std::cout << -1 << '\n';
  return 0;
}
