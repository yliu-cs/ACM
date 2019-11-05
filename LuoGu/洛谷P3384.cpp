#include <bits/stdc++.h>
const int maxn = 1e5 + 5;

int n, m, rt, mod;
int arr[maxn];

int fa[maxn], dep[maxn];
int sz[maxn], son[maxn];
int rk[maxn], top[maxn];
int id[maxn];
int dfs_clock;

struct edge { int v, next; };
edge g[maxn << 1];
int tot;
int head[maxn];

void AddEdge(int u, int v) {
  g[tot] = (edge){v, head[u]};
  head[u] = tot++;
}

long long sum[maxn << 2];
long long lazy[maxn << 2];

void SegTreePull(int o) { sum[o] = (sum[o << 1] + sum[o << 1 | 1]) % mod; }

void SegTreePush(int o, int l, int r) {
  int m = (l + r) >> 1;
  if (lazy[o]) {
    sum[o << 1]  = (sum[o << 1] + ((m - l + 1) * lazy[o]) % mod) % mod;
    sum[o << 1 | 1] = (sum[o << 1 | 1] + ((r - m) * lazy[o]) % mod) % mod;
    lazy[o << 1] = (lazy[o << 1] + lazy[o]) % mod;
    lazy[o << 1 | 1] = (lazy[o << 1 | 1] + lazy[o]) % mod;
    lazy[o] = 0;
  }
}

void SegTreeBuild(int o, int l, int r) {
  if (l == r) {
    sum[o] = arr[rk[l]];
    return;
  }
  int m = (l + r) >> 1;
  SegTreeBuild(o << 1, l, m);
  SegTreeBuild(o << 1 | 1, m + 1, r);
  SegTreePull(o);
}

void SegTreeModify(int o, int l, int r, int ll, int rr, long long v) {
  if (ll <= l && rr >= r) {
    sum[o] = (sum[o] + ((r - l + 1) * v) % mod) % mod;
    lazy[o] = (lazy[o] + v) % mod;
    return;
  }
  SegTreePush(o, l, r);
  int m = (l + r) >> 1;
  if (ll <= m) SegTreeModify(o << 1, l, m, ll, rr, v);
  if (rr > m) SegTreeModify(o << 1 | 1, m + 1, r, ll, rr, v);
  SegTreePull(o);
}

long long SegTreeQuery(int o, int l, int r, int ll, int rr) {
  if (ll <= l && rr >= r) return sum[o];
  SegTreePush(o, l, r);
  int m = (l + r) >> 1;
  long long ret = 0;
  if (ll <= m) ret = (ret + SegTreeQuery(o << 1, l, m, ll, rr)) % mod;
  if (rr > m) ret = (ret + SegTreeQuery(o << 1 | 1, m + 1, r, ll, rr)) % mod;
  return ret;
}

void SubDivDfs1(int u, int p, int d) {
  fa[u] = p;
  dep[u] = d;
  sz[u] = 1;
  for (int i = head[u]; ~i; i = g[i].next) {
    if (g[i].v == p) continue;
    SubDivDfs1(g[i].v, u, d + 1);
    sz[u] += sz[g[i].v];
    if (sz[g[i].v] > sz[son[u]]) son[u] = g[i].v;
  }
}

void SubDivDfs2(int u, int tp) {
  top[u] = tp;
  id[u] = ++dfs_clock;
  rk[dfs_clock] = u;
  if (!son[u]) return;
  SubDivDfs2(son[u], tp);
  for (int i = head[u]; ~i; i = g[i].next) {
    if (g[i].v == son[u] || g[i].v == fa[u]) continue;
    SubDivDfs2(g[i].v, g[i].v);
  }
}

void SubDivModify(int u, int v, int c) {
  while (top[u] != top[v]) {
    if (dep[top[u]] < dep[top[v]]) std::swap(u, v);
    SegTreeModify(1, 1, n, id[top[u]], id[u], c);
    u = fa[top[u]];
  }
  if (id[u] > id[v]) std::swap(u, v);
  SegTreeModify(1, 1, n, id[u], id[v], c);
}

long long SubDivQuery(int u, int v) {
  long long ret = 0;
  while (top[u] != top[v]) {
    if (dep[top[u]] < dep[top[v]]) std::swap(u, v);
    ret = (ret + SegTreeQuery(1, 1, n, id[top[u]], id[u])) % mod;
    u = fa[top[u]];
  }
  if (id[u] > id[v]) std::swap(u, v);
  ret = (ret + SegTreeQuery(1, 1, n, id[u], id[v])) % mod;
  return ret;
}

int main() {
  scanf("%d%d%d%d", &n, &m, &rt, &mod);
  for (int i = 1; i <= n; ++i) scanf("%d", &arr[i]);
  tot = 0;
  memset(head, -1, sizeof(head));
  for (int i = 1, u, v; i < n; ++i) {
    scanf("%d%d", &u, &v);
    AddEdge(u, v);
    AddEdge(v, u);
  }
  SubDivDfs1(rt, 0, 1);
  SubDivDfs2(rt, rt);
  SegTreeBuild(1, 1, n);
  for (int i = 1, op, u, v, c; i <= m; ++i) {
    scanf("%d", &op);
    if (op == 1) {
      scanf("%d%d%d", &u, &v, &c);
      SubDivModify(u, v, c);
    }
    else if (op == 2) {
      scanf("%d%d", &u, &v);
      printf("%lld\n", SubDivQuery(u, v));
    }
    else if (op == 3) {
      scanf("%d%d", &u, &c);
      SegTreeModify(1, 1, n, id[u], id[u] + sz[u] - 1, 1ll * c);
    }
    else if (op == 4) {
      scanf("%d", &u);
      printf("%lld\n", SegTreeQuery(1, 1, n, id[u], id[u] + sz[u] - 1));
    }
  }
  return 0;
}