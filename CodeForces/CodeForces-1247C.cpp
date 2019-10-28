// Author: Tony5t4rk Time: 2019-10-28 12:50:50 
#include <bits/stdc++.h>
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int n, p;
  std::cin >> n >> p;
  for (int cnt = 1; cnt * p <= n; ++cnt) {
    int x = n - cnt * p;
    if (cnt >= __builtin_popcount(x) && cnt <= x) {
      std::cout << cnt << '\n';
      return 0;
    }
  }
  std::cout << -1 << '\n';
  return 0;
}
