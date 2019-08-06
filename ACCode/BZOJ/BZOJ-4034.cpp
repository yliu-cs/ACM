#include <bits/stdc++.h>
const int maxn = 1e5 + 5;

struct edge { int v, next; };
edge g[maxn << 1];
int tot;
int head[maxn];

void AddEdge(int u, int v) {
  g[tot] = (edge){v, head[u]};
  head[u] = tot++;
  g[tot] = (edge){u, head[v]};
  head[v] = tot++;
}

int n;
long long val[maxn];

int fa[maxn], dep[maxn];
int sz[maxn], son[maxn];
int rk[maxn], top[maxn];
int id[maxn];
int dfs_clock;

long long sum[maxn << 2], lazy[maxn << 2];

void SegTreePull(int o) {
  sum[o] = sum[o << 1] + sum[o << 1 | 1];
}

void SegTreePush(int o, int l, int r) {
  int m = (l + r) / 2;
  if (lazy[o] != 0) {
    sum[o << 1] += (m - l + 1) * lazy[o];
    sum[o << 1 | 1] += (r - m) * lazy[o];
    lazy[o << 1] += lazy[o];
    lazy[o << 1 | 1] += lazy[o];
    lazy[o] = 0;
  }
}

void SegTreeBuild(int o, int l, int r) {
  sum[o] = lazy[o] = 0;
  if (l == r) {
    sum[o] = val[rk[l]];
    return;
  }
  int m = (l + r) / 2;
  SegTreeBuild(o << 1, l, m);
  SegTreeBuild(o << 1 | 1, m + 1, r);
  SegTreePull(o);
}

void SegTreeModify(int o, int l, int r, int ll, int rr, long long v) {
  if (ll <= l && rr >= r) {
    sum[o] += (r - l + 1) * v;
    lazy[o] += v;
    return;
  }
  SegTreePush(o, l, r);
  int m = (l + r) / 2;
  if (ll <= m) SegTreeModify(o << 1, l, m, ll, rr, v);
  if (rr > m) SegTreeModify(o << 1 | 1, m + 1, r, ll, rr, v);
  SegTreePull(o);
}

long long SegTreeQuery(int o, int l, int r, int ll, int rr) {
  if (ll <= l && rr >= r) return sum[o];
  SegTreePush(o, l, r);
  int m = (l + r) / 2;
  long long ret = 0;
  if (ll <= m) ret += SegTreeQuery(o << 1, l, m, ll, rr);
  if (rr > m) ret += SegTreeQuery(o << 1 | 1, m + 1, r, ll, rr);
  return ret;
}

void TreeSplitDfs1(int u, int prev, int depth) {
  fa[u] = prev;
  dep[u] = depth;
  sz[u] = 1;
  for (int i = head[u]; ~i; i = g[i].next) {
    int v = g[i].v;
    if (v == prev) continue;
    TreeSplitDfs1(v, u, depth + 1);
    sz[u] += sz[v];
    if (sz[v] > sz[son[u]]) son[u] = v;
  }
}

void TreeSplitDfs2(int u, int tp) {
  top[u] = tp;
  id[u] = ++dfs_clock;
  rk[dfs_clock] = u;
  if (!son[u]) return;
  TreeSplitDfs2(son[u], tp);
  for (int i = head[u]; ~i; i = g[i].next) {
    int v = g[i].v;
    if (v == son[u] || v == fa[u]) continue;
    TreeSplitDfs2(v, v);
  }
}

long long TreeSplitQuery(int u, int v) {
  long long ret = 0;
  while (top[u] != top[v]) {
    if (dep[top[u]] < dep[top[v]]) std::swap(u, v);
    ret += SegTreeQuery(1, 1, n, id[top[u]], id[u]);
    u = fa[top[u]];
  }
  if (id[u] > id[v]) std::swap(u, v);
  ret += SegTreeQuery(1, 1, n, id[u], id[v]);
  return ret;
}

int main() {
  int m;
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; ++i) scanf("%lld", &val[i]);
  memset(head, -1, sizeof(head));
  for (int i = 1, u, v; i < n; ++i) {
    scanf("%d%d", &u, &v);
    AddEdge(u, v);
  }
  TreeSplitDfs1(1, 0, 1);
  TreeSplitDfs2(1, 1);
  SegTreeBuild(1, 1, n);
  for (int i = 1; i <= m; ++i) {
    int opt;
    scanf("%d", &opt);
    if (opt == 1) {
      int x, a;
      scanf("%d%d", &x, &a);
      SegTreeModify(1, 1, n, id[x], id[x], a);
    }
    else if (opt == 2) {
      int x, a;
      scanf("%d%d", &x, &a);
      SegTreeModify(1, 1, n, id[x], id[x] + sz[x] - 1, a);
    }
    else if (opt == 3) {
      int x;
      scanf("%d", &x);
      printf("%lld\n", TreeSplitQuery(x, 1));
    }
  }
  return 0;
}