// Author: Tony5t4rk Time: 2019-09-29 21:05:58 
#include <bits/stdc++.h>
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.setf(std::ios::fixed);
  std::cout.precision(15);
  int l, r;
  std::cin >> l >> r;
  auto Check = [](int x) {
    std::set<int> set;
    while (x) {
      if (set.find(x % 10) != set.end()) return false;
      set.insert(x % 10);
      x /= 10;
    }
    return true;
  };
  for (int i = l; i <= r; ++i) {
    if (Check(i)) {
      std::cout << i << '\n';
      return 0;
    }
  }
  std::cout << -1 << '\n';
  return 0;
}
