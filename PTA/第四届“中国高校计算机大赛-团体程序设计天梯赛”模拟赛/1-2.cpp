#include <bits/stdc++.h>

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0); std::cout.tie(0);

  int h, m; char c; std::cin >> h >> c >> m;
  if (h >= 0 && h <= 12) {
    std::cout << "Only ";
    if (h < 10) std::cout << 0;
    std::cout << h << ":";
    if (m < 10) std::cout << 0;
    std::cout << m << ".  Too early to Dang.";
    return 0;
  }
  h -= 12;
  for (int i = 0; i < h; ++i) std::cout << "Dang";
  if (m != 0) std::cout << "Dang";
  return 0;
}
