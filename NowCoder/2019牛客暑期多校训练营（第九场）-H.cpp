#include <bits/stdc++.h>
const int maxn = 1e5 + 5;
const double eps = 1e-9;
int Sgn(double k) {
  return std::fabs(k) < eps ? 0 : (k < 0 ? -1 : 1);
}
int Cmp(double k1, double k2) {
  return Sgn(k1 - k2);
}
struct FuncSegTree {
  int tot;
  int rt[maxn * 40];
  int lson[maxn * 40], rson[maxn * 40];
  int cnt[maxn * 40];
  long long sum[maxn * 40];
  int Build(int l, int r) {
    int o = ++tot, m = (l + r) / 2;
    cnt[o] = 0;
    if (l != r) {
      lson[o] = Build(l, m);
      rson[o] = Build(m + 1, r);
    }
    return o;
  }
  int Modify(int prev, int l, int r, int v) {
    int o = ++tot, m = (l + r) / 2;
    lson[o] = lson[prev];
    rson[o] = rson[prev];
    cnt[o] = cnt[prev] + 1;
    sum[o] = sum[prev] + v;
    if (l != r) {
      if (v <= m) lson[o] = Modify(lson[o], l, m, v);
      else rson[o] = Modify(rson[o], m + 1, r, v);
    }
    return o;
  }
  int QueryCnt(int u, int v, int s, int t, int l, int r) {
    if (s <= l && t >= r) return cnt[v] - cnt[u];
    int m = (l + r) / 2, ret = 0;
    if (s <= m) ret += QueryCnt(lson[u], lson[v], s, t, l, m);
    if (t > m) ret += QueryCnt(rson[u], rson[v], s, t, m + 1, r);
    return ret;
  }
  long long QuerySum(int u, int v, int s, int t, int l, int r) {
    if (s <= l && t >= r) return sum[v] - sum[u];
    int m = (l + r) / 2;
    long long ret = 0;
    if (s <= m) ret += QuerySum(lson[u], lson[v], s, t, l, m);
    if (t > m) ret += QuerySum(rson[u], rson[v], s, t, m + 1, r);
    return ret;
  }
};
FuncSegTree T;
int h[maxn];
long long pre[maxn];
int main() {
  int n, q;
  scanf("%d%d", &n, &q);
  int max = 0;
  for (int i = 1; i <= n; ++i) {
    scanf("%d", &h[i]);
    max = std::max(max, h[i]);
    pre[i] = pre[i - 1] + h[i];
  }
  T.tot = 0;
  T.rt[0] = T.Build(1, max);
  for (int i = 1; i <= n; ++i) T.rt[i] = T.Modify(T.rt[i - 1], 1, max, h[i]);
  for (int i = 1; i <= q; ++i) {
    int l, r, x, y;
    scanf("%d%d%d%d", &l, &r, &x, &y);
    double tar = 1. * (pre[r] - pre[l - 1]) * x / y;
    double bl = 0, br = max;
    while (Cmp(bl, br)) {
      double bm = (bl + br) * 0.5;
      int cnt = T.QueryCnt(T.rt[l - 1], T.rt[r], std::ceil(bm), max, 1, max);
      long long sum = T.QuerySum(T.rt[l - 1], T.rt[r], std::ceil(bm), max, 1, max);
      double del = 1. * sum - 1. * cnt * bm;
      if (Cmp(del, tar) > 0) bl = bm;
      else br = bm;
    }
    printf("%.15lf\n", bl);
  }
  return 0;
}
