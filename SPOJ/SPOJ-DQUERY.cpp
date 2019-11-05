#include <bits/stdc++.h>
const int maxn = 3e4 + 5;
const int maxa = 1e6 + 5;

struct FuncSegTree {
  int tot;
  int rt[maxn];
  int lson[maxn << 5], rson[maxn << 5];
  int cnt[maxn << 5];

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

FuncSegTree tree;

int n;
int arr[maxn];
int q;
int last[maxa];

int main() {
  scanf("%d", &n);
  tree.rt[0] = tree.Build(1, n);
  for (int i = 1; i <= n; ++i) {
    scanf("%d", &arr[i]);
    tree.rt[i] = tree.Modify(tree.rt[i - 1], 1, n, last[arr[i]] + 1);
    last[arr[i]] = i;
  }
  scanf("%d", &q);
  for (int i = 1, l, r; i <= q; ++i) {
    scanf("%d%d", &l, &r);
    printf("%d\n", tree.Query(tree.rt[l - 1], tree.rt[r], 1, l, 1, n));
  }
  return 0;
}

