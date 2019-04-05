const int inf = "Edit";
const int maxn = "Edit";

int n, e;
bool vis[maxn];
int g[maxn][maxn];

// Dfs搜索增广路经，u:当前搜索顶点，t:搜索终点，now_flow:当前最大流量
int Dfs(int u, int t, int now_flow) {
  if (u == t) return now_flow;
  vis[u] = true;
  for (int i = 1; i <= n; ++i) {
    if (!vis[i] && g[u][i]) {
      int FindFlow = Dfs(i, t, now_flow < g[u][i] ? now_flow : g[u][i]);
      if (!FindFlow) continue;
      g[u][i] -= FindFlow;
      g[i][u] += FindFlow;
      return FindFlow;
    }
  }
  return false;
}

// Ford-Fulkersone算法，s:起点，t:终点
int FordFulkerson(int s, int t) {
  int max_flow = 0, Flow = 0;
  memset(vis, false, sizeof(vis));
  while (Flow = Dfs(s, t, inf)) {
    max_flow += Flow;
    memset(vis, false, sizeof(vis));
  }
  return max_flow;
}

