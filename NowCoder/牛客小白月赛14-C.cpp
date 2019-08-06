#include <bits/stdc++.h>

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr); std::cout.tie(nullptr);

  int n; std::cin >> n;

  if (n & 1) std::cout << 1 << '\n';
  else std::cout << 2 << '\n';

  return 0;
}

