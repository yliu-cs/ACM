#include <bits/stdc++.h>

struct edge {int pre, c;};
std::vector<std::vector<edge>> g;
std::vector<bool> vis;
std::vector<int> dis;

int Dfs(int u) {
  if (vis[u]) return dis[u];
  int ret = 0;
  for (auto &e : g[u]) {
    ret = std::max(ret, Dfs(e.pre) + e.c);
  }
  vis[u] = true;
  dis[u] = ret;
  return ret;
}

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr); std::cout.tie(nullptr);

  int n, m; std::cin >> n >> m;
  g.resize(n);
  for (int i = 0, u, v, c; i < m; ++i) {
    std::cin >> u >> v >> c;
    --u; --v;
    // g[u].push_back((edge){v, c});
    g[v].push_back((edge){u, c});
  }

  int ans = 0;
  vis.assign(n, false);
  dis.assign(n, 0);
  for (int i = 0; i < n; ++i) {
    if (!vis[i]) ans = std::max(ans, Dfs(i));
  }

  std::cout << ans << '\n';
  return 0;
}
