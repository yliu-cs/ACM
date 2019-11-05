#include <bits/stdc++.h>
const int maxn = 1e6 + 5;

struct edge {int v, next;};
int tot;
int head[maxn];
edge g[maxn << 1];

void AddEdge(int u, int v) {
  g[tot] = (edge){v, head[u]};
  head[u] = tot++;
}

int pre[maxn];

int Find(int x) {
  return pre[x] == x ? x : pre[x] = Find(pre[x]);
}

int t;
int n, m;
bool vis[maxn];
std::priority_queue<int, std::vector<int>, std::greater<int> > que;
int cnt;
bool first;

int main() {
  scanf("%d", &t);
  for (int cas = 1; cas <= t; ++cas) {
    scanf("%d%d", &n, &m);

    while (!que.empty()) que.pop();
    for (int i = 1; i <= n; ++i) {
      vis[i] = false;
      pre[i] = i;
      head[i] = -1;
    }

    tot = 0;
    for (int i = 1, u, v; i <= m; ++i) {
      scanf("%d%d", &u, &v);
      AddEdge(u, v); AddEdge(v, u);
      int anc_u = Find(u), anc_v = Find(v);
      if (anc_u != anc_v) pre[std::max(anc_u, anc_v)] = std::min(anc_u, anc_v);
    }

    cnt = 0;
    for (int i = 1; i <= n; ++i) {
      if (Find(i) == i) {
        vis[i] = true;
        que.push(i);
        ++cnt;
      }
    }

    first = true;
    printf("%d\n", cnt);
    while (!que.empty()) {
      int u = que.top(); que.pop();
      if (first) first = false;
      else printf(" ");
      printf("%d", u);
      for (int i = head[u]; ~i; i = g[i].next) {
        int v = g[i].v;
        if (vis[v]) continue;
        que.push(v);
        vis[v] = true;
      }
    }
    if (cas != t) printf("\n");
  }

  return 0;
}

