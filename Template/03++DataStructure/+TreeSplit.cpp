const int maxn = "Edit";

int n;
int arr[maxn];

int fa[maxn], dep[maxn];
int sz[maxn], son[maxn];
int rk[maxn], top[maxn];
int id[maxn];
int dfs_clock;

struct edge {int v, next;};
edge g[maxn << 1];
int tot;
int head[maxn];

void AddEdge(int u, int v) {
  g[tot] = (edge){v, head[u]};
  head[u] = tot++;
}

long long sum[maxn << 2];
long long lazy[maxn << 2];

void SegTreePull(int o) {
  sum[o] = sum[o << 1] + sum[o << 1 | 1];
}

void SegTreePush(int o, int l, int r) {
  int m = (l + r) >> 1;
  if (lazy[o] != 0) {
    sum[o << 1] += (m - l + 1) * lazy[o];
    sum[o << 1 | 1] += (r - m) * lazy[o];
    lazy[o << 1] += lazy[o];
    lazy[o << 1 | 1] += lazy[o];
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
    sum[o] += (r - l + 1) * v;
    lazy[o] += v;
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
  if (ll <= m) ret += SegTreeQuery(o << 1, l, m, ll, rr);
  if (rr > m) ret += SegTreeQuery(o << 1 | 1, m + 1, r, ll, rr);
  return ret;
}

void TreeSplitDfs1(int u, int p, int d) {
  fa[u] = p; dep[u] = d; sz[u] = 1;
  for (int i = head[u]; ~i; i = g[i].next) {
    int v = g[i].v;
    if (v == p) continue;
    TreeSplitDfs1(v, u, d + 1);
    sz[u] += sz[v];
    if (sz[v] > sz[son[u]]) son[u] = v;
  }
}

void TreeSplitDfs2(int u, int tp) {
  top[u] = tp; id[u] = ++dfs_clock;
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

void TreeSplitModify(int u, int v, int c) {
  while (top[u] != top[v]) {
    if (dep[top[u]] < dep[top[v]]) std::swap(u, v);
    SegTreeModify(1, 1, n, id[top[u]], id[u], c);
    u = fa[top[u]];
  }
  if (id[u] > id[v]) std::swap(u, v);
  SegTreeModify(1, 1, n, id[u], id[v], c);
}
