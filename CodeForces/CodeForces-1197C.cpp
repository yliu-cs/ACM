#include <bits/stdc++.h>

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int n, k;
  std::cin >> n >> k;
  std::vector<int> a(n);
  std::vector<std::pair<int, int>> diff;
  std::vector<int> div;
  div.push_back(0);
  div.push_back(n);
  for (int i = 0; i < n; ++i) {
    std::cin >> a[i];
    if (i != 0) {
      diff.push_back({a[i] - a[i - 1], i});
    }
  }
  --k;
  std::sort(diff.begin(), diff.end());
  while (k--) {
    auto buf = diff.back();
    diff.pop_back();
    div.push_back(buf.second);
  }
  std::sort(div.begin(), div.end());
  int ans = 0;
  for (int i = 1; i < (int)div.size(); ++i) {
    ans += a[div[i] - 1] - a[div[i - 1]];
  }
  std::cout << ans << '\n';
  return 0;
}

