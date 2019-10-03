// Author: Tony5t4rk Time: 2019-10-03 13:28:06 
#include <bits/stdc++.h>
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int n, h;
  std::cin >> n >> h;
  std::vector<int> a(n);
  for (auto &v : a) std::cin >> v;
  int l = 1, r = n, ans;
  while (l <= r) {
    int m = (l + r) / 2;
    std::vector<int> b(a.begin(), a.end());
    std::sort(b.begin(), b.begin() + m);
    std::reverse(b.begin(), b.begin() + m);
    int last = h;
    bool flag = true;
    for (int i = 0; i < m; i += 2) {
      if (last < b[i]) {
        flag = false;
        break;
      }
      last -= b[i];
    }
    if (flag) {
      l = m + 1;
      ans = m;
    }
    else r = m - 1;
  }
  std::cout << ans << '\n';
  return 0;
}
