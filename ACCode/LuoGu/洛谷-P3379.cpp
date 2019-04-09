#include <bits/stdc++.h>
const int maxn = (int)5e5 + 5;

namespace LCA {
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
}

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr); std::cout.tie(nullptr);

  int n, m, s; std::cin >> n >> m >> s;
  LCA::n = n; LCA::k = log2(n) + 1;

  for (int i = 1, u, v; i < n; ++i) {
    std::cin >> u >> v;
    LCA::AddEdge(u, v);
  }

  LCA::Init(s);

  for (int i = 0, u, v; i < m; ++i) {
    std::cin >> u >> v;
    std::cout << LCA::Query(u, v) << '\n';
  }
  return 0;
}
