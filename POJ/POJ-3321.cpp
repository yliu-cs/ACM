#include <cstdio>
#include <iostream>
#include <cstring>
const int maxn = 1e5 + 5;

int tree[maxn << 2];

void Pull(int o) { tree[o] = tree[o << 1] + tree[o << 1 | 1]; }

void Build(int o, int l, int r) {
  if (l == r) {
    tree[o] = 1;
    return;
  }
  int m = (l + r) >> 1;
  Build(o << 1, l, m);
  Build(o << 1 | 1, m + 1, r);
  Pull(o);
}

void Modify(int o, int l, int r, int idx) {
  if (l == r) {
    tree[o] ^= 1;
    return;
  }
  int m = (l + r) >> 1;
  if (idx <= m) Modify(o << 1, l, m, idx);
  if (idx > m) Modify(o << 1 | 1, m + 1, r, idx);
  Pull(o);
}

int Query(int o, int l, int r, int ll, int rr) {
  if (ll <= l && rr >= r) return tree[o];
  int m = (l + r) >> 1;
  int ret = 0;
  if (ll <= m) ret += Query(o << 1, l, m, ll, rr);
  if (rr > m) ret += Query(o << 1 | 1, m + 1, r, ll, rr);
  return ret;
}

struct edge { int v, next; };
edge g[maxn << 1];
int head[maxn];
int tot;

void AddEdge(int u, int v) {
  g[tot] = (edge){v, head[u]};
  head[u] = tot++;
}

int n, m;
int in[maxn], out[maxn];
int dfs_clock;

void Dfs(int u, int p) {
  in[u] = ++dfs_clock;
  for (int i = head[u]; ~i; i = g[i].next) {
    if (g[i].v == p) continue;
    Dfs(g[i].v, u);
  }
  out[u] = dfs_clock;
}

int main() {
  scanf("%d", &n);
  memset(head, -1, sizeof(head));
  for (int i = 1, u, v; i < n; ++i) {
    scanf("%d%d", &u, &v);
    AddEdge(u, v);
    AddEdge(v, u);
  }
  Build(1, 1, n);
  Dfs(1, 0);
  scanf("%d", &m);
  for (int i = 1, x; i <= m; ++i) {
    getchar();
    char op;
    scanf("%c%d", &op, &x);
    if (op == 'Q') {
      printf("%d\n", Query(1, 1, n, in[x], out[x]));
    }
    else if (op == 'C') {
      Modify(1, 1, n, in[x]);
    }
  }
  return 0;
}