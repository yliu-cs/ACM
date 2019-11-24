#include <bits/stdc++.h>

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int n, m;
  std::cin >> n >> m;
  std::vector<std::vector<int>> a(n, std::vector<int>(m));
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      std::cin >> a[i][j];
    }
  }
  std::vector<std::pair<int, int>> ans;
  for (int i = 0; i < n - 1; ++i) {
    for (int j = 0; j < m - 1; ++j) {
      if (a[i][j] == 1 && a[i + 1][j] == 1 && a[i][j + 1] == 1 && a[i + 1][j + 1] == 1) {
        ans.push_back({i, j});
      }
    }
  }
  std::vector<std::vector<int>> b(n, std::vector<int>(m, 0));
  for (int i = 0; i < (int)ans.size(); ++i) {
    int x = ans[i].first, y = ans[i].second;
    b[x][y] = 1;
    b[x + 1][y] = 1;
    b[x][y + 1] = 1;
    b[x + 1][y + 1] = 1;
  }
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      if (a[i][j] != b[i][j]) {
        std::cout << -1 << '\n';
        return 0;
      }
    }
  }
  std::cout << ans.size() << '\n';
  for (int i = 0; i < (int)ans.size(); ++i) {
    std::cout << ans[i].first + 1 << ' ' << ans[i].second + 1 << '\n';
  }
  return 0;
}

