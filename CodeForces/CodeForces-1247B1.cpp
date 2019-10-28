// Author: Tony5t4rk Time: 2019-10-28 12:38:39 
#include <bits/stdc++.h>
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int t;
  std::cin >> t;
  while (t--) {
    int n, k, d;
    std::cin >> n >> k >> d;
    std::vector<int> a(n);
    for (auto &v : a) std::cin >> v;
    std::vector<int> lst(k + 1, -1);
    std::set<int> set;
    int ans = k;
    for (int l = 0, r = -1; l + d - 1 < n; ++l) {
      while (r < l + d - 1) {
        ++r;
        set.insert(a[r]);
        lst[a[r]] = r;
      }
      ans = std::min(ans, (int)set.size());
      if (lst[a[l]] == l) {
        lst[a[l]] = -1;
        set.erase(a[l]);
      }
    }
    std::cout << ans << '\n';
  }
  return 0;
}
