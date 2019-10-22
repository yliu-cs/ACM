// Author: Tony5t4rk Time: 2019-10-22 15:55:32 
#include <bits/stdc++.h>
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  long long n, m, ta, tb, k;
  std::cin >> n >> m >> ta >> tb >> k;
  if (k >= n || k >= m) {
    std::cout << -1 << '\n';
    return 0;
  }
  std::vector<int> a(n);
  for (auto &v : a) std::cin >> v;
  std::vector<int> b(m);
  for (auto &v : b) std::cin >> v;
  long long ans = 0;
  for (int i = 0; i <= k; ++i) {
    int idx = std::lower_bound(b.begin(), b.end(), a[i] + ta) - b.begin();
    if (idx + k - i >= m) {
      std::cout << -1 << '\n';
      return 0;
    }
    ans = std::max(ans, b[idx + k - i] + tb);
  }
  std::cout << ans << '\n';
  return 0;
}
