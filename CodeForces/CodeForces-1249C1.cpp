// Author: Tony5t4rk Time: 2019-10-23 13:52:45 
#include <bits/stdc++.h>
const long long INF = 2e18 + 5;
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int t;
  std::cin >> t;
  while (t--) {
    long long n;
    std::cin >> n;
    std::vector<long long> vec;
    for (long long i = 0, base = 1, sum = 0; ; ++i) {
      vec.push_back(base);
      sum += base;
      if (sum > n) break;
      base *= 3ll;
    }
    std::set<long long> pre;
    auto Dfs = [&](auto &self, int r, int idx, long long sum) {
      if (idx == r) {
        if (sum) pre.insert(sum);
        return;
      }
      self(self, r, idx + 1, sum);
      self(self, r, idx + 1, sum + vec[idx]);
    };
    Dfs(Dfs, vec.size() / 2, 0, 0);
    long long ans = INF;
    auto Solve = [&](auto &self, int idx, long long sum) {
      if (idx == vec.size()) {
        if (sum >= n) ans = std::min(ans, sum);
        else {
          auto it = pre.lower_bound(n - sum);
          if (it != pre.end()) ans = std::min(ans, (*it) + sum);
        }
        return;
      }
      self(self, idx + 1, sum);
      self(self, idx + 1, sum + vec[idx]);
    };
    Solve(Solve, vec.size() / 2, 0);
    std::cout << ans << '\n';
  }
  return 0;
}
