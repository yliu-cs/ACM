#include <bits/stdc++.h>

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0); std::cout.tie(0);

  freopen("hamming.in", "r", stdin);

  int t; std::cin >> t;
  for (int cas = 1; cas <= t; ++cas) {
    int n; std::cin >> n;
    std::string str1, str2; std::cin >> str1 >> str2;
    std::map<int, std::pair<int, int>> cnt;
    for (auto &c : str1) {
      if (c == '0') cnt[1].first++;
      else if (c == '1') cnt[1].second++;
    }
    for (auto &c : str2) {
      if (c == '0') cnt[2].first++;
      else if (c == '1') cnt[2].second++;
    }
    std::cout << std::min(cnt[1].first, cnt[2].second) + std::min(cnt[1].second, cnt[2].first) << '\n';
  }
  return 0;
}
