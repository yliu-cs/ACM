// Author: Tony5t4rk Time: 2019-10-03 14:45:18 
#include <bits/stdc++.h>
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int n;
  std::cin >> n;
  long long pref = 0, ans = 0;
  for (int i = 0, x; i < n; ++i) {
    std::cin >> x;
    if (!pref) {
      ans += x / 3;
      pref += x % 3;
    }
    else {
      long long last = x / 2;
      if (last >= pref) {
        ans += pref;
        x -= pref * 2;
        ans += x / 3;
        pref = x % 3;
      }
      else {
        ans += last;
        pref = pref - last + x % 2;
      }
    }
  }
  std::cout << ans << '\n';
  return 0;
}
