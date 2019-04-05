#include <bits/stdc++.h>

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr); std::cout.tie(nullptr);

  int n; std::cin >> n;
  std::vector<std::pair<int, int>> p(n);
  for (auto &v : p) std::cin >> v.first >> v.second;

  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      if (p[i].first + p[i].second == p[j].first && p[j].first + p[j].second == p[i].first) {
        std::cout << "YE5" << '\n';
        return 0;
      }
    }
  }

  std::cout << "N0" << '\n';
  return 0;
}
