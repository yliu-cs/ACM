#include <bits/stdc++.h>
typedef long long ll;
const int maxn = 1e4 + 5;
const ll inf = 1e18 + 5;

struct edge {
  int v, next;
  ll c;
};

struct node {
  int v;
  ll c;
};
bool operator < (node k1, node k2) {
  return k1.c > k2.c;
}

struct Graph {
  int n;
  edge g[maxn << 1];
  int tot;
  int head[maxn];
  ll dis[maxn];
  bool vis[maxn];

  void Init() {
    tot = 0;
    for (int i = 1; i <= n; ++i) head[i] = -1;
  }

  void AddEdge(int u, int v, ll c) {
    g[tot] = (edge){v, head[u], c};
    head[u] = tot++;
  }

  void Dijkstra(int s) {
    std::priority_queue<node> que;
    for (int i = 1; i <= n; ++i) {
      dis[i] = inf;
      vis[i] = false;
    }
    que.push((node){s, 0});
    dis[s] = 0;
    while (!que.empty()) {
      node cur = que.top();
      que.pop();
      int u = cur.v;
      ll c = cur.c;
      if (vis[u]) continue;
      vis[u] = true;
      dis[u] = c;
      for (int i = head[u]; ~i; i = g[i].next) {
        int v = g[i].v;
        if (vis[v]) continue;
        if (dis[v] > dis[u] + g[i].c) {
          dis[v] = dis[u] + g[i].c;
          que.push((node){v, dis[v]});
        }
      }
    }
  }
};

struct MaxFlow {
  int n;
  edge g[maxn << 1];
  int tot;
  int head[maxn];
  int dep[maxn];
  int cur[maxn];

  void Init() {
    tot = 0;
    for (int i = 1; i <= n; ++i) head[i] = -1;
  }

  void AddEdge(int u, int v, ll c, ll rev = 0) {
    g[tot] = (edge){v, head[u], c};
    head[u] = tot++;
    g[tot] = (edge){u, head[v], rev};
    head[v] = tot++;
  }

  bool Bfs(int s, int t) {
    for (int i = 1; i <= n; ++i) dep[i] = -1;
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

  ll Dfs(int u, int t, ll flow) {
    if (u == t || flow == 0) return flow;
    ll max = 0, findflow;
    for (int &i = cur[u]; ~i; i = g[i].next) {
      if (g[i].c > 0 && dep[g[i].v] == dep[u] + 1) {
        findflow = Dfs(g[i].v, t, std::min(flow - max, g[i].c));
        if (findflow > 0) {
          g[i].c -= findflow;
          g[i ^ 1].c += findflow;
          max += findflow;
          if (max == flow) return flow;
        }
      }
    }
    if (!max) dep[u] = -2;
    return max;
  }

  ll Dinic(int s, int t) {
    ll ret = 0;
    while (Bfs(s, t)) {
      for (int i = s; i <= t; ++i) cur[i] = head[i];
      ret += Dfs(s, t, inf);
    }
    return ret;
  }
};

Graph G1, G2;
MaxFlow F;

int main() {
  int t;
  scanf("%d", &t);
  for (int cas = 1; cas <= t; ++cas) {
    int n, m;
    scanf("%d%d", &n, &m);
    G1.n = n;
    G1.Init();
    G2.n = n;
    G2.Init();
    for (int i = 1, x, y, c; i <= m; ++i) {
      scanf("%d%d%d", &x, &y, &c);
      G1.AddEdge(x, y, c);
      G2.AddEdge(y, x, c);
    }
    G1.Dijkstra(1);
    ll min = G1.dis[n];
    if (min == inf) {
      printf("0\n");
      continue;
    }
    G2.Dijkstra(G2.n);
    F.n = n;
    F.Init();
    for (int u = 1; u <= G1.n; ++u) {
      for (int j = G1.head[u]; ~j; j = G1.g[j].next) {
        int v = G1.g[j].v, c = G1.g[j].c;
        if (G1.dis[u] + G2.dis[v] + c == min) F.AddEdge(u, v, c);
      }
    }
    ll ans = F.Dinic(1, n);
    printf("%lld\n", ans);
  }
  return 0;
}