#include <bits/stdc++.h>

const int N = 5e3 + 5;
const int M = 5e3 + 5;

int n, m;
struct Edge {
  int v, id;
};
std::vector<Edge> g[N];
int vis[M], ans[M];
bool cir;

void Dfs(int u) {
  vis[u] = 1;
  for (auto &e : g[u]) {
    if (vis[e.v] == 0) {
      ans[e.id] = 1;
      Dfs(e.v);
    }
    else if (vis[e.v] == 2) {
      ans[e.id] = 1;
    }
    else {
      ans[e.id] = 2;
      cir = true;
    }
  }
  vis[u] = 2;
}

int main() {
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= m; ++i) {
    int u, v;
    scanf("%d%d", &u, &v);
    g[u].push_back((Edge){v, i});
  }
  for (int i = 1; i <= n; ++i) {
    if (vis[i] == 0) {
      Dfs(i);
    }
  }
  if (cir == false) {
    printf("1\n");
    for (int i = 1; i <= m; ++i) {
      printf("1 ");
    }
    printf("\n");
  }
  else {
    printf("2\n");
    for (int i = 1; i <= m; ++i) {
      printf("%d ", ans[i]);
    }
    printf("\n");
  }
  return 0;
}

