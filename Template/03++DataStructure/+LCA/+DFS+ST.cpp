const int maxn = "Edit";

struct edge { int v, c, next; };

edge edges[maxn << 1];
int head[maxn];
int tot;

void AddEdge(int u, int v, int c) {
  edges[tot] = (edge){v, c, head[u]};
  head[u] = tot++;
}

// 节点深度
int rmq[maxn << 1];
// 深搜遍历顺序
int vertex[maxn << 1];
// 节点在深搜中第一次出现的位置
int first[maxn];
int fa[maxn];
int dis[maxn];
int lca_tot;

// 最小值对应下标
int dp[maxn << 1][20];

// rmq初始化
void Work(int n) {
  for (int i = 1; i <= n; ++i) dp[i][0] = i;
  for (int j = 1; (1 << j) <= n; ++j) {
    for (int i = 1; i + (1 << j) - 1 <= n; ++i) {
      dp[i][j] = rmq[dp[i][j - 1]] < rmq[dp[i + (1 << (j - 1))][j - 1]] ? dp[i][j - 1] : dp[i + (1 << (j - 1))][j - 1];
    }
  }
}

// 深搜
void Dfs(int cur, int pre, int dep) {
  vertex[++lca_tot] = cur;
  first[cur] = lca_tot;
  rmq[lca_tot] = dep;
  fa[cur] = pre;
  for (int i = head[cur]; ~i; i = edges[i].next) {
    if (edges[i].v == pre) continue;
    dis[edges[i].v] = dis[cur] + edges[i].c;
    Dfs(edges[i].v, cur, dep + 1);
    vertex[++lca_tot] = cur;
    rmq[lca_tot] = dep;
  }
}

// rmq查询
int Query(int l, int r) {
  if (l > r) swap(l, r);
  int len = (int)log2(r - l + 1);
  return rmq[dp[l][len]] <= rmq[dp[r - (1 << len) + 1][len]] ? dp[l][len] : dp[r - (1 << len) + 1][len];
}

// LCA初始化
void Init(int rt, int num) {
  memset(dis, 0, sizeof(dis));
  lca_tot = 0;
  Dfs(rt, 0, 0);
  fa[1] = 0;
  Work(2 * num - 1);
}

// 查询节点u、v的距离
int GetDis(int u, int v) { return dis[u] + dis[v] - 2 * dis[LCA(u, v)]; }

// 查询节点u、v的最近公共祖先(LCA)
int GetLCA(int u, int v) { return vertex[Query(first[u], first[v])]; }
