const int maxn = "Edit";

class graph {
  public:
    struct edge {int v, flow, next;};

    edge g[maxn << 2];
    int head[maxn];
    int tot;
    int dep[maxn];
    int cur[maxn];

    void Init() {
      tot = 0;
      memset(head, -1, sizeof(head));
    }
    
    void AddEdge(int u, int v, int flow, int rev = 0) {
      g[tot] = (edge){v, flow, head[u]};
      head[u] = tot++;
      g[tot] = (edge){u, rev, head[v]};
      head[v] = tot++;
    }

    bool Bfs(int s, int t) {
      memset(dep, -1, sizeof(dep));
      queue<int> que;
      dep[s] = 0;
      que.push(s);
      while (!que.empty()) {
        int u = que.front(); que.pop();
        for (int i = head[u]; ~i; i = g[i].next) {
          if (dep[g[i].v] == -1 && g[i].flow > 0) {
            dep[g[i].v] = dep[u] + 1;
            que.push(g[i].v);
          }
        }
      }
      return dep[t] != -1;
    }

    int Dfs(int u, int t, int flow) {
      if (u == t || flow == 0) return flow;
      int max_flow = 0, find_flow;
      for (int &i = cur[u]; ~i; i = g[i].next) {
        if (g[i].flow > 0 && dep[g[i].v] == dep[u] + 1) {
          find_flow = Dfs(g[i].v, t, min(flow - max_flow, g[i].flow));
          if (find_flow > 0) {
            g[i].flow -= find_flow;
            g[i ^ 1].flow += find_flow;
            max_flow += find_flow;
            if (max_flow == flow) return flow;
          }
        }
      }
      if (!max_flow) dep[u] = -2;
      return max_flow;
    }

    int Dinic(int s, int t) {
      int ans = 0;
      while (Bfs(s, t)) {
        for (int i = s; i <= t; ++i) cur[i] = head[i];
        ans += Dfs(s, t, inf);
      }
      return ans;
    }
};

