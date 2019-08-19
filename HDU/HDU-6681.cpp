#include <bits/stdc++.h>
const int maxn = 4e5 + 5;
struct FuncSegTree {
  int tot;
  int rt[maxn];
  int lson[maxn * 40], rson[maxn * 40];
  int cnt[maxn * 40];
  int Build(int l, int r) {
    int o = ++tot, m = (l + r) / 2;
    cnt[o] = 0;
    if (l != r) {
      lson[o] = Build(l, m);
      rson[o] = Build(m + 1, r);
    }
    return o;
  }
  int Modify(int p, int l, int r, int v) {
    int o = ++tot, m = (l + r) / 2;
    lson[o] = lson[p];
    rson[o] = rson[p];
    cnt[o] = cnt[p] + 1;
    if (l != r) {
      if (v <= m) lson[o] = Modify(lson[o], l, m, v);
      else rson[o] = Modify(rson[o], m + 1, r, v);
    }
    return o;
  }
  long long Query(int u, int v, int s, int t, int l, int r) {
    if (s <= l && t >= r) return cnt[v] - cnt[u];
    int m = (l + r) / 2;
    long long ret = 0;
    if (s <= m) ret += Query(lson[u], lson[v], s, t, l, m);
    if (t > m) ret += Query(rson[u], rson[v], s, t, m + 1, r);
    return ret;
  }
};
int x[maxn], y[maxn];
int xsz, ysz;
struct line { int x, y; char dir; };
line opt[maxn];
FuncSegTree T1, T2;
int GetX(int _x) {
  return std::lower_bound(x + 1, x + xsz + 1, _x) - x;
}
int GetY(int _y) {
  return std::lower_bound(y + 1, y + ysz + 1, _y) - y;
}
int arr1[maxn], arr2[maxn];
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int t;
  std::cin >> t;
  while (t--) {
    int n, m, k;
    std::cin >> n >> m >> k;
    xsz = 0, ysz = 0;
    x[++xsz] = 0; y[++ysz] = 0;
    x[++xsz] = n; y[++ysz] = m;
    for (int i = 1; i <= k; ++i) {
      std::cin >> opt[i].x >> opt[i].y >> opt[i].dir;
      opt[i].y = m - opt[i].y;
      x[++xsz] = opt[i].x; y[++ysz] = opt[i].y;
    }
    std::sort(x + 1, x + xsz + 1);
    xsz = std::unique(x + 1, x + xsz + 1) - x - 1;
    std::sort(y + 1, y + ysz + 1);
    ysz = std::unique(y + 1, y + ysz + 1) - y - 1;
    long long ans = 1;
    for (int i = 1; i <= ysz; ++i) arr1[i] = 1;
    for (int i = 1; i <= ysz; ++i) arr2[i] = 1;
    arr1[1] = xsz; arr1[ysz] = xsz;
    arr2[1] = xsz; arr2[ysz] = xsz;
    for (int i = 1; i <= k; ++i) {
      int _x = GetX(opt[i].x), _y = GetY(opt[i].y);
      if (opt[i].dir == 'L') {
        arr1[_y] = _x;
        if (_x == xsz) ++ans;
      }
      else if (opt[i].dir == 'R') {
        arr2[_y] = xsz - _x + 1;
        if (_x == 1) ++ans;
      }
    }
    T1.tot = 0; T1.rt[0] = T1.Build(1, ysz);
    T2.tot = 0; T2.rt[0] = T2.Build(1, ysz);
    for (int i = 1; i <= ysz; ++i) {
      T1.rt[i] = T1.Modify(T1.rt[i - 1], 1, xsz, arr1[i]);
      T2.rt[i] = T2.Modify(T2.rt[i - 1], 1, xsz, arr2[i]);
    }
    for (int i = 1; i <= k; ++i) {
      if (opt[i].dir == 'L' || opt[i].dir == 'R') continue;
      int _x = GetX(opt[i].x), _y = GetY(opt[i].y);
      if (opt[i].dir == 'U') {
        ans += T1.Query(T1.rt[0], T1.rt[_y], _x, xsz, 1, xsz);
        ans += T2.Query(T2.rt[0], T2.rt[_y], xsz - _x + 1, xsz, 1, xsz);
        ans -= 2;
      }
      else if (opt[i].dir == 'D') {
        ans += T1.Query(T1.rt[_y - 1], T1.rt[ysz], _x, xsz, 1, xsz);
        ans += T2.Query(T2.rt[_y - 1], T2.rt[ysz], xsz - _x + 1, xsz, 1, xsz);
        ans -= 2;
      }
    }
    printf("%lld\n", ans);
  }
  return 0;
}
