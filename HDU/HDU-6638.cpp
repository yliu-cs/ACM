#include <bits/stdc++.h>
const long long inf = 1e18 + 5;
const int maxn = 2e3 + 5;

struct SegTree {
  struct node {
    long long max, sum, pre, suf;
    node () { max = sum = pre = suf = 0; }
  };
  int n;
  node tree[maxn * 4];

  node Unite(const node &k1, const node &k2) {
    node ret;
    ret.max = std::max(k1.suf + k2.pre, std::max(k1.max, k2.max));
    ret.sum = k1.sum + k2.sum;
    ret.pre = std::max(k1.pre, k1.sum + k2.pre);
    ret.suf = std::max(k2.suf, k2.sum + k1.suf);
    return ret;
  }

  void Pull(int o) {
    tree[o] = Unite(tree[o * 2], tree[o * 2 + 1]);
  }

  void Build(int o, int l, int r) {
    tree[o].max = tree[o].sum = tree[o].pre = tree[o].suf = 0;
    if (l == r) return;
    int m = (l + r) / 2;
    Build(o * 2, l, m);
    Build(o * 2 + 1, m + 1, r);
    Pull(o);
  }
  void Build() {
    Build(1, 1, n);
  }

  void Modify(int o, int l, int r, int idx, long long v) {
    if (l == r) {
      tree[o].max += v;
      tree[o].pre += v;
      tree[o].suf += v;
      tree[o].sum += v;
      return;
    }
    int m = (l + r) / 2;
    if (idx <= m) Modify(o * 2, l, m, idx, v);
    else Modify(o * 2 + 1, m + 1, r, idx, v);
    Pull(o);
  }
  void Modify(int idx, long long v) {
    Modify(1, 1, n, idx, v);
  }

  node Query(int o, int l, int r, int ll, int rr) {
    if (ll <= l && rr >= r) return tree[o];
    int m = (l + r) / 2;
    node k1, k2;
    if (ll <= l) k1 = Query(o * 2, l, m, ll, rr);
    if (rr > r) k1 = Query(o * 2 + 1, m + 1, r, ll, rr);
    return Unite(k1, k2);
  }
  node Query() {
    return Query(1, 1, n, 1, n);
  }
};

int t;
int n;
struct point { int x, y, c; };
point p[maxn];
int x[maxn], y[maxn];
int xsz, ysz;
std::vector<int> yele[maxn];
SegTree tree;
long long ans;

int GetX(int k) {
  return std::lower_bound(x + 1, x + xsz + 1, k) - x;
}
int GetY(int k) {
  return std::lower_bound(y + 1, y + ysz + 1, k) - y;
}

int main() {
  scanf("%d", &t);
  for (int cas = 1; cas <= t; ++cas) {
    scanf("%d", &n);
    for (int i = 1, c; i <= n; ++i) {
      scanf("%d%d%d", &x[i], &y[i], &c);
      p[i] = (point){x[i], y[i], c};
    }
    std::sort(x + 1, x + n + 1);
    xsz = std::unique(x + 1, x + n + 1) - x - 1;
    std::sort(y + 1, y + n + 1);
    ysz = std::unique(y + 1, y + n + 1) - y - 1;
    for (int i = 1; i <= ysz; ++i) yele[i].clear();
    for (int i = 1; i <= n; ++i) yele[GetY(p[i].y)].emplace_back(i);
    tree.n = xsz;
    ans = -inf;
    for (int i = 1; i <= ysz; ++i) {
      tree.Build();
      for (int j = i; j <= ysz; ++j) {
        for (int &pt : yele[j]) tree.Modify(GetX(p[pt].x), p[pt].c);
        ans = std::max(ans, tree.Query().max);
      }
    }
    printf("%lld\n", ans);
  }
  return 0;
}
