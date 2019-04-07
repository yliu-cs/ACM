#include <bits/stdc++.h>

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr); std::cout.tie(nullptr);

  int w, h, x1, y1, x2, y2;
  while (std::cin >> w >> h >> x1 >> y1 >> x2 >> y2) {
    if (x1 == x2) std::cout << 0 << ' ' << y1 << ' ' << w << ' ' << y2 << '\n';
    else std::cout << x1 << ' ' << 0 << ' ' << x2 << ' ' << h << '\n';
  }
  return 0;
}
