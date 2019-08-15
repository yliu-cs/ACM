#include <bits/stdc++.h>
const int maxn = 1e5 + 5;
int pre[maxn];
long long sz[maxn];
int Find(int x) {
  return pre[x] == x ? x : pre[x] = Find(pre[x]);
}
void Union(int x, int y) {
  int xx = Find(x), yy = Find(y);
  if (xx == yy) return;
  pre[yy] = xx;
  sz[xx] += sz[yy];
}
int main() {
  int n, m;
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; ++i) {
    pre[i] = i;
    sz[i] = 1;
  }
  long long ans = (__int128)n * (n - 1) * (n - 2) * (n - 3) / 24;
  printf("%lld\n", ans);
  long long sum = 0;
  for (int i = 1, x, y; i <= m; ++i) {
    scanf("%d%d", &x, &y);
    x = Find(x);
    y = Find(y);
    if (x != y) {
      long long cnt = (n - sz[x] - sz[y]) * (n - sz[x] - sz[y] - 1) / 2;
      sum -= sz[x] * (sz[x] - 1) / 2;
      sum -= sz[y] * (sz[y] - 1) / 2;
      ans -= sz[x] * sz[y] * (cnt - sum);
      pre[x] = y;
      sz[y] += sz[x];
      sum += sz[y] * (sz[y] - 1) / 2;
    }
    printf("%lld\n", ans);
  }
  return 0;
}
