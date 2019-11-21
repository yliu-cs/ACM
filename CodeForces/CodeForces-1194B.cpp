#include <bits/stdc++.h>

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int t;
  std::cin >> t;
  while (t--) {
    int n, m;
    std::cin >> n >> m;
    std::vector<std::vector<char>> pic(n, std::vector<char>(m));
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
        std::cin >> pic[i][j];
      }
    }
    std::vector<int> row(n, 0), col(m, 0);
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
        row[i] += (pic[i][j] == '*');
      }
    }
    for (int j = 0; j < m; ++j) {
      for (int i = 0; i < n; ++i) {
        col[j] += (pic[i][j] == '*');
      }
    }
    int ans = n + m;
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
        if (pic[i][j] == '*') {
          ans = std::min(ans, m + n - row[i] - col[j]);
        }
        else {
          ans = std::min(ans, m + n - row[i] - col[j] - 1);
        }
      }
    }
    ans = std::max(ans, 0);
    std::cout << ans << '\n';
  }
  return 0;
}

