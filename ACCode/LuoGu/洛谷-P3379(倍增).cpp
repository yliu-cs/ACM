// luogu-judger-enable-o2
#include <bits/stdc++.h>
const int maxn = 5e5 + 5;
const int maxlog = 25;

int n, q, rt;
int k;
std::vector<int> g[maxn];
int anc[maxn][maxlog];
int dep[maxn];

void Dfs(int u, int p, int d) {
  anc[u][0] = p;
  dep[u] = d;
  for (int &v : g[u]) {
    if (v == p) continue;
    Dfs(v, u, d + 1);
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
  scanf("%d%d%d", &n, &q, &rt);
  k = log2(n) + 1;
  for (int i = 1, u, v; i < n; ++i) {
    scanf("%d%d", &u, &v);
    g[u].push_back(v);
    g[v].push_back(u);
  }
  Dfs(rt, 0, 1);
  for (int j = 1; j < k; ++j) {
    for (int i = 1; i <= n; ++i) {
      anc[i][j] = anc[anc[i][j - 1]][j - 1];
    }
  }
  for (int i = 1, u, v; i <= q; ++i) {
    scanf("%d%d", &u, &v);
    printf("%d\n", GetLCA(u, v));
  }
  return 0;
}