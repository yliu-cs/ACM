#include <bits/stdc++.h>
const int maxn = 1e4 + 5;
struct road { int u, v, c; };
road e[maxn];
bool operator < (const road &k1, const road &k2) {
  return k1.c > k2.c;
}
int pre[maxn];
int Find(int x) {
  return pre[x] == x ? x : pre[x] = Find(pre[x]);
}
void Union(int u, int v) {
  pre[Find(u)] = Find(v);
}
struct edge { int v, c; };
std::vector<edge> g[maxn];
int Bfs(int s, int k) {
  int ret = 0;
  struct node { int u, prev, sum, step; };
  std::queue<node> que;
  que.push((node){s, -1, 0, 0});
  while (!que.empty()) {
    node cur = que.front();
    que.pop();
    if (cur.step == k) {
      ret = std::max(ret, cur.sum);
      continue;
    }
    for (edge &it : g[cur.u]) {
      if (it.v == cur.prev) continue;
      que.push((node){it.v, cur.u, cur.sum + it.c, cur.step + 1});
    }
  }
  return ret;
}
int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int n, m, k;
    scanf("%d%d%d", &n, &m, &k);
    for (int i = 1; i <= n; ++i) {
      pre[i] = i;
      g[i].clear();
    }
    for (int i = 1; i <= m; ++i) scanf("%d%d%d", &e[i].u, &e[i].v, &e[i].c);
    std::sort(e + 1, e + m + 1);
    for (int i = 1; i <= m; ++i) {
      int u = e[i].u, v = e[i].v, c = e[i].c;
      if (Find(u) == Find(v)) continue;
      Union(u, v);
      g[u].push_back((edge){v, c});
      g[v].push_back((edge){u, c});
    }
    int ans = 0;
    for (int i = 1; i <= n; ++i) ans = std::max(ans, Bfs(i, k - 1));
    if (ans) printf("%d\n", ans);
    else printf("impossible\n");
  }
  return 0;
}
