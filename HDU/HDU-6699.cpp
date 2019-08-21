#include <bits/stdc++.h>
const int maxn = 2e3 + 5;
int n, m, q;
bool map[maxn][maxn];
bool Check(int x, int y) {
  return x >= 1 && x <= n && y >= 1 && y <= m;
}
bool Judge(int x, int y) {
  if (!Check(x, y)) return false;
  if ((Check(x - 1, y) && !map[x - 1][y]) || (Check(x + 1, y) && !map[x + 1][y]))
    if ((Check(x, y - 1) && !map[x][y - 1]) || (Check(x, y + 1) && !map[x][y + 1]))
      return true;
  return false;
}
int Knock(int x, int y) {
  if (!map[x][y]) return 0;
  map[x][y] = false;
  int ret = 1;
  for (int i = -1; i <= 1; ++i)
    for (int j = -1; j <= 1; ++j)
      if (Judge(x + i, y + j) && std::abs(i) != std::abs(j))
        ret += Knock(x + i, y + j);
  return ret;
}
int main() {
  int t; scanf("%d", &t);
  while (t--) {
    scanf("%d%d%d", &n, &m, &q);
    for (int i = 1; i <= n; ++i)
      for (int j = 1; j <= m; ++j)
        map[i][j] = true;
    int ans = 0;
    while (q--) {
      int x, y; scanf("%d%d", &x, &y);
      printf("%d\n", Knock(x, y));
    }
  }
  return 0;
}
