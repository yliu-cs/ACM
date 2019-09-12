#include <bits/stdc++.h>
const int maxn = 1e5 + 5;
const int inf = 1e9 + 5;
struct SegTree {
  int n;
  int pos[maxn * 4];
  void Pull(int o) {
    pos[o] = std::max(pos[o * 2], pos[o * 2 + 1]);
  }
  void Build(int o, int l, int r) {
    if (l == r) {
      pos[o] = inf;
      return;
    }
    int m = (l + r) / 2;
    Build(o * 2, l, m);
    Build(o * 2 + 1, m + 1, r);
    Pull(o);
  }
  void Init(int _n) {
    n = _n;
    Build(1, 1, n);
  }
  void Modify(int o, int l, int r, int idx, int v) {
    if (l == r) {
      pos[o] = v;
      return;
    }
    int m = (l + r) / 2;
    if (idx <= m) Modify(o * 2, l, m, idx, v);
    else Modify(o * 2 + 1, m + 1, r, idx, v);
    Pull(o);
  }
  void Modify(int idx, int v) {
    Modify(1, 1, n, idx, v);
  }
  int Query(int o, int l, int r, int ll, int rr, int v) {
    if (l == r) return l;
    int m = (l + r) / 2, ret = inf;
    if (ll <= m && pos[o * 2] > v) ret = Query(o * 2, l, m, ll, rr, v);
    if (ret != inf) return ret;
    if (rr > m && pos[o * 2 + 1] > v) ret = Query(o * 2 + 1, m + 1, r, ll, rr, v);
    return ret;
  }
  int Query(int ll, int v) {
    return Query(1, 1, n, ll, n, v);
  }
};
int t;
int n, m;
SegTree tree;
int a[maxn];
int ans;
int main() {
  scanf("%d", &t);
  for (int cas = 1; cas <= t; ++cas) {
    scanf("%d%d", &n, &m);
    tree.Init(n + 1);
    ans = 0;
    for (int i = 1; i <= n; ++i) {
      scanf("%d", &a[i]);
      tree.Modify(a[i], i);
    }
    for (int i = 1; i <= m; ++i) {
      int op;
      scanf("%d", &op);
      if (op == 1) {
        int pos;
        scanf("%d", &pos);
        pos ^= ans;
        tree.Modify(a[pos], inf);
      }
      else if (op == 2) {
        int r, k;
        scanf("%d%d", &r, &k);
        r ^= ans; k ^= ans;
        ans = tree.Query(k, r);
        printf("%d\n", ans);
      }
    }
  }
  return 0;
}
