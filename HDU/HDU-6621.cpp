#include <bits/stdc++.h>
const int maxn = 1e5 + 5;

struct PresidentTree {
  int tot;
  int rt[maxn];
  int lson[maxn * 40], rson[maxn * 40];
  int cnt[maxn * 40];

  int Build(int l, int r) {
    int o = ++tot, m = (l + r) >> 1;
    cnt[o] = 0;
    if (l != r) {
      lson[o] = Build(l, m);
      rson[o] = Build(m + 1, r);
    }
    return o;
  }

  int Modify(int prev, int l, int r, int v) {
    int o = ++tot, m = (l + r) >> 1;
    lson[o] = lson[prev];
    rson[o] = rson[prev];
    cnt[o] = cnt[prev] + 1;
    if (l != r) {
      if (v <= m) lson[o] = Modify(lson[o], l, m, v);
      else rson[o] = Modify(rson[o], m + 1, r, v);
    }
    return o;
  }

  int Query(int u, int v, int s, int t, int l, int r) {
    if (s <= l && t >= r) return cnt[v] - cnt[u];
    int m = (l + r) >> 1, ret = 0;
    if (s <= m) ret += Query(lson[u], lson[v], s, t, l, m);
    if (t > m) ret += Query(rson[u], rson[v], s, t, m + 1, r);
    return ret;
  }
};

int t;
int n, m;
int a[maxn];
int arr[maxn];
int sz;
PresidentTree tree;
int lastans, ans;

int GetLower(int x) {
  return std::lower_bound(arr + 1, arr + sz + 1, x) - arr;
}

int GetUpper(int x) {
  return std::upper_bound(arr + 1, arr + sz + 1, x) - arr;
}

int main() {
  scanf("%d", &t);
  for (int cas = 1; cas <= t; ++cas) {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; ++i) {
      scanf("%d", &a[i]);
      arr[i] = a[i];
    }
    std::sort(arr + 1, arr + n + 1);
    sz = std::unique(arr + 1, arr + n + 1) - arr - 1;
    tree.tot = 0;
    tree.rt[0] = tree.Build(1, n);
    for (int i = 1; i <= n; ++i) tree.rt[i] = tree.Modify(tree.rt[i - 1], 1, sz, GetLower(a[i]));
    lastans = ans = 0;
    for (int i = 1; i <= m; ++i) {
      int l, r, p, k;
      scanf("%d%d%d%d", &l, &r, &p, &k);
      l ^= lastans;
      r ^= lastans;
      p ^= lastans;
      k ^= lastans;
      int bl = 0, br = (int)(1e6 + 5);
      while (bl <= br) {
        int bm = (bl + br) / 2;
        int ll = GetLower(p - bm), rr = GetUpper(p + bm) - 1;
        if (tree.Query(tree.rt[l - 1], tree.rt[r], ll, rr, 1, n) >= k) {
          ans = bm;
          br = bm - 1;
        }
        else bl = bm + 1;
      }
      printf("%d\n", ans);
      lastans = ans;
    }
  }
  return 0;
}