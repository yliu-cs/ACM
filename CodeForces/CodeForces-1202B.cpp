#include <bits/stdc++.h>

const int INF = 1e9 + 5;

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::string s;
  std::cin >> s;
  int n = (int)s.length();
  std::vector<std::vector<std::vector<int>>> dis(10, std::vector<std::vector<int>>(10, std::vector<int>(10)));
  for (int x = 0; x < 10; ++x) {
    for (int y = 0; y < 10; ++y) {
      for (int v = 0; v < 10; ++v) {
        int dist = INF;
        for (int d = 1; d < 100; ++d) {
          for (int k = 0; k <= d; ++k) {
            int cur = k * x + (d - k) * y;
            if (cur % 10 == v) {
              dist = d;
              break;
            }
          }
          if (dist != INF) {
            break;
          }
        }
        if (dist == INF) {
          dist = -1;
        }
        else {
          --dist;
        }
        dis[x][y][v] = dis[y][x][v] = dist;
      }
    }
  }
  std::vector<std::vector<int>> ans(10, std::vector<int>(10));
  for (int x = 0; x < 10; ++x) {
    for (int y = x; y < 10; ++y) {
      int dist = 0;
      bool f = true;
      for (int i = 1; i < n; ++i) {
        int diff = s[i] - s[i - 1];
        if (diff < 0) {
          diff += 10;
        }
        if (dis[x][y][diff] == -1) {
          f = false;
          break;
        }
        else {
          dist += dis[x][y][diff];
        }
      }
      if (!f) {
        dist = -1;
      }
      ans[x][y] = ans[y][x] = dist;
    }
  }
  for (int x = 0; x < 10; ++x) {
    for (int y = 0; y < 10; ++y) {
      std::cout << ans[x][y] << ' ';
    }
    std::cout << '\n';
  }
  return 0;
}

