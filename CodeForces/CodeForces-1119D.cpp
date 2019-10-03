// Author: Tony5t4rk Time: 2019-10-03 14:00:25 
#include <bits/stdc++.h>
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int n; std::cin >> n;
  std::vector<long long> s(n);
  for (auto &v : s) std::cin >> v;
  std::sort(s.begin(), s.end());
  s.erase(std::unique(s.begin(), s.end()), s.end());
  std::vector<long long> diff;
  for (int i = 1; i < (int)s.size(); ++i) diff.push_back(s[i] - s[i - 1]);
  std::sort(diff.begin(), diff.end());
  std::vector<long long> pref(diff.size());
  if (!pref.empty()) pref[0] = diff[0];
  for (int i = 1; i < (int)pref.size(); ++i) pref[i] = pref[i - 1] + diff[i];
  int m; std::cin >> m;
  for (int i = 0; i < m; ++i) {
    long long l, r;
    std::cin >> l >> r;
    long long len = r - l + 1, ans = len * (long long)s.size();
    int idx = std::lower_bound(diff.begin(), diff.end(), len) - diff.begin();
    if (idx == 0) {
      std::cout << ans << ' ';
      continue;
    }
    --idx;
    ans -= len * (idx + 1) - pref[idx];
    std::cout << ans << ' ';
  }
  return 0;
}
