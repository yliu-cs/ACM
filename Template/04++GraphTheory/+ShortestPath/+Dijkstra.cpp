const int maxn = "Edit";
const int inf = "Edit";

struct edge {int v, c, next;};

edge g[maxn << 1];
int head[maxn];
int tot;
int dis[maxn];

void Init() {
  tot = 0;
  memset(head, -1, sizeof(head));
}

void AddEdge(int u, int v, int c) {
  g[tot] = edge (v, c, head[u]);
  head[u] = tot++;
}

struct Cmp {
  bool operator() (const int &A, const int &B) {
    return dis[A] > dis[B];
  }
};

int n, e;

void Dijkstra(int s) {
  std::priority_queue<int, std::vector<int>, Cmp> que;
  memset(dis, inf, sizeof(dis));
  dis[s] = 0;
  que.push(s);
  while (!que.empty()) {
    int u = que.top(); que.pop();
    for (int i = head[u]; ~i; i = g[i].next) {
      if (dis[g[i].v] > dis[u] + g[i].c) {
        dis[g[i].v] = dis[u] + g[i].c;
        que.push(g[i].v);
      }
    }
  }
}

