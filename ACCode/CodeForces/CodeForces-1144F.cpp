#include <bits/stdc++.h>

std::vector<std::vector<int>> g;
std::vector<std::pair<int, int>> e;
std::vector<int> color;
bool flag;

void Dfs(int u, int col) {
  color[u] = col;
  for (auto &v : g[u]) {
    if (color[v] == -1) Dfs(v, !col);
    else if (color[v] == color[u]) flag = false;
  }
}

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr); std::cout.tie(nullptr);

  int n, m; std::cin >> n >> m;
  g.resize(n);
  for (int i = 0, u, v; i < m; ++i) {
    std::cin >> u >> v;
    --u; --v;
    g[u].emplace_back(v);
    g[v].emplace_back(u);
    e.push_back({u, v});
  }

  flag = true;
  color.assign(n, -1);

  Dfs(0, 0);

  if (!flag) {
    std::cout << "NO" << '\n';
    return 0;
  }
  std::cout << "YES" << '\n';
  for (int i = 0; i < m; ++i) std::cout << (color[e[i].first] < color[e[i].second]);
  std::cout << '\n';

  return 0;
}
