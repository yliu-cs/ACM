#include <bits/stdc++.h>
const int maxn = 5;

int t;
int n;
char str[maxn];
int mat[maxn][maxn];
int buf[maxn][maxn];

void Rotate(int r, int c, int dir) {
  buf[1][1] = mat[r][c];
  buf[1][2] = mat[r][c + 1];
  buf[2][1] = mat[r + 1][c];
  buf[2][2] = mat[r + 1][c + 1];
  if (dir == 1) {
    mat[r][c] = buf[2][1];
    mat[r][c + 1] = buf[1][1];
    mat[r + 1][c] = buf[2][2];
    mat[r + 1][c + 1] = buf[1][2];
  }
  else {
    mat[r][c] = buf[1][2];
    mat[r][c + 1] = buf[2][2];
    mat[r + 1][c] = buf[1][1];
    mat[r + 1][c + 1] = buf[2][1];
  }
}

int main() {
  scanf("%d", &t);
  for (int cas = 1; cas <= t; ++cas) {
    scanf("%d", &n);
    for (int i = 1; i <= 3; ++i) {
      scanf("%s", str);
      for (int j = 0; j < 3; ++j) {
        mat[i][j + 1] = (str[j] - '0');
      }
    }
    for (int i = 1; i <= n; ++i) {
      scanf("%s", str);
      int idx = (str[0] - '0');
      int r, c, dir;
      if (str[1] == 'C') dir = 1;
      else if (str[1] == 'R') dir = 0;
      if (idx == 1) {
        r = 1;
        c = 1;
      }
      else if (idx == 2) {
        r = 1;
        c = 2;
      }
      else if (idx == 3) {
        r = 2;
        c = 1;
      }
      else if (idx == 4) {
        r = 2;
        c = 2;
      }
      Rotate(r, c, dir);
    }
    for (int i = 1; i <= 3; ++i) {
      for (int j = 1; j <= 3; ++j) {
        printf("%d", mat[i][j]);
      }
      printf("\n");
    }
  }
  return 0;
}

