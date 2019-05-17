#include <bits/stdc++.h>
#include <bits/extc++.h>

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr); std::cout.tie(nullptr);

  int m, n; std::cin >> m >> n;
  std::vector<std::set<int>> set(m);
  
  for (int i = 0, k; i < m; ++i) {
    std::cin >> k;
    for (int j = 0, x; j < k; ++j) {
      std::cin >> x;
      set[i].emplace(x);
    }
  }

  bool flag = true;

  for (int i = 0; i < m; ++i) {
    for (int j = i + 1; j < m; ++j) {
      bool ok = false;
      for (auto &v : set[j]) {
        if (set[i].find(v) != set[i].end()) {
          ok = true;
          break;
        }
      }
      if (!ok) {
        flag = false;
        break;
      }
    }
    if (!flag) break;
  }

  if (flag) std::cout << "possible" << '\n';
  else std::cout << "impossible" << '\n';
  return 0;
}

