// Author: Tony5t4rk Time: 2019-10-23 13:31:02 
#include <bits/stdc++.h>
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int t;
  std::cin >> t;
  while (t--) {
    int n;
    std::cin >> n;
    std::vector<int> a(n);
    for (auto &v : a) std::cin >> v;
    std::sort(a.begin(), a.end());
    int ans = 1;
    for (int i = 1; i < n; ++i) {
      if (a[i] == a[i - 1] + 1) {
        ans = 2;
        break;
      }
    }
    std::cout << ans << '\n';
  }
  return 0;
}
