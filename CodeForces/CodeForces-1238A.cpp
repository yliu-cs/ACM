#include <bits/stdc++.h>
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int t;
  std::cin >> t;
  while (t--) {
    long long x, y;
    std::cin >> x >> y;
    long long diff = x - y;
    if (diff <= 1) std::cout << "NO" << '\n';
    else std::cout << "YES" << '\n';
  }
  return 0;
}
