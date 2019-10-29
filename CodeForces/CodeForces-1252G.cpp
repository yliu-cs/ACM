// Author: Tonyst4rk Time: 2019-10-29 16:07:53
#include <bits/stdc++.h>

const int N = 1e5 + 5;
const int M = 1e5 + 5;

int min[M * 4], lazy[M * 4];

void Pull(int o) {
  min[o] = std::min(min[o * 2], min[o * 2 + 1]);
}

void Push(int o) {
  if (lazy[o] != 0) {
    min[o * 2] += lazy[o];
    min[o * 2 + 1] += lazy[o];
    lazy[o * 2] += lazy[o];
    lazy[o * 2 + 1] += lazy[o];
    lazy[o] = 0;
  }
}

void Build(int o, int l, int r, int rk[]) {
  if (l == r) {
    min[o] = rk[l];
    return;
  }
  int m = (l + r) / 2;
  Build(o * 2, l, m, rk);
  Build(o * 2 + 1, m + 1, r, rk);
  Pull(o);
}

void Modify(int o, int l, int r, int ll, int rr, int v) {
  if (ll <= l && rr >= r) {
    min[o] += v;
    lazy[o] += v;
    return;
  }
  Push(o);
  int m = (l + r) / 2;
  if (ll <= m) Modify(o * 2, l, m, ll, rr, v);
  if (rr > m) Modify(o * 2 + 1, m + 1, r, ll, rr, v);
  Pull(o);
}

int n, m, q;
int a[N];
std::vector<int> b[M];
int rank, rk[M];

int main() {
  scanf("%d%d%d", &n, &m, &q);
  for (int i = 1; i <= n; ++i) {
    scanf("%d", &a[i]);
    if (i == 1) rank = 1;
    else if (a[i] < a[1]) ++rank;
  }
  rk[0] = rank;
  for (int i = 1, sz; i <= m; ++i) {
    scanf("%d", &sz);
    b[i].resize(sz + 1);
    rk[i] = rank - sz;
    for (int j = 1; j <= sz; ++j) {
      scanf("%d", &b[i][j]);
      if (b[i][j] > a[1]) --rank;
    }
  }
  Build(1, 1, m, rk);
  while (q--) {
    int x, y, z;
    scanf("%d%d%d", &x, &y, &z);
    if (x < m) {
      if (z > a[1] && b[x][y] < a[1]) Modify(1, 1, m, x + 1, m, -1);
      if (z < a[1] && b[x][y] > a[1]) Modify(1, 1, m, x + 1, m, 1);
    }
    b[x][y] = z;
    printf("%d\n", (min[1] > 0 ? 1 : 0));
  }
  return 0;
}

