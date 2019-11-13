#include <bits/stdc++.h>

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int t;
  std::cin >> t;
  while (t--) {
    int n, x, a, b;
    std::cin >> n >> x >> a >> b;
    std::cout << std::abs(b - a) + std::min(std::min(a, b) - 1 + n - std::max(a, b), x) << '\n';
  }
  return 0;
}

