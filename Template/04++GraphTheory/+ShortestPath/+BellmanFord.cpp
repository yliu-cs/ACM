const int inf = "Edit";
const int maxn = "Edit";

int n;
struct edge {int u, v, dis;};
int dis[maxn];
std::vector<edge> g;

// Bellman_Ford算法判断是否存在负环回路
bool BellmanFord(int s) {
  memset(dis, inf, sizeof(dis));
  dis[s] = 0;
  // 最多做N-1次
  for (int i = 1; i < n; ++i) {
    bool flag = false;
    for (int j = 0; j < (int)g.size(); ++j) {
      if (dis[g[j].v] > dis[g[j].u] + g[j].dis) {
        dis[g[j].v] = dis[g[j].u] + g[j].dis;
        flag = true;
      }
    }
    if (!flag) return true;
  }
  for (int j = 0; j < (int)g.size(); ++j) {
    if (dis[g[j].v] > dis[g[j].u] + g[j].dis) return false;
  }
  return true;
}
