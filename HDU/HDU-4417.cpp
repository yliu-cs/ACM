#include <bits/stdc++.h>
const int maxn = 1e5 + 5;

class FuncSegTree {
  public:
    int tot;
    int rt[maxn];
    int lson[maxn << 5], rson[maxn << 5];
    int cnt[maxn << 5];

    int Build(int l, int r) {
      int t = ++tot;
      int m = (l + r) >> 1;
      if (l != r) {
        lson[t] = Build(l, m);
        rson[t] = Build(m + 1, r);
      }
      return t;
    }

    int Modify(int prev, int l, int r, int v) {
      int t = ++tot;
      lson[t] = lson[prev]; rson[t] = rson[prev];
      cnt[t] = cnt[prev] + 1;
      int m = (l + r) >> 1;
      if (l != r) {
        if (v <= m) lson[t] = Modify(lson[t], l, m, v);
        else rson[t] = Modify(rson[t], m + 1, r, v);
      }
      return t;
    }

    int Query(int u, int v, int l, int r, int k) {
      if (l == r) return l;
      int m = (l + r) >> 1;
      int num = cnt[lson[v]] - cnt[lson[u]];
      if (num >= k) return Query(lson[u], lson[v], l, m, k);
      return Query(rson[u], rson[v], m + 1, r, k - num);
    }

    int Query(int u, int v, int s, int t, int l, int r) {
      if (s <= l && t >= r) return cnt[v] - cnt[u];
      int m = (l + r) >> 1;
      int ret = 0;
      if (s <= m) ret += Query(lson[u], lson[v], s, t, l, m);
      if (t > m) ret += Query(rson[u], rson[v], s, t, m + 1, r);
      return ret;
    }
};

int t;
int n, m;
int origin[maxn];
int arr[maxn];
int size;
FuncSegTree tree;

int Get(int x) {
  return std::lower_bound(arr + 1, arr + size + 1, x) - arr;
}

int main() {
  scanf("%d", &t);
  for (int cas = 1; cas <= t; ++cas) {

    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; ++i) {
      scanf("%d", &origin[i]);
      arr[i] = origin[i];
    }

    std::sort(arr + 1, arr + n + 1);
    size = std::unique(arr + 1, arr + n + 1) - (arr + 1);

    tree.tot = 0; tree.rt[0] = tree.Build(1, size);
    for (int i = 1; i <= n; ++i) tree.rt[i] = tree.Modify(tree.rt[i - 1], 1, size, Get(origin[i]));

    printf("Case %d:\n", cas);
    for (int i = 0, l, r, h; i < m; ++i) {
      scanf("%d%d%d", &l, &r, &h);
      ++l; ++r;
      int pos = std::upper_bound(arr + 1, arr + size + 1, h) - arr;
      --pos;
      if (pos == 0) printf("%d\n", 0);
      else printf("%d\n", tree.Query(tree.rt[l - 1], tree.rt[r], 1, pos, 1, size));
    }

  }
  return 0;
}

