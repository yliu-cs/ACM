#include <bits/stdc++.h>

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr); std::cout.tie(nullptr);

  int n, m; std::cin >> n >> m;
  std::vector<std::vector<int>> matrix(n, std::vector<int>(m));
  int cur = 0;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      std::cin >> matrix[i][j];
    }
    cur ^= matrix[i][0];
  }

  if (cur > 0) {
    std::cout << "TAK" << '\n';
    for (int i = 0; i < n; ++i) std::cout << 1 << ' ';
    std::cout << '\n';
    return 0;
  }

  for (int i = 0; i < n; ++i) {
    cur ^= matrix[i][0];
    for (int j = 1; j < m; ++j) {
      cur ^= matrix[i][j];
      if (cur > 0) {
        std::cout << "TAK" << '\n';
        for (int k = 0; k < i; ++k) std::cout << 1 << ' ';
        std::cout << j + 1 << ' ';
        for (int k = i + 1; k < n; ++k) std::cout << 1 << ' ';
        std::cout << '\n';
        return 0;
      }
      cur ^= matrix[i][j];
    }
    cur ^= matrix[i][0];
  }

  std::cout << "NIE" << '\n';
  return 0;
}

