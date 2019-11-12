#include <bits/stdc++.h>

const int N = 2e6 + 5;
const int INF = 1e9 + 5;

struct MaxFlow {
  struct Edge {
    int v, next, c;
  };
  int n;
  Edge g[N * 4];
  int tot, head[N], dep[N], cur[N];

  void Init() {
    tot = 0;
    for (int i = 1; i <= n; ++i) {
      head[i] = -1;
    }
  }

  void AddEdge(int u, int v, int c, int rev = 0) {
    g[tot] = (Edge){v, head[u], c};
    head[u] = tot++;
    g[tot] = (Edge){u, head[v], rev};
    head[v] = tot++;
  }

  bool Bfs(int s, int t) {
    for (int i = 1; i <= n; ++i) {
      dep[i] = -1;
    }
    std::queue<int> que;
    dep[s] = 0;
    que.push(s);
    while (!que.empty()) {
      int u = que.front();
      que.pop();
      for (int i = head[u]; ~i; i = g[i].next) {
        if (dep[g[i].v] == -1 && g[i].c > 0) {
          dep[g[i].v] = dep[u] + 1;
          que.push(g[i].v);
        }
      }
    }
    return dep[t] != -1;
  }

  int Dfs(int u, int t, int flow) {
    if (u == t || flow == 0) {
      return flow;
    }
    int max = 0, findflow;
    for (int &i = cur[u]; ~i; i = g[i].next) {
      if (g[i].c > 0 && dep[g[i].v] == dep[u] + 1) {
        findflow = Dfs(g[i].v, t, std::min(flow - max, g[i].c));
        if (findflow > 0) {
          g[i].c -= findflow;
          g[i ^ 1].c += findflow;
          max += findflow;
          if (max == flow) {
            return flow;
          }
        }
      }
    }
    if (!max) {
      dep[u] = -2;
    }
    return max;
  }

  int Dinic(int s, int t) {
    int ret = 0;
    while (Bfs(s, t)) {
      for (int i = s; i <= t; ++i) {
        cur[i] = head[i];
      }
      ret += Dfs(s, t, INF);
    }
    return ret;
  }
};

MaxFlow G;

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int n, m;
  std::cin >> n >> m;
  std::vector<std::vector<char>> maze(n, std::vector<char>(m));
  for (auto &r : maze) {
    for (auto &c : r) {
      std::cin >> c;
    }
  }
  G.n = 2 * n * m;
  G.Init();
  auto Get = [&](int x, int y) -> int {
    return x * m + y + 1;
  };
  auto Check = [&](int x, int y) -> bool {
    return x >= 0 && y >= 0 && x < n && y < m;
  };
  for (int x = 0; x < n; ++x) {
    for (int y = 0; y < m; ++y) {
      if ((x == 0 && y == 0) || (x == n - 1 && y == m - 1)) {
        G.AddEdge(Get(x, y), n * m + Get(x, y), 2);
      }
      else {
        G.AddEdge(Get(x, y), n * m + Get(x, y), 1);
      }
      for (int i = 0; i <= 1; ++i) {
        for (int j = 0; j <= 1; ++j) {
          if (i == j) {
            continue;
          }
          int nx = x + i, ny = y + j;
          if (Check(nx, ny) && maze[nx][ny] == '.') {
            G.AddEdge(n * m + Get(x, y), Get(nx, ny), 1);
          }
        }
      }
    }
  }
  std::cout << G.Dinic(Get(0, 0), n * m + Get(n - 1, m - 1)) << '\n';
  return 0;
}

