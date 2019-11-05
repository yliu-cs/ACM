#include <bits/stdc++.h>
const long long inf = 1e18 + 5;
const int maxn = 1e5 + 5;

struct SegTree {
  long long sum[maxn * 4], cnt[maxn * 4];
  void Pull(int o) {
    sum[o] = sum[o * 2] + sum[o * 2 + 1];
    cnt[o] = cnt[o * 2] + cnt[o * 2 + 1];
  }
  void Build(int o, int l, int r) {
    sum[o] = cnt[o] = 0;
    if (l == r) return;
    int m = (l + r) / 2;
    Build(o * 2, l, m);
    Build(o * 2 + 1, m + 1, r);
    Pull(o);
  }
  void Build() {
    Build(1, 1, 400);
  }
  void Modify(int o, int l, int r, int pos, long long v) {
    if (l == r) {
      sum[o] += 1ll * pos * v;
      cnt[o] += v;
      return;
    }
    int m = (l + r) / 2;
    if (pos <= m) Modify(o * 2, l, m, pos, v);
    if (pos > m) Modify(o * 2 + 1, m + 1, r, pos, v);
    Pull(o);
  }
  void Modify(int pos, long long v) {
    Modify(1, 1, 400, pos, v);
  }
  long long Query(int o, int l, int r, long long v) {
    if (l == r) return 1ll * std::min(v, cnt[o]) * l;
    int m = (l + r) / 2;
    if (v == cnt[o * 2]) return sum[o * 2];
    if (v < cnt[o * 2]) return Query(o * 2, l, m, v);
    else return sum[o * 2] + Query(o * 2 + 1, m + 1, r, v - cnt[o * 2]);
  }
  long long Query(long long v) {
    return Query(1, 1, 400, v);
  }
};

int n;
struct tree {
  long long h, c, p;
  tree() { h = c = p = 0; }
};
tree t[maxn];
long long h[maxn];
long long hsz;
SegTree T;
long long ans;
long long suf[maxn];

int main() {
  while (~scanf("%d", &n)) {
    T.Build();
    for (int i = 1; i <= n; ++i) {
      scanf("%lld%lld%lld", &t[i].h, &t[i].c, &t[i].p);
      h[i] = t[i].h;
      T.Modify(t[i].c, t[i].p);
    }
    std::sort(h + 1, h + n + 1);
    hsz = std::unique(h + 1, h + n + 1) - h - 1;
    for (int i = 1; i <= n; ++i) t[i].h = std::lower_bound(h + 1, h + hsz + 1, t[i].h) - h;
    std::sort(t + 1, t + n + 1, [&](const tree &k1, const tree &k2) {
      if (k1.h == k2.h) return k1.c > k2.c;
      return k1.h > k2.h;
    });
    suf[n + 1] = 0;
    for (int i = n; i >= 1; --i) suf[i] = suf[i + 1] + t[i].p;
    long long idx = 1, pref = 0;
    ans = inf;
    for (int i = hsz; i >= 1; --i) {
      long long cnt = 0, sum = 0;
      while (t[idx].h == i && idx <= n) {
        T.Modify(t[idx].c, -t[idx].p);
        sum += t[idx].c * t[idx].p;
        cnt += t[idx].p;
        ++idx;
      }
      long long del = std::max(0ll, suf[idx] - cnt + 1);
      ans = std::min(ans, pref + T.Query(del));
      pref += sum;
    }
    printf("%lld\n", ans);
  }
  return 0;
}
