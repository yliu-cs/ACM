// Author: Tonyst4rk Time: 2019-10-29 16:07:53
#include <bits/stdc++.h>

const int N = 2e5 + 5;

int tot, rt[N], lson[N * 40], rson[N * 40], cnt[N * 40];
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
  lson[o] = lson[p]; rson[o] = rson[p];
  cnt[o] = cnt[p] + 1;
  if (l != r) {
    if (v <= m) lson[o] = Modify(lson[o], l, m, v);
    else rson[o] = Modify(rson[o], m + 1, r, v);
  }
  return o;
}
int Query(int u, int v, int s, int t, int l, int r) {
  if (s <= l && t >= r) return cnt[v] - cnt[u];
  int m = (l + r) / 2, ret = 0;
  if (s <= m) ret += Query(lson[u], lson[v], s, t, l, m);
  if (t > m) ret += Query(rson[u], rson[v], s, t, m + 1, r);
  return ret;
}

int n;
int l[N], w[N];
int sz, arr[N];
int id[N];
long long ans;

int Get(int x) {
  return std::lower_bound(arr + 1, arr + sz + 1, x) - arr;
}

int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i) {
    scanf("%d%d", &l[i], &w[i]);
    if (l[i] > w[i]) std::swap(l[i], w[i]);
    arr[++sz] = l[i]; arr[++sz] = w[i];
    ans = std::max(ans, 1ll * l[i] * w[i]);
  }
  std::sort(arr + 1, arr + sz + 1);
  sz = std::unique(arr + 1, arr + sz + 1) - arr - 1;
  for (int i = 1; i <= n; ++i) id[i] = i;
  std::sort(id + 1, id + n + 1,
    [&](const int k1, const int k2) {
      if (l[k1] == l[k2]) return w[k1] < w[k2];
      return l[k1] < l[k2];
    }
  );
  rt[0] = Build(1, sz);
  for (int i = 1; i <= n; ++i) rt[i] = Modify(rt[i - 1], 1, sz, Get(w[id[i]]));
  for (int i = 1; i < n; ++i) {
    int bl = 1, br = w[id[i]], bans;
    while (bl <= br) {
      int bm = (bl + br) / 2;
      if (Query(rt[i], rt[n], Get(bm), sz, 1, sz) > 0) {
        bans = bm;
        bl = bm + 1;
      }
      else br = bm - 1;
    }
    ans = std::max(ans, 1ll * l[id[i]] * bans * 2);
  }
  if (ans & 1) printf("%lld.5\n", ans / 2);
  else printf("%lld.0\n", ans / 2);
  return 0;
}

