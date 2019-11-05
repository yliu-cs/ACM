#include <bits/stdc++.h>

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0); std::cout.tie(0);

  int n; std::cin >> n;
  std::vector<int> even, odd;
  for (int i = 0, x; i < n; ++i) {
    std::cin >> x;
    if (x & 1) odd.emplace_back(x);
    else even.emplace_back(x);
  }

  int odd_cnt = (int)odd.size(), even_cnt = (int)even.size();
  if (std::max(odd_cnt, even_cnt) - std::min(odd_cnt, even_cnt) <= 1) {
    std::cout << 0 << '\n';
    return 0;
  }

  long long ans = 0;
  if (odd_cnt > even_cnt) {
    sort(odd.begin(), odd.end());
    for (int i = 0; i < odd_cnt - even_cnt - 1; ++i) ans += odd[i];
  }
  else {
    sort(even.begin(), even.end());
    for (int i = 0; i < even_cnt - odd_cnt - 1; ++i) ans += even[i];
  }

  std::cout << ans << '\n';
  return 0;
}
