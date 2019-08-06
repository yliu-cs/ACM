// luogu-judger-enable-o2
#include <bits/stdc++.h>
const int maxn = 5e5 + 5;

int n, q, rt;
std::vector<int> g[maxn];
struct query { int v, idx; };
std::vector<query> qg[maxn];
int pre[maxn];
bool vis[maxn];
int anc[maxn];
int ans[maxn];

int Find(int o) { return pre[o] == o ? o : pre[o] = Find(pre[o]); }

void Union(int u, int v) { pre[Find(u)] = Find(v); }

void Tarjan(int u) {
  vis[u] = true;
  for (int &v : g[u]) {
    if (vis[v] == true) continue;
    Tarjan(v);
    if (Find(u) != Find(v)) Union(u, v);
    anc[Find(u)] = u;
  }
  for (query &qy : qg[u]) {
    if (vis[qy.v]) ans[qy.idx] = anc[Find(qy.v)];
  }
}

int main() {
  scanf("%d%d%d", &n, &q, &rt);
  for (int i = 1; i <= n; ++i) {
    pre[i] = i;
    vis[i] = false;
    anc[i] = i;
  }
  for (int i = 1, u, v; i < n; ++i) {
    scanf("%d%d", &u, &v);
    g[u].push_back(v);
    g[v].push_back(u);
  }
  for (int i = 1, u, v; i <= q; ++i) {
    scanf("%d%d", &u, &v);
    qg[u].push_back((query){v, i});
    qg[v].push_back((query){u, i});
  }
  Tarjan(rt);
  for (int i = 1; i <= q; ++i) printf("%d\n", ans[i]);
  return 0;
}