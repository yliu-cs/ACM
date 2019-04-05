const int inf = "Edit";
const int maxn = "Edit";

struct edge {int v, cap, cost, flow, next;};
int n, e;
int head[maxn];
int path[maxn];
int dis[maxn];
bool vis[maxn];
int tot;
edge g[maxn];

void Init() {
  tot = 0;
  memset(head, -1, sizeof(head));
}

void AddEdge(int u, int v, int cap, int cost) {
  g[tot] = (edge){v, cap, cost, 0, head[u]};
  head[u] = tot++;
  g[tot] = (edge){u, 0, -cost, 0, head[v]};
  head[v] = tot++;
}

bool SPFA(int s, int t) {
  memset(dis, inf, sizeof(dis));
  memset(vis, false, sizeof(vis));
  memset(path, -1, sizeof(path));
  dis[s] = 0;
  vis[s] = true;
  std::queue<int> que;
  while (!que.empty()) que.pop();
  que.push(s);
  while (!que.empty()) {
    int U = que.front();
    que.pop();
    vis[U] = false;
    for (int i = head[U]; ~i; i = g[i].next) {
      int v = g[i].v;
      if (g[i].cap > g[i].flow && dis[v] > dis[U] + g[i].cost) {
        dis[v] = dis[U] + g[i].cost;
        path[v] = i;
        if (!vis[v]) {
          vis[v] = true;
          que.push(v);
        }
      }
    }
  }
  return path[t] != -1;
}

int MinCostMaxflow(int s, int t, int &min_cost) {
  int max_flow = 0;
  min_cost = 0;
  while (SPFA(s, t)) {
    int min = inf;
    for (int i = path[t]; ~i; i = path[g[i ^ 1].v]) {
      if (g[i].cap - g[i].flow < min) min = g[i].cap - g[i].flow;
    }
    for (int i = path[t]; ~i; i = path[g[i ^ 1].v]) {
      g[i].flow += min;
      g[i ^ 1].flow -= min;
      min_cost += g[i].cost * min;
    }
    max_flow += min;
  }
  return max_flow;
}

