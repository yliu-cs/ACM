// Author: Tony5t4rk Time: 2019-10-23 12:28:42 
#include <bits/stdc++.h>
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int n;
  std::cin >> n;
  std::vector<std::pair<int, int>> s(n);
  for (int i = 0; i < n; ++i) {
    std::cin >> s[i].first;
    s[i].second = i + 1;
  }
  std::sort(s.begin(), s.end());
  std::vector<int> t(n);
  for (int i = 0; i < n; ++i) std::cin >> t[i];
  std::sort(t.begin(), t.end());
  int sum = 0;
  for (int i = 0; i < n; ++i) {
    s[i].first -= t[i];
    sum += s[i].first;
  }
  if (sum != 0) {
    std::cout << "NO" << '\n';
    return 0;
  }
  std::vector<std::tuple<int, int, int>> ans;
  int l = 0, r = 0;
  while (true) {
    while (s[l].first >= 0 && l < n) ++l;
    while (s[r].first <= 0 && r < n) ++r;
    if (l == r) break;
    if (l > r) {
      std::cout << "NO" << '\n';
      return 0;
    }
    int d = std::min(-s[l].first, s[r].first);
    ans.push_back({s[l].second, s[r].second, d});
    s[l].first += d;
    s[r].first -= d;
  }
  std::cout << "YES" << '\n';
  std::cout << ans.size() << '\n';
  for (auto &v : ans) std::cout << std::get<0>(v) << ' ' << std::get<1>(v) << ' ' << std::get<2>(v) << '\n';
  return 0;
}
