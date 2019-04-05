const int inf = "Edit";
const int maxn = "Edit";

struct Edge {int v, dis;};
int n, e;
bool vis[maxn];
int cnt[maxn];
int dis[maxn];
std::vector<Edge> g[maxn];

void AddEdge (int u, int v, int c) {
  g[u].push_back((Edge){v, c});
  g[v].push_back((Edge){u, c});
}

bool SPFA(int s) {
  memset(vis, false, sizeof(vis));
  memset(dis, inf, sizeof(dis));
  memset(cnt, 0, sizeof(cnt));
  vis[s] = true;
  dis[s] = 0;
  cnt[s] = 1;
  std::queue<int> que;
  while (!que.empty()) que.pop();
  que.push(s);
  while (!que.empty()) {
    int U = que.front();
    que.pop();
    vis[U] = false;
    for (int i = 0; i < (int)g[U].size(); ++i) {
      int v = g[U][i].v;
      if (dis[v] > dis[U] + g[U][i].dis) {
        dis[v] = dis[U] + g[U][i].dis;
        if (!vis[v]) {
          vis[v] = true;
          que.push(v);
          if (++cnt[v] > N) return false;
        }
      }
    }
  }
  return true;
}

