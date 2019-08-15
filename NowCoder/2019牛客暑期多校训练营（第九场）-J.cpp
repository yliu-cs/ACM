#include <bits/stdc++.h>
int main() {
  int n;
  std::cin >> n;
  std::vector<std::pair<int, int> > vec;
  for (int i = 1, l, r; i <= n; ++i) {
    std::cin >> l >> r;
    vec.push_back({l + l, 1});
    vec.push_back({l + r, -2});
    vec.push_back({r + r, 1});
  }
  std::sort(vec.begin(), vec.end());
  int last = 0, cnt = 0;
  long long sum = 0, ans = 0;
  for (auto &v : vec) {
    sum += 1ll * cnt * (v.first - last);
    ans = std::max(ans, sum);
    last = v.first;
    cnt += v.second;
  }
  std::cout << ans << '\n';
  return 0;
}
