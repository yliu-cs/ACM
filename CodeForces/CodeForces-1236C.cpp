// Author: Tony5t4rk Time: 2019-10-17 22:00:37 
#include <bits/stdc++.h>
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int n;
  std::cin >> n;
  std::vector<std::vector<int>> ans(n, std::vector<int>(n, 0));
  int cur = 0;
  for (int j = 0; j < n; ++j) {
    if (j & 1) {
      for (int i = n - 1; i >= 0; --i) ans[i][j] = ++cur;
    }
    else {
      for (int i = 0; i < n; ++i) ans[i][j] = ++cur;
    }
  }
  for (auto &group : ans) {
    for (auto &v : group) std::cout << v << ' ';
    std::cout << '\n';
  }
  return 0;
}
