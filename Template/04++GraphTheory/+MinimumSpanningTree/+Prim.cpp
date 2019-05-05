const int inf = "Edit";
const int maxn = "Edit";

int n;
int dis[maxn];
int vis[maxn];
struct edge { int v, dis; };
std::vector<edge> g[maxn];

void AddEdge(int u, int v, int c) {
  g[u].push_back((edge){v, c});
  g[v].push_back((edge){u, c});
}

// Prim算法
int Prim(int s) {
  memset(dis, inf, sizeof(dis));
  memset(vis, 0, sizeof(vis));
  dis[s] = 0;
  int ret = 0;
  for (int i = 1; i <= n; ++i) {
    int u = -1, min = inf;
    for (int j = 1; j <= n; ++j) {
      if (!vis[j] && dis[j] < min) {
        u = j;
        min = dis[j];
      }
    }
    vis[u] = 1;
    ret += min;
    for (int j = 0; j < int(g[u].size()); ++j) {
      int v = g[u][j].v;
      if (!vis[v] && g[u][j].dis < dis[v]) dis[v] = g[u][j].dis;
    }
  }
  return ret;
}
