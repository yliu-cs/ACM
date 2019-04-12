const int inf = "Edit";
const int maxn = "Edit";

struct edge {int v, c, next;};

edge g[maxn << 1];
int head[maxn];
int tot;
edge rev_g[maxn << 1];
int rev_head[maxn];
int rev_tot;

void Init() {
  tot = 0;
  memset(head, -1, sizeof(head));
  rev_tot = 0;
  memset(rev_head, -1, sizeof(rev_head));
}

void AddEdge(int u, int v, int c) {
  g[tot] = edge {v, c, head[u]};
  head[u] = tot++;
  rev_g[rev_tot] = edge {u, c, rev_head[v]};
  rev_head[v] = rev_tot++;
}

int dis[maxn];

struct Cmp {
  bool operator() (const int &k1, const int &k2) {
    return dis[k1] > dis[k2];
  }
};

// 利用反向边图求各点到终点的最短路
void Dijkstra(int s) {
  priority_queue<int, vector<int>, Cmp> que;
  memset(dis, inf, sizeof(dis));
  dis[s] = 0;
  que.push(s);
  while (!que.empty()) {
    int u = que.top(); que.pop();
    for (int i = rev_head[u]; i != -1; i = rev_g[i].next) {
      if (dis[rev_g[i].v] > dis[u] + rev_g[i].c) {
        dis[rev_g[i].v] = dis[u] + rev_g[i].c;
        que.push(rev_g[i].v);
      }
    }
  }
}

struct node {
  int f, g, p;
  // k*核心:f=g+H(p)，这里H(p)=dis[p]
  bool operator < (const node &k) const {
    if (f == k.f) return g > k.g;
    return f > k.f;
  }
};

// A*算法求起点s到终点t的第k短路
int AStar(int s, int t, int k) {
  int cnt = 0;
  priority_queue<node> que;
  // 注意特盘相同点是否算最短路
  if (s == t) k++;
  if (dis[s] == inf) return -1;
  que.push(node {dis[s], 0, s});
  while (!que.empty()) {
    node keep = que.top(); que.pop();
    if (keep.p == t) {
      cnt++;
      if (cnt == k) return keep.g;
    }
    for (int i = head[keep.p]; i != -1; i = g[i].next) {
      node tmp;
      tmp.p = g[i].v;
      tmp.g = keep.g + g[i].c;
      tmp.f = tmp.g + dis[tmp.p];
      que.push(tmp);
    }
  }
  return -1;
}
