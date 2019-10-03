// Author: Tony5t4rk Time: 2019-10-03 13:22:20 
#include <bits/stdc++.h>
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int n;
  std::cin >> n;
  std::vector<int> c(n);
  for (auto &v : c) std::cin >> v;
  int ans = 0;
  for (int i = n - 1; i >= 0; --i) {
    if (c[i] != c[0]) {
      ans = std::max(ans, i);
      break;
    }
  }
  for (int i = 0; i < n; ++i) {
    if (c[i] != c.back()) {
      ans = std::max(ans, n - i - 1);
      break;
    }
  }
  std::cout << ans << '\n';
  return 0;
}
