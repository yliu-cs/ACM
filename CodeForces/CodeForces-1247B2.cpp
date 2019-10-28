// Author: Tony5t4rk Time: 2019-10-28 12:38:39 
#include <bits/stdc++.h>
const int N = 2e5 + 5;
const int K = 1e6 + 5;
int t, n, k, d, ans;
int a[N], lst[K];
int main() {
  scanf("%d", &t);
  while (t--) {
    scanf("%d%d%d", &n, &k, &d);
    ans = k;
    for (int i = 1; i <= n; ++i) scanf("%d", &a[i]);
    std::set<int> set;
    for (int l = 1, r = 0; l + d - 1 <= n; ++l) {
      while (r < l + d - 1) {
        ++r;
        set.insert(a[r]);
        lst[a[r]] = r;
      }
      ans = std::min(ans, (int)set.size());
      if (lst[a[l]] == l) set.erase(a[l]);
    }
    printf("%d\n", ans);
  }
  return 0;
}
