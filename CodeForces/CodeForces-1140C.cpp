#include <bits/stdc++.h>

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0); std::cout.tie(0);

  int n, k; std::cin >> n >> k;
  std::vector<std::pair<long long, long long>> s(n);
  for (auto &it : s) std::cin >> it.first >> it.second;
  sort(s.begin(), s.end(), [&](std::pair<long long, long long> k1, std::pair<long long, long long> k2) {
    return k1.second > k2.second;
  });

  long long sum = 0, ans = 0;
  std::priority_queue<long long, std::vector<long long>, std::greater<long long> > que;
  for (int i = 0; i < n; ++i) {
    que.push(s[i].first);
    sum += s[i].first;
    if (i >= k) {
      long long cur = que.top(); que.pop();
      sum -= cur;
    }
    ans = std::max(ans, sum * s[i].second);
  }

  std::cout << ans << '\n';
  return 0;
}
