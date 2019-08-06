#include <bits/stdc++.h>
const long long inf = 1e18 + 5;
const int maxn = 1e5 + 5;

int t;
int n, m;
std::vector<int> g[maxn];
long long val[maxn];

// dfs sequence
int dfs_clock;
int in[maxn], out[maxn];
int ele[maxn];
long long dis[maxn];

void DfsSeq(int u, int prev) {
  in[u] = ++dfs_clock;
  ele[dfs_clock] = u;
  for (int &v : g[u]) {
    if (v == prev) continue;
    dis[v] = dis[u] + val[v];
    DfsSeq(v, u);
  }
  out[u] = dfs_clock;
}

// segment tree
long long max[maxn << 2], lazy[maxn << 2];

void Pull(int o) {
  max[o] = std::max(max[o << 1], max[o << 1 | 1]);
}

void Push(int o) {
  if (lazy[o] != 0) {
    lazy[o << 1] += lazy[o];
    lazy[o << 1 | 1] += lazy[o];
    max[o << 1] += lazy[o];
    max[o << 1 | 1] += lazy[o];
    lazy[o] = 0;
  }
}

void Build(int o, int l, int r) {
  max[o] = lazy[o] = 0;
  if (l == r) {
    max[o] = dis[ele[l]];
    return;
  }
  int m = (l + r) / 2;
  Build(o << 1, l, m);
  Build(o << 1 | 1, m + 1, r);
  Pull(o);
}

void Modify(int o, int l, int r, int ll, int rr, long long v) {
  if (ll <= l && rr >= r) {
    max[o] += v;
    lazy[o] += v;
    return;
  }
  int m = (l + r) / 2;
  Push(o);
  if (ll <= m) Modify(o << 1, l, m, ll, rr, v);
  if (rr > m) Modify(o << 1 | 1, m + 1, r, ll, rr, v);
  Pull(o);
}
void Modify(int ll, int rr, long long v) {
  return Modify(1, 1, n, ll, rr, v);
}

long long Query(int o, int l, int r, int ll, int rr) {
  if (ll <= l && rr >= r) return max[o];
  Push(o);
  int m = (l + r) / 2;
  long long ret = -inf;
  if (ll <= m) ret = std::max(ret, Query(o << 1, l, m, ll, rr));
  if (rr > m) ret = std::max(ret, Query(o << 1 | 1, m + 1, r, ll, rr));
  return ret;
}
long long Query(int ll, int rr) {
  return Query(1, 1, n, ll, rr);
}

int main() {
  scanf("%d", &t);
  for (int cas = 1; cas <= t; ++cas) {
    scanf("%d%d", &n, &m);
    for (int i = 0; i <= n; ++i) g[i].clear();
    for (int i = 1, u, v; i < n; ++i) {
      scanf("%d%d", &u, &v);
      g[u].push_back(v);
      g[v].push_back(u);
    }
    for (int i = 0; i < n; ++i) scanf("%lld", &val[i]);
    dis[0] = val[0];
    dfs_clock = 0;
    DfsSeq(0, -1);
    Build(1, 1, n);
    printf("Case #%d:\n", cas);
    for (int i = 1; i <= m; ++i) {
      int opt;
      scanf("%d", &opt);
      if (opt == 0) {
        int x, y;
        scanf("%d%d", &x, &y);
        Modify(in[x], out[x], y - val[x]);
        val[x] = y;
      }
      else if (opt == 1) {
        int x;
        scanf("%d", &x);
        printf("%lld\n", Query(in[x], out[x]));
      }
    }
  }
  return 0;
}