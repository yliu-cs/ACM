#include <bits/stdc++.h>

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0); std::cout.tie(0);

  freopen("hello.in", "r", stdin);

  int t; std::cin >> t;
  for (int cas = 1; cas <= t; ++cas) {
    std::vector<int> d(12);
    std::cin >> d[0];
    bool flag = true; int max = d[0];
    for (int i = 1; i < 4; ++i) {
      std::cin >> d[i];
      if (d[i] <= d[i - 1]) flag = false;
      max = std::max(max, d[i]);
    }
    for (int i = 4; i < 12; ++i) {
      std::cin >> d[i];
      if (d[i] <= max) flag = false;
    }
    if (flag) std::cout << "yes" << '\n';
    else std::cout << "no" << '\n';
  }
  return 0;
}
