const int maxn = "Edit";

int n, k;
std::vector<int> g[maxn];

void AddEdge(int u, int v) {
  g[u].push_back(v);
  g[v].push_back(u);
}

int anc[maxn][25];
int dep[maxn];

void Dfs(int u, int prev, int depth) {
  anc[u][0] = prev; dep[u] = depth;
  for (auto &v : g[u]) {
    if (v == prev) continue;
    Dfs(v, u, depth + 1);
  }
}

void Init(int rt) {
  Dfs(rt, 0, 1);
  for (int j = 1; j < k; ++j) {
    for (int i = 1; i <= n; ++i) {
      anc[i][j] = anc[anc[i][j - 1]][j - 1];
    }
  }
}

void Swim(int &u, int h) {
  for (int i = 0; h > 0; ++i) {
    if (h & 1) u = anc[u][i];
    h >>= 1;
  }
}

int Query(int u, int v) {
  if (dep[u] < dep[v]) std::swap(u, v);
  Swim(u, dep[u] - dep[v]);
  if (u == v) return u;
  for (int i = k - 1; i >= 0; --i) {
    if (anc[u][i] != anc[v][i]) {
      u = anc[u][i];
      v = anc[v][i];
    }
  }
  return anc[u][0];
}
