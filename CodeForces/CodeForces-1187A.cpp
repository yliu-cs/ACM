#include <bits/stdc++.h>

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int _;
  std::cin >> _;
  while (_--) {
    int n, s, t;
    std::cin >> n >> s >> t;
    int both = s + t - n;
    if (s > t) {
      std::swap(s, t);
    }
    std::cout << t - both + 1 << '\n';
  }
  return 0;
}

