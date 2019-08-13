#include <bits/stdc++.h>
const int maxn = 3e3 + 5;
struct BitTree2D {
  int tree[4][maxn][maxn];
  void Modify(int x, int y, int v) {
    for (int i = x; i < maxn; i += i & (-i)) {
      for (int j = y; j < maxn; j += j & (-j)) {
        tree[0][i][j] += v;
        tree[1][i][j] += v * y;
        tree[2][i][j] += v * x;
        tree[3][i][j] += v * x * y;
      }
    }
  }
  int Query(int x, int y) {
    int ret = 0;
    for (int i = x; i > 0; i -= i & (-i)) {
      for (int j = y; j > 0; j -= j & (-j)) {
        ret += tree[0][i][j] * (x + 1) * (y + 1);
        ret -= tree[1][i][j] * (x + 1);
        ret -= tree[2][i][j] * (y + 1);
        ret += tree[3][i][j];
      }
    }
    return ret;
  }
};
BitTree2D T;
int main() {
  int n, m;
  scanf("%d%d", &n, &m);
  char opt[2];
  while (~scanf("%s", opt)) {
    if (opt[0] == 'L') {
      int a, b, c, d, v;
      scanf("%d%d%d%d%d", &a, &b, &c, &d, &v);
      T.Modify(a, b, v);
      T.Modify(c + 1, b, -v);
      T.Modify(a, d + 1, -v);
      T.Modify(c + 1, d + 1, v);
    }
    else if (opt[0] == 'k') {
      int a, b, c, d;
      scanf("%d%d%d%d", &a, &b, &c, &d);
      printf("%d\n", T.Query(c, d) - T.Query(a - 1, d) - T.Query(c, b - 1) + T.Query(a - 1, b - 1));
    }
  }
  return 0;
}
