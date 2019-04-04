#include <bits/stdc++.h>

std::vector<std::vector<int>> clue;
std::vector<std::vector<bool>> col;

void Change(int x, int y) {
  for (int i = -1; i < 2; ++i) {
    for (int j = -1; j < 2; ++j) {
      if (clue[x + i][y + j] <= 0) return;
    }
  }
  col[x][y] = true;
  for (int i = -1; i < 2; ++i) {
    for (int j = -1; j < 2; ++j) {
      --clue[x + i][y + j];
    }
  }
}

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr); std::cout.tie(nullptr);

  int h, w; std::cin >> h >> w;
  clue = std::vector<std::vector<int>>(h + 2, std::vector<int>(w + 2, 0));
  for (int i = 0; i < h + 2; ++i)
    for (int j = 0; j < w + 2; ++j)
      std::cin >> clue[i][j];

  col = std::vector<std::vector<bool>>(h + 2, std::vector<bool>(w + 2, false));

  int cir = (std::min(h, w) + 1) / 2;
  int l = 1, r = w, t = 1, b = h;
  for (int k = 0; k < cir; ++k) {
    Change(t, l); Change(t, r);
    Change(b, l); Change(b, r);

    int m = (l + r + 1) / 2;

    for (int i = l + 1; i < m; ++i) Change(t, i);
    for (int i = r - 1; i >= m; --i) Change(t, i);
    for (int i = l + 1; i < m; ++i) Change(b, i);
    for (int i = r - 1; i >= m; --i) Change(b, i);

    m = (t + b + 1) / 2;

    for (int i = t + 1; i < m; ++i) Change(i, l);
    for (int i = b - 1; i >= m; --i) Change(i, l);
    for (int i = t + 1; i < m; ++i) Change(i, r);
    for (int i = b - 1; i >= m; --i) Change(i, r);

    if (l != r) {
      ++l;
      --r;
    }
    if (t != b) {
      ++t;
      --b;
    }
  }

  for (int i = 0; i < h + 2; ++i) {
    for (int j = 0; j < w + 2; ++j) {
      if (clue[i][j] > 0) {
        std::cout << "impossible\n";
        return 0;
      }
    }
  }

  for (int i = 1; i <= h; ++i) {
    for (int j = 1; j <= w; ++j) {
      std::cout << (col[i][j] ? 'X' : '.');
    }
    std::cout << '\n';
  }
  return 0;
}
