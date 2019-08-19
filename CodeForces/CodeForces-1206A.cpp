// Author: Tony5t4rk Time: 2019-08-18 21:46:02 
#include <bits/stdc++.h>
int main() {
  int n;
  std::cin >> n;
  std::set<int> a;
  for (int i = 1, x; i <= n; ++i) {
    std::cin >> x;
    a.insert(x);
  }
  int m;
  std::cin >> m;
  std::set<int> b;
  for (int i = 1, x; i <= m; ++i) {
    std::cin >> x;
    b.insert(x);
  }
  for (auto &i : a) {
    for (auto &j : b) {
      if (a.find(i + j) == a.end() && b.find(i + j) == b.end()) {
        std::cout << i << ' ' << j << '\n';
        return 0;
      }
    }
  }
  return 0;
}
