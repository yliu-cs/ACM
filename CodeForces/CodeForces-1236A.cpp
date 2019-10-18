// Author: Tony5t4rk Time: 2019-10-17 21:36:10 
#include <bits/stdc++.h>
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int t;
  std::cin >> t;
  while (t--) {
    int a, b, c;
    std::cin >> a >> b >> c;
    int ans = 0;
    for (int i = 0; i <= std::min(a, b / 2); ++i) {
      for (int j = 0; j <= std::min(b - i * 2, c / 2); ++j) {
        if (i > a) continue;
        if (2 * i + j > b) continue;
        if (2 * j > c) continue;
        ans = std::max(ans, 3 * i + 3 * j);
      }
    }
    std::cout << ans << '\n';
  }
  return 0;
}
