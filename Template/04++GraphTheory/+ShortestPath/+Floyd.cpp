const int maxn = "Edit";

// n:顶点数
int n;
// dis[i][j]为i点到j点的最短路
int dis[maxn][maxn];

// Floyd算法
void Floyd() {
  for (int k = 1; k <= n; ++k) {
    for (int i = 1; i <= n; ++i) {
      for (int j = 1; j <= n; ++j) {
        dis[i][j] = std::min(dis[i][j], dis[i][k] + dis[k][j]);
      }
    }
  }
}
