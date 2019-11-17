#include <bits/stdc++.h>

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.setf(std::ios::fixed);
  std::cout.precision(13);
  double h, l;
  std::cin >> h >> l;
  std::cout << (l * l - h * h) / (2. * h) << '\n';
  return 0;
}

