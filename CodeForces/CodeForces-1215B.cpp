// Author: Tony5t4rk Time: 2019-10-21 19:28:16 
#include <bits/stdc++.h>
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int n;
  std::cin >> n;
  int cnt[2] = {0, 1};
  int f = 1;
  long long ans[2] = {0, 0};
  for (int i = 1, x; i <= n; ++i) {
    std::cin >> x;
    if (x < 0) f *= -1;
    if (f == 1) {
      ans[0] += cnt[0];
      ans[1] += cnt[1];
      ++cnt[1];
    }
    else {
      ans[0] += cnt[1];
      ans[1] += cnt[0];
      ++cnt[0];
    }
  }
  std::cout << ans[0] << ' ' << ans[1] << '\n';
  return 0;
}
