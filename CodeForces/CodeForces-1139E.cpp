#include <bits/stdc++.h>

namespace NetFlow {
  const int inf = 0x3f3f3f3f;
  int s, t;
  struct edge {int to, cap, rev;};
  std::vector<std::vector<edge>> g;
  std::vector<bool> vis;

  void Init(int n) {
    s = 0; t = n;
    g.resize(n + 1);
  }

  void AddEdge(int u, int v, int cap, int rev = 0) {
    g[u].push_back((edge){v, cap, (int)g[v].size()});
    g[v].push_back((edge){u, rev, (int)g[u].size() - 1});
  }

  int Dfs(int u, int t, int flow) {
    if (u == t) return flow;
    vis[u] = true;
    for (edge &e : g[u]) {
      if (!vis[e.to] && e.cap > 0) {
        int f = Dfs(e.to, t, std::min(e.cap, flow));
        if (f > 0) {
          e.cap -= f;
          g[e.to][e.rev].cap += f;
          return f;
        }
      }
    }
    return 0;
  }

  int GetMaxFlow(int s, int t) {
    int ans = 0;
    while (true) {
      vis.assign(t + 1, false);
      int flow = Dfs(s, t, inf);
      if (flow == 0) return ans;
      ans += flow;
    }
  }
};

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0); std::cout.tie(0);

  int n, m; std::cin >> n >> m;
  std::vector<int> p(n, 0), c(n, 0);
  std::vector<std::vector<int>> cnt(5005);
  for (int i = 0; i < n; ++i) std::cin >> p[i];
  for (int i = 0; i < n; ++i) {
    std::cin >> c[i];
    --c[i];
  }
  int d; std::cin >> d;
  std::vector<int> q(d);
  std::vector<bool> del(n, false);
  for (int i = 0; i < d; ++i) {
    std::cin >> q[i];
    --q[i];
    del[q[i]] = true;
  }

  int s = m + 5005, t = s + 1;
  NetFlow::Init(t);
  for (int i = 0; i < m; ++i) NetFlow::AddEdge(s, i, 1);
  for (int i = 0; i < n; ++i)
    if (!del[i]) NetFlow::AddEdge(c[i], m + p[i], 1);

  std::vector<int> ans(d);
  int cur_mx = -1, cur_match = 0;
  for (int i = d - 1; i >= 0; --i) {
    while (cur_mx < 5001 && cur_match == cur_mx + 1) {
      ++cur_mx;
      NetFlow::AddEdge(m + cur_mx, t, 1);
      cur_match += NetFlow::GetMaxFlow(s, t);
    }
    ans[i] = cur_mx;
    NetFlow::AddEdge(c[q[i]], m + p[q[i]], 1);
    cur_match += NetFlow::GetMaxFlow(s, t);
  }

  for (int i = 0; i < d; ++i) std::cout << ans[i] << '\n';
  return 0;
}
