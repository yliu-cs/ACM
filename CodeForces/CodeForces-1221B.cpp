#include <bits/stdc++.h>

int n;

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cin >> n;
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= n; ++j) {
      if (((i & 1) && (j & 1)) || ((i % 2 == 0) && j % 2 == 0)) {
        std::cout << 'W';
      }
      else {
        std::cout << 'B';
      }
    }
    std::cout << '\n';
  }
  return 0;
}

