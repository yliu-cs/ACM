// Author: Tony5t4rk Time: 2019-08-18 21:50:20 
#include <bits/stdc++.h>
int main() {
  int n;
  std::cin >> n;
  std::vector<long long> a[2];
  for (int i = 1; i <= n; ++i) {
    long long x;
    std::cin >> x;
    a[(x > -1)].push_back(x);
  }
  std::sort(a[0].begin(), a[0].end());
  std::sort(a[1].begin(), a[1].end());
  long long ans = 0;
  if (!a[0].empty() && !a[1].empty() && a[0].size() % 2 == 0) {
    for (long long &v : a[0]) ans += std::abs(v + 1);
    for (long long &v : a[1]) ans += std::abs(v - 1);
  }
  else if (a[0].empty()) {
    for (long long &v : a[1]) ans += std::abs(v - 1);
  }
  else if (a[1].empty()) {
    if (a[0].size() % 2 == 0) {
      for (int i = 0; i < a[0].size(); ++i) ans += std::abs(a[0][i] + 1);
    }
    else {
      for (int i = 0; i < a[0].size() - 1; ++i) ans += std::abs(a[0][i] + 1);
      ans += std::abs(a[0].back() - 1);
    }
  }
  else {
    for (int i = 0; i < a[0].size() - 1; ++i) ans += std::abs(a[0][i] + 1);
    for (int i = 1; i < a[1].size(); ++i) ans += std::abs(a[1][i] - 1);
    ans += std::min(std::abs(a[0].back() + 1) + std::abs(a[1][0] + 1), std::abs(a[0].back() - 1) + std::abs(a[1][0] - 1));
  }
  std::cout << ans << '\n';
  return 0;
}
