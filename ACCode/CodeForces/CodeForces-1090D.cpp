#include <bits/stdc++.h>

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr); std::cout.tie(nullptr);

  int n, m; std::cin >> n >> m;

  std::set<std::pair<int, int>> e;

  for (int i = 1, u, v; i <= m; ++i) {
    std::cin >> u >> v;
    e.insert({u, v});
    e.insert({v, u});
  }

  for (int i = 1; i <= n; ++i) {
    for (int j = i + 1; j <= n; ++j) {
      if (e.find({i, j}) != e.end()) continue;
      std::cout << "YES" << '\n';
      int cur = 1;
      for (int k = 1; k <= n; ++k) {
        if (k == i) {
          std::cout << n << ' ';
          continue;
        }
        if (k == j) {
          std::cout << n - 1 << ' ';
          continue;
        }
        std::cout << cur++ << ' ';
      }
      std::cout << '\n';
      cur = 1;
      for (int k = 1; k <= n; ++k) {
        if (k == i || k == j) {
          std::cout << n << ' ';
          continue;
        }
        std::cout << cur++ << ' ';
      }
      std::cout << '\n';
      return 0;
    }
  }

  std::cout << "NO" << '\n';
  return 0;
}

