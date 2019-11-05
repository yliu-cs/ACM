#include <bits/stdc++.h>
const int maxn = 1e5 + 5;

int n;
struct edge { int v, c; };
std::vector<edge> g[maxn];
std::map<int, int> map;
bool vis[maxn];

int o;
bool flag;
bool suc;
int ans;
int f;

void Dfs1(int u, int p) {
  vis[u] = true;
  for (edge &e : g[u]) {
    int v = e.v, c = e.c;
    if (v == p) continue;
    if (!vis[v]) {
      Dfs1(v, u);
      if (suc) return;
      if (u == o) {
        suc = true;
        flag = false;
        if (f) ans += c;
        else ans -= c;
        map[o] = ans / 2;
        return;
      }
      if (flag) {
        if (f) ans += c;
        else ans -= c;
        f ^= 1;
        return;
      }
    }
    else {
      flag = true;
      o = v;
      ans += c;
      return;
    }
  }
}

void Dfs2(int u) {
  vis[u] = true;
  for (edge &e : g[u]) {
    int v = e.v, c = e.c;
    if (!vis[v]) {
      map[v] = c - map[u];
      Dfs2(v);
    }
  }
}

int main() {
  scanf("%d", &n);
  memset(pre, -1, sizeof(pre));
  for (int i = 0, u, v, c; i < n; ++i) {
    scanf("%d%d%d", &u, &v, &c);
    g[u].push_back((edge){v, c});
    g[v].push_back((edge){u, c});
    if (Find(u) != Find(v)) Union(u, v);
  }
  f = 0;
  flag = suc = false;
  memset(vis, false, sizeof(vis));
  Dfs1(1, 0);
  memset(vis, false, sizeof(vis));
  Dfs2(o);
  for (int i = 1; i <= n; ++i) printf("%d\n", map[i]);
  return 0;
}