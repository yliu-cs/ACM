const int maxn = "Edit";

struct edge {int v, next;};
struct query {int q, next, index;};

int pre[maxn << 2];
edge g[maxn << 2];
int head[maxn];
int tot;
query qg[maxn << 2];
int qhead[maxn];
int qtot;
int vis[maxn];
int anc[maxn];
int ans[maxn];

int Find(int x) {return pre[x] == x ? x : pre[x] = Find(pre[x]);}
void Union(int x, int y) {pre[Find(x)] = Find(y);}

void AddEdge(int u, int v) {
  g[tot] = edge {v, head[u]};
  head[u] = tot++;
}

// 添加询问
void AddQuery(int u, int v, int index) {
  qg[qtot] = query {v, qhead[u], index};
  qhead[u] = qtot++;
  qg[qtot] = query {u, qhead[v], index};
  qhead[v] = qtot++;
}

// 初始化
void Init() {
  tot = 0;
  memset(head, -1, sizeof(head));
  qtot = 0;
  memset(qhead, -1, sizeof(qhead));
  memset(vis, false, sizeof(vis));
  memset(pre, -1, sizeof(pre));
  memset(anc, 0, sizeof(anc));
  for (int i = 0; i <= n; ++i) pre[i] = i;
}

// LCA离线Tarjan算法
void Tarjan(int u) {
  anc[u] = u;
  vis[u] = true;
  for (int i = head[u]; ~i; i = g[i].next) {
    if (vis[g[i].v]) continue;
    Tarjan(g[i].v);
    Join(u, g[i].v);
    anc[Find(u)] = u;
  }
  for (int i = qhead[u]; ~i; i = qg[i].next) {
    if (vis[qg[i].q]) ans[qg[i].index] = anc[Find(qg[i].q)];
  }
}

