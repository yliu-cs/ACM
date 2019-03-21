#include <bits/stdc++.h>

int n, m;
std::vector<std::vector<int>> g;
std::vector<bool> vis;
int tot;
std::vector<int> cnt;
struct tuple {int u, v, w;};
std::vector<tuple> ans;

bool Dfs(int cur, int pre = -1) {
  std::cerr << "cur: " << cur + 1 << " pre: " << pre + 1 << '\n';
  cnt[cur] = ++tot;
  vis[cur] = true;
  int v = -1;
  for (auto it : g[cur]) {
    if (it == pre) continue;
    if (vis[it]) {
      if (cnt[it] > cnt[cur]) continue;
      if (v == -1) v = it;
      else {
        ans.emplace_back((tuple){v, cur, it});
        v = -1;
      }
    }
    else {
      if (Dfs(it, cur)) {
        if (v == -1) v = it;
        else {
          ans.emplace_back((tuple){v, cur, it});
          v = -1;
        }
      }
    }
  }
  if (v == -1) return true;
  else if (pre != -1) ans.emplace_back((tuple){v, cur, pre});
  return false;
}

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0); std::cout.tie(0);

  std::cin >> n >> m;
  g.resize(n);
  vis.assign(n, false); cnt.assign(n, 0);
  for (int i = 0, u, v; i < m; ++i) {
    std::cin >> u >> v;
    --u; --v;
    g[u].emplace_back(v);
    g[v].emplace_back(u);
  }

  for (int i = 0; i < n; ++i)
    if (!vis[i])
      Dfs(i);

  std::cout << ans.size() << '\n';
  for (auto &it : ans) std::cout << it.u + 1 << " " << it.v + 1 << " " << it.w + 1 << '\n';
  return 0;
}
