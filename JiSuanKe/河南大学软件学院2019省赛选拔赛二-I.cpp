#include <bits/stdc++.h>

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr); std::cout.tie(nullptr);

  int n, m; std::cin >> n >> m;
  std::vector<std::vector<int>> r(n), c(m);
  std::vector<std::vector<int>> matrix(n, std::vector<int>(m, 0));
  std::vector<std::pair<int, int>> s;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      std::cin >> matrix[i][j];
      if (matrix[i][j]) {
        r[i].push_back(j);
        c[j].push_back(i);
      }
      else s.push_back({i, j});
    }
  }

  int ans = 0;
  for (auto &cor : s) {
    int x = cor.first, y = cor.second;
    int cnt = 0;
    if (!r[x].empty()) {
      int pos = lower_bound(r[x].begin(), r[x].end(), y) - r[x].begin();
      if (pos > 0) cnt++;
      if (r[x][pos] > y && pos != (int)r[x].size()) cnt++;
    }
    if (!c[y].empty()) {
      int pos = lower_bound(c[y].begin(), c[y].end(), x) - c[y].begin();
      if (pos > 0) cnt++;
      if (c[y][pos] > x && pos != (int)c[y].size()) cnt++;
    }
    ans += cnt;
  }

  std::cout << ans << '\n';
  return 0;
}
