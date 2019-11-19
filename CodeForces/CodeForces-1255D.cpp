#include <bits/stdc++.h>

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int t;
  std::cin >> t;
  while (t--) {
    std::vector<char> data;
    for (int i = 0; i < 10; ++i) {
      data.push_back((char)(i + '0'));
    }
    for (int i = 0; i < 26; ++i) {
      data.push_back((char)(i + 'a'));
    }
    for (int i = 0; i < 26; ++i) {
      data.push_back((char)(i + 'A'));
    }
    int n, m, k;
    std::cin >> n >> m >> k;
    std::vector<std::vector<char>> maze(n, std::vector<char>(m));
    int r = 0;
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
        std::cin >> maze[i][j];
        if (maze[i][j] == 'R') {
          ++r;
        }
      }
    }
    int less = r / k;
    int more = less + 1;
    int cnt2 = r - k * less;
    int cnt1 = (r - cnt2 * more) / less;
    auto Next = [&](std::pair<int, int> k) -> std::pair<int, int> {
      int x = k.first, y = k.second;
      if (x & 1) {
        if (y == 0) {
          return {x + 1, y};
        }
        return {x, y - 1};
      }
      else {
        if (y == m - 1) {
          return {x + 1, y};
        }
        return {x, y + 1};
      }
    };
    auto Get = [&](std::pair<int, int> k) {
      return maze[k.first][k.second];
    };
    auto Check = [&](std::pair<int, int> k) {
      return k.first >= 0 && k.first < n && k.second >= 0 && k.second < m;
    };
    std::pair<int, int> idx = {0, 0};
    std::vector<std::vector<int>> ans(n, std::vector<int>(m, 0));
    for (int i = 0; i < k; ++i) {
      if (less == 0 && cnt1 != 0 && Get(idx) == '.') {
        ans[idx.first][idx.second] = i;
        --cnt1;
        idx = Next(idx);
        continue;
      }
      if (cnt1 != 0) {
        int cnt = 0;
        while (cnt < less) {
          cnt += (Get(idx) == 'R');
          ans[idx.first][idx.second] = i;
          idx = Next(idx);
        }
        --cnt1;
      }
      else if (cnt2 != 0) {
        int cnt = 0;
        while (cnt < more) {
          cnt += (Get(idx) == 'R');
          ans[idx.first][idx.second] = i;
          idx = Next(idx);
        }
        --cnt2;
      }
    }
    while (Check(idx)) {
      ans[idx.first][idx.second] = k - 1;
      idx = Next(idx);
    }
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
        std::cout << data[ans[i][j]];
      }
      std::cout << '\n';
    }
  }
  return 0;
}

