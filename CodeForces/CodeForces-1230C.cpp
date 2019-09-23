#include <bits/stdc++.h>
const int maxn = 10;
int n, m;
std::vector<std::pair<int, int>> edge;
int code[maxn];
bool used[maxn][maxn];
int ans;
int Count() {
  int ret = 0;
  memset(used, false, sizeof(used));
  for (auto &e : edge) {
    int u = code[e.first], v = code[e.second];
    if (used[u][v] || used[v][u]) continue;
    ++ret;
    used[u][v] = used[v][u] = true;
  }
  return ret;
}
void Dfs(int pos) {
  if (pos > n) {
    ans = std::max(ans, Count());
    return;
  }
  for (int i = 1; i <= std::min(n, 6); ++i) {
    code[pos] = i;
    Dfs(pos + 1);
  }
}
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.setf(std::ios::fixed);
  std::cout.precision(15);
  std::cin >> n >> m;
  for (int i = 1, u, v; i <= m; ++i) {
    std::cin >> u >> v;
    edge.push_back({u, v});
  }
  Dfs(1);
  std::cout << ans << '\n';
  return 0;
}

