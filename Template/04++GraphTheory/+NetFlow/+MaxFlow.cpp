const int inf = "Edit";
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

