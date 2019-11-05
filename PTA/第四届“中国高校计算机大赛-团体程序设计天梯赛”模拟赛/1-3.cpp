#include <bits/stdc++.h>

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0); std::cout.tie(0);

  int d; std::cin >> d;
  --d;
  std::cout << (d + 2) % 7 + 1 << '\n';
  return 0;
}
