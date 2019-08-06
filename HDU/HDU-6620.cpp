#include <bits/stdc++.h>
typedef long long ll;

int grid[5][5];
int posx, posy;

int Count(int x, int y) {
  int ret = 0;
  for (int i = 1; i <= x; ++i) {
    for (int j = 1; j <= (i == x ? y : 4); ++j) {
      if (grid[i][j] > grid[x][y]) ++ret;
    }
  }
  return ret;
}

int main() {
  int t;
  scanf("%d", &t);
  for (int cas = 1; cas <= t; ++cas) {
    int cnt = 0;
    for (int i = 1; i <= 4; ++i) {
      for (int j = 1; j <= 4; ++j) {
        scanf("%d", &grid[i][j]);
        if (grid[i][j] == 0) {
          posx = i;
          posy = j;
          continue;
        }
        cnt += Count(i, j);
      }
    }
    if (cnt & 1) {
      if (std::abs(4 - posx) & 1) printf("Yes\n");
      else printf("No\n");
    }
    else if (std::abs(4 - posx) % 2 == 0) printf("Yes\n");
    else printf("No\n");
  }
  return 0;
}