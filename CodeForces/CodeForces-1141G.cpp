#include <bits/stdc++.h>

int n, k;
std::vector<std::vector<int>> g;
std::map<std::pair<int, int>, int> id;
int ans;
std::vector<int> col;

void Dfs(int cur, int pre, int ban) {
  int color = 0;
  for (auto v : g[cur]) {
    if (v == pre) continue;
    if (color == ban) {
      color = (color + 1) % ans;
      ban = -1;
    }
    col[id[{cur, v}]] = color;
    Dfs(v, cur, color);
    color = (color + 1) % ans;
  }
}

int main() {
  std::ios::sync_with_stdio(false); std::cin.tie(0);

  std::cin >> n >> k;
  g.resize(n);
  std::vector<int> deg(n, 0);
  for (int i = 0, u, v; i < n - 1; ++i) {
    std::cin >> u >> v;
    --u; --v;
    g[u].emplace_back(v);
    g[v].emplace_back(u);
    ++deg[u]; ++deg[v];
    id[{u, v}] = i; id[{v, u}] = i;
  }

  std::map<int, int> deg_cnt;
  for (auto &it : deg) deg_cnt[it]++;
  int cnt = n;
  for (auto &it : deg_cnt) {
    if (cnt > k) {
      ans = it.first;
      cnt -= it.second;
    }
    else break;
  }

  col.resize(n - 1);
  Dfs(0, -1, -1);

  std::cout << ans << '\n';
  for (auto &it : col) std::cout << it + 1 << " ";
  return 0;
}
