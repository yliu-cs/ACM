const int maxn = "Edit";

int n;
int dis[maxn][maxn];

void Floyd() {
  for (int k = 1; k <= n; ++k) {
    for (int i = 1; i <= n; ++i) {
      for (int j = 1; j <= n; ++j) {
        dis[i][j] = std::min(dis[i][j], dis[i][k] + dis[k][j]);
      }
    }
  }
}
