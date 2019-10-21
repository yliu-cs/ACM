// Author: Tony5t4rk Time: 2019-10-21 19:16:04 
#include <bits/stdc++.h>
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int a1, a2, k1, k2, n;
  std::cin >> a1 >> a2 >> k1 >> k2 >> n;
  if (k1 > k2) {
    std::swap(a1, a2);
    std::swap(k1, k2);
  }
  int la = n - a1 * (k1 - 1) - a2 * (k2 - 1), min = 0, max = 0;
  if (la > 0) min = std::min(a1 + a2, la);
  if (k1 * a1 >= n) max = n / k1;
  else max = a1 + std::min(a2, (n - k1 * a1) / k2);
  std::cout << min << ' ' << max << '\n';
  return 0;
}
