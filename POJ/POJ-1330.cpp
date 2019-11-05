#include <iostream>
#include <cstdio>
#include <cmath>
const int maxn = 1e5 + 5;
const int maxlog = 25;

struct edge { int v, next; };
edge g[maxn << 1];
int tot;
int head[maxn];

void AddEdge(int u, int v) {
  g[tot] = (edge){v, head[u]};
  head[u] = tot++;
}

int n, k;
bool vis[maxn];
int anc[maxn][maxlog];
int dep[maxn];

void Dfs(int u, int prev, int depth) {
  anc[u][0] = prev;
  dep[u] = depth;
  for (int i = head[u]; ~i; i = g[i].next) {
    int v = g[i].v;
    if (v == prev) continue;
    Dfs(v, u, depth + 1);
  }
}

void Swim(int &u, int h) {
  for (int i = 0; h > 0; ++i) {
    if (h & 1) u = anc[u][i];
    h >>= 1;
  }
}

int GetLCA(int u, int v) {
  if (dep[u] < dep[v]) std::swap(u, v);
  Swim(u, dep[u] - dep[v]);
  if (u == v) return v;
  for (int i = k - 1; i >= 0; --i) {
    if (anc[u][i] != anc[v][i]) {
      u = anc[u][i];
      v = anc[v][i];
    }
  }
  return anc[u][0];
}

int main() {
  int t;
  scanf("%d", &t);
  for (int cas = 1; cas <= t; ++cas) {
    scanf("%d", &n);
    k = log2(n) + 1;
    tot = 0;
    for (int i = 1; i <= n; ++i) {
      head[i] = -1;
      vis[i] = false;
    }
    for (int i = 1, u, v; i < n; ++i) {
      scanf("%d%d", &u, &v);
      AddEdge(u, v);
      vis[v] = true;
    }
    int rt;
    for (int i = 1; i <= n; ++i) {
      if (!vis[i]) {
        rt = i;
        break;
      }
    }
    Dfs(rt, 0, 1);
    for (int j = 1; j < k; ++j)
      for (int i = 1; i <= n; ++i)
        anc[i][j] = anc[anc[i][j - 1]][j - 1];
    int u, v;
    scanf("%d%d", &u, &v);
    printf("%d\n", GetLCA(u, v));
  }
  return 0;
}