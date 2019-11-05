#include <bits/stdc++.h>

const int INF = 1e9 + 5;
const int N = 1e2 + 5;

int n, m, rt;
struct Edge {
  int u, v, c;
};
std::vector<Edge> edge;
int minin[N], pre[N], id[N], vis[N];
int ans;

int Zhuliu() {
  int ret = 0;
  while (true) {
    for (int i = 1; i <= n; ++i) {
      minin[i] = INF;
    }
    for (auto &e : edge) {
      if (e.u != e.v && e.c < minin[e.v]) {
        minin[e.v] = e.c;
        pre[e.v] = e.u;
      }
    }
    for (int i = 1; i <= n; ++i) {
      if (i != rt && minin[i] == INF) {
        return -1;
      }
    }
    int cnt = 0;
    for (int i = 1; i <= n; ++i) {
      id[i] = vis[i] = 0;
    }
    for (int i = 1; i <= n; ++i) {
      if (i == rt) {
        continue;
      }
      ret += minin[i];
      int v = i;
      while (vis[v] != i && !id[v] && v != rt) {
        vis[v] = i;
        v = pre[v];
      }
      if (!id[v] && v != rt) {
        id[v] = ++cnt;
        for (int u = pre[v]; u != v; u = pre[u]) {
          id[u] = cnt;
        }
      }
    }
    if (cnt == 0) {
      break;
    }
    for (int i = 1; i <= n; ++i) {
      if (!id[i]) {
        id[i] = ++cnt;
      }
    }
    for (auto &e : edge) {
      int u = e.u, v = e.v;
      e.u = id[u];
      e.v = id[v];
      if (id[u] != id[v]) {
        e.c -= minin[v];
      }
    }
    rt = id[rt];
    n = cnt;
  }
  return ret;
}

int main() {
  scanf("%d%d%d", &n, &m, &rt);
  for (int i = 1; i <= m; ++i) {
    int u, v, w;
    scanf("%d%d%d", &u, &v, &w);
    edge.push_back((Edge){u, v, w});
  }
  ans = Zhuliu();
  printf("%d\n", ans);
  return 0;
}

