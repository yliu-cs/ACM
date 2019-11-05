#include <bits/stdc++.h>
const int inf = 0x3f3f3f3f;
const int maxn = 5e2 + 5;

int n, m;
int map[maxn][maxn];
int ans[maxn][maxn];

int Dis(std::pair<int, int> k1, std::pair<int, int> k2) {
  return abs(k1.first - k2.first) + abs(k1.second - k2.second);
}

bool Check(std::pair<int, int> x) {
  return x.first >= 1 && x.first <= n && x.second >= 1 && x.second <= m;
}

struct status {int x, y; std::pair<int, int> s;};
std::queue<status> que;

void Bfs() {
  while (!que.empty()) {
    status cur = que.front(); que.pop();
    for (int i = -1; i < 2; ++i) {
      for (int j = -1; j < 2; ++j) {
        if (i == j && i == 0) continue;
        status next = (status){cur.x + i, cur.y + j, cur.s};
        if (!Check({next.x, next.y})) continue;
        int dis = Dis({next.x, next.y}, next.s);
        if (dis < ans[next.x][next.y]) {
          ans[next.x][next.y] = dis;
          que.push(next);
        }
      }
    }
  }
}

int main() {
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= m; ++j) {
      scanf("%d", &map[i][j]);
      if (map[i][j]) {
        que.push((status){i, j, {i, j}});
        ans[i][j] = 0;
      }
      else ans[i][j] = inf;
    }
  }

  Bfs();

  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= m; ++j) {
      printf("%d", ans[i][j]);
      if (j != m) printf(" ");
    }
    printf("\n");
  }
  return 0;
}

