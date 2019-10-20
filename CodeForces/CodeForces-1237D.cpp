// Author: Tony5t4rk Time: 2019-10-20 21:07:09 
#include <bits/stdc++.h>
const int N = 3e5 + 5;
const int INF = 1e9 + 5;
int n, max, min;
int a[N];
int tree[N * 4];
void Pull(int o) {
  tree[o] = std::max(tree[o * 2], tree[o * 2 + 1]);
}
void Build(int o, int l, int r) {
  if (l == r) {
    tree[o] = a[l];
    return;
  }
  int m = (l + r) / 2;
  Build(o * 2, l, m);
  Build(o * 2 + 1, m + 1, r);
  Pull(o);
}
int Query(int o, int l, int r, int ll, int rr) {
  if (ll <= l && rr >= r) return tree[o];
  int m = (l + r) / 2, ret = 0;
  if (ll <= m) ret = std::max(ret, Query(o * 2, l, m, ll, rr));
  if (rr > m) ret = std::max(ret, Query(o * 2 + 1, m + 1, r, ll, rr));
  return ret;
}
int main() {
  scanf("%d", &n);
  max = -INF; min = INF;
  for (int i = 1; i <= n; ++i) {
    scanf("%d", &a[i]);
    a[2 * n + i] = a[n + i] = a[i];
    max = std::max(max, a[i]);
    min = std::min(min, a[i]);
  }
  if (max <= min * 2) {
    for (int i = 1; i <= n; ++i) printf("-1 ");
    printf("\n");
    return 0;
  }
  Build(1, 1, 3 * n);
  int ptr = 1;
  for (int i = 1; i <= n; ++i) {
    int cur = Query(1, 1, 3 * n, i, ptr);
    while (ptr <= 3 * n && cur <= a[ptr] * 2) {
      ++ptr;
      cur = std::max(cur, a[ptr]);
    }
    printf("%d ", ptr - i);
  }
  printf("\n");
  return 0;
}
