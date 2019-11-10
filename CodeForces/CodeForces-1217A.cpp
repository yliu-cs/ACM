#include <bits/stdc++.h>

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int t;
  std::cin >> t;
  while (t--) {
    int a, b, c;
    std::cin >> a >> b >> c;
    if (a + c <= b) {
      std::cout << 0 << '\n';
      continue;
    }
    int min = std::max(0, (b + c - a + 2) / 2);
    std::cout << std::max(0, c - min + 1) << '\n';
  }
  return 0;
}

