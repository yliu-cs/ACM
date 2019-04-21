#include <bits/stdc++.h>
const int maxn = 1e5 + 5;

int n, m, r, p;
int arr[maxn];

int fa[maxn], dep[maxn];
int sz[maxn], son[maxn];
int rk[maxn], top[maxn];
int id[maxn];
int dfs_clock;

/*---Graph---*/
struct edge {int v, next;};
edge g[maxn << 1];
int tot;
int head[maxn];

void AddEdge(int u, int v) {
  g[tot] = (edge){v, head[u]};
  head[u] = tot++;
}

/*---SegTree---*/
long long sum[maxn << 2], lazy[maxn << 2];

void Pull(int o) {
  sum[o] = (sum[o << 1] + sum[o << 1 | 1]) % p;
}

void Push(int o, int l, int r) {
  int m = (l + r) / 2;
  if (lazy[o]) {
    sum[o << 1] = (sum[o << 1] + ((m - l + 1) * lazy[o]) % p) % p;
    sum[o << 1 | 1] = (sum[o << 1 | 1] + ((r - m) * lazy[o]) % p) % p;
    lazy[o << 1] = (lazy[o << 1] + lazy[o]) % p;
    lazy[o << 1 | 1] = (lazy[o << 1 | 1] + lazy[o]) % p;
    lazy[o] = 0;
  }
}

void Build(int o, int l, int r) {
  if (l == r) {
    sum[o] = arr[rk[l]];
    return;
  }
  int m = (l + r) / 2;
  Build(o << 1, l, m);
  Build(o << 1 | 1, m + 1, r);
  Pull(o);
}

void SegTreeModify(int o, int l, int r, int ll, int rr, long long v) {
  if (ll <= l && rr >= r) {
    sum[o] = (sum[o] + ((r - l + 1) * v) % p) % p;
    lazy[o] = (lazy[o] + v) % p;
    return;
  }
  Push(o, l, r);
  int m = (l + r) / 2;
  if (ll <= m) SegTreeModify(o << 1, l, m, ll, rr, v);
  if (rr > m) SegTreeModify(o << 1 | 1, m + 1, r, ll, rr, v);
  Pull(o);
}

long long SegTreeQuery(int o, int l, int r, int ll, int rr) {
  if (ll <= l && rr >= r) return sum[o];
  Push(o, l, r);
  int m = (l + r) / 2;
  long long ret = 0;
  if (ll <= m) ret = (ret + SegTreeQuery(o << 1, l, m, ll, rr)) % p;
  if (rr > m) ret = (ret + SegTreeQuery(o << 1 | 1, m + 1, r, ll, rr)) % p;
  return ret;
}

/*---TreeSplit---*/
void Dfs1(int u, int p, int d) {
  fa[u] = p; dep[u] = d; sz[u] = 1;
  for (int i = head[u]; ~i; i = g[i].next) {
    int v = g[i].v;
    if (v == p) continue;
    Dfs1(v, u, d + 1);
    sz[u] += sz[v];
    if (sz[v] > sz[son[u]]) son[u] = v;
  }
}

void Dfs2(int u, int tp) {
  top[u] = tp; id[u] = ++dfs_clock;
  rk[dfs_clock] = u;
  if (!son[u]) return;
  Dfs2(son[u], tp);
  for (int i = head[u]; ~i; i = g[i].next) {
    int v = g[i].v;
    if (v == son[u] || v == fa[u]) continue;
    Dfs2(v, v);
  }
}

long long TreeSplitQuery(int u, int v) {
  long long ret = 0;
  while (top[u] != top[v]) {
    if (dep[top[u]] < dep[top[v]]) std::swap(u, v);
    ret = (ret + SegTreeQuery(1, 1, n, id[top[u]], id[u])) % p;
    u = fa[top[u]];
  }
  if (id[u] > id[v]) std::swap(u, v);
  ret = (ret + SegTreeQuery(1, 1, n, id[u], id[v])) % p;
  return ret;
}

void TreeSplitModify(int u, int v, int c) {
  while (top[u] != top[v]) {
    if (dep[top[u]] < dep[top[v]]) std::swap(u, v);
    SegTreeModify(1, 1, n, id[top[u]], id[u], c);
    u = fa[top[u]];
  }
  if (id[u] > id[v]) std::swap(u, v);
  SegTreeModify(1, 1, n, id[u], id[v], c);
}

int main() {
  scanf("%d%d%d%d", &n, &m, &r, &p);
  for (int i = 1; i <= n; ++i) scanf("%d", &arr[i]);
  tot = 0; memset(head, -1, sizeof(head));
  for (int i = 1, u, v; i < n; ++i) {
    scanf("%d%d", &u, &v);
    AddEdge(u, v); AddEdge(v, u);
  }
  Dfs1(r, 0, 1);
  Dfs2(r, r);
  Build(1, 1, n);
  for (int i = 0, op; i < m; ++i) {
    scanf("%d", &op);
    if (op == 1) {
      int u, v, c; scanf("%d%d%d", &u, &v, &c);
      TreeSplitModify(u, v, c);
    }
    else if (op == 2) {
      int u, v; scanf("%d%d", &u, &v);
      printf("%lld\n", TreeSplitQuery(u, v));
    }
    else if (op == 3) {
      int u, c; scanf("%d%d", &u, &c);
      SegTreeModify(1, 1, n, id[u], id[u] + sz[u] - 1, c);
    }
    else if (op == 4) {
      int u; scanf("%d", &u);
      printf("%lld\n", SegTreeQuery(1, 1, n, id[u], id[u] + sz[u] - 1));
    }
  }
  return 0;
}

