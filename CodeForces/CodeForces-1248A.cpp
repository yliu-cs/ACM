// Author: Tony5t4rk Time: 2019-10-20 17:07:06 
#include <bits/stdc++.h>
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int t;
  std::cin >> t;
  while (t--) {
    int n;
    std::cin >> n;
    int pcnt[2] = {0, 0};
    for (int i = 0, x; i < n; ++i) {
      std::cin >> x;
      ++pcnt[x & 1];
    }
    int m;
    std::cin >> m;
    int qcnt[2] = {0, 0};
    for (int i = 0, x; i < m; ++i) {
      std::cin >> x;
      ++qcnt[x & 1];
    }
    std::cout << 1ll * pcnt[0] * qcnt[0] + 1ll * pcnt[1] * qcnt[1] << '\n';
  }
  return 0;
}
