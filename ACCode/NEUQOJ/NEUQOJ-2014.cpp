#include <bits/stdc++.h>
const int maxn = 5e5 + 5;

struct edge {int v, c, next;};

edge g[maxn << 1];
int tot;
int head[maxn];

void AddEdge(int u, int v, int c) {
  g[tot] = (edge){v, c, head[u]};
  head[u] = tot++;
}

int n;
int val[maxn];
long long sum[maxn];
long long dis[maxn];
long long ans;

void Dfs1(int u, int p) {
  dis[u] = 0; sum[u] = val[u];
  for (int i = head[u]; ~i; i = g[i].next) {
    int v = g[i].v, c = g[i].c;
    if (v == p) continue;
    Dfs1(v, u);
    dis[u] += dis[v] + c * sum[v];
    sum[u] += sum[v];
  }
}

void Dfs2(int u, int p) {
  for (int i = head[u]; ~i; i = g[i].next) {
    int v = g[i].v, c = g[i].c;
    if (v == p) continue;
    long long up_sum = sum[u] - sum[v], up_dis = dis[u] - dis[v] - c * sum[v];
    long long down_sum = sum[v], down_dis = dis[v];
    long long ret = up_dis + down_dis + c * up_sum;
    ans = std::min(ans, ret);
    dis[v] = ret; sum[v] = up_sum + down_sum;
    Dfs2(v, u);
  }
}

int main() {
  scanf("%d", &n);
  memset(head, -1, sizeof(head));
  for (int i = 1, u, v, c; i < n; ++i) {
    scanf("%d%d%d", &u, &v, &c);
    AddEdge(u, v, c);
    AddEdge(v, u, c);
  }
  for (int i = 1; i <= n; ++i) scanf("%d", &val[i]);

  Dfs1(1, 0);
  ans = dis[1];
  Dfs2(1, 0);

  printf("%lld\n", ans);
  return 0;
}

