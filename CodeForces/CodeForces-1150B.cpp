#include <bits/stdc++.h>

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr); std::cout.tie(nullptr);

  int n; std::cin >> n;
  std::vector<std::vector<char>> maze(n, std::vector<char>(n));
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      std::cin >> maze[i][j];
    }
  }

  for (int i = 1; i < n - 1; ++i) {
    for (int j = 1; j < n - 1; ++j) {
      if (maze[i][j] == '.' && maze[i - 1][j] == '.' && maze[i + 1][j] == '.'
          && maze[i][j - 1] == '.' && maze[i][j + 1] == '.') {
        maze[i][j] = '#';
        maze[i + 1][j] = '#';
        maze[i - 1][j] = '#';
        maze[i][j + 1] = '#';
        maze[i][j - 1] = '#';
      }
    }
  }

  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      if (maze[i][j] == '.') {
        std::cout << "NO" << '\n';
        return 0;
      }
    }
  }
  std::cout << "YES" << '\n';

  return 0;
}

