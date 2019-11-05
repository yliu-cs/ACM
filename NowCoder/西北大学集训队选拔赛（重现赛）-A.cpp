#include <bits/stdc++.h>
#include <bits/extc++.h>

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr); std::cout.tie(nullptr);

  int n, t; std::cin >> n >> t;
  std::vector<std::pair<int, int>> info(n);
  for (std::pair<int, int> &v : info) std::cin >> v.first >> v.second;

  std::vector<int> diff;
  for (int i = 1; i < n; ++i) diff.push_back(info[i].first - info[i - 1].second);
  std::sort(diff.begin(), diff.end());

  int ans = 0;
  for (int &v : diff) {
    if (t < v) break;
    ++ans;
    t -= v + 1;
  }

  std::cout << ans << '\n';
  return 0;
}

