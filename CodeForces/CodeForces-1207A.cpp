#include <bits/stdc++.h>

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int t;
  std::cin >> t;
  while (t--) {
    int b, p, f;
    std::cin >> b >> p >> f;
    int h, c;
    std::cin >> h >> c;
    int ham = 0, bur = 0;
    if (h > c) {
      ham = std::min(b / 2, p);
      b -= 2 * ham;
      p -= ham;
      bur = std::min(b / 2, f);
      b -= 2 * bur;
      f -= bur;
    }
    else {
      bur = std::min(b / 2, f);
      b -= 2 * bur;
      f -= bur;
      ham = std::min(b / 2, p);
      b -= 2 * ham;
      p -= ham;
    }
    std::cout << ham * h + bur * c << '\n';
  }
  return 0;
}

