#include <bits/stdc++.h>
const int inf = 0x3f3f3f3f;
const int maxn = 1e6 + 5;

std::vector<int> g[maxn];
int t;
int n, m;
int pos;
int fa[maxn];
int arr[maxn];
int level[maxn];

void Mark(int u) {
  if (fa[u] != -1 && level[fa[u]] == inf) {
    level[fa[u]] = level[u];
    Mark(fa[u]);
  }
}

void Dfs(int u) {
  std::sort(g[u].begin(), g[u].end(), [&](int k1, int k2) {return level[k1] < level[k2];});
  for (auto &v : g[u]) Dfs(v);
  if (arr[pos] == u) ++pos;
}

int main() {
  scanf("%d", &t);
  for (int cas = 1; cas <= t; ++cas) {
    scanf("%d%d", &n, &m);

    for (int i = 1; i <= n; ++i) {
      fa[i] = -1; level[i] = inf;
      arr[i] = -1; g[i].clear();
    }

    for (int i = 2, p; i <= n; ++i) {
      scanf("%d", &p);
      g[p].push_back(i);
      fa[i] = p;
    }

    for (int i = 1; i <= m; ++i) {
      scanf("%d", &arr[i]);
      level[arr[i]] = i;
      Mark(arr[i]);
    }

    pos = 1;
    Dfs(1);

    if (pos == m + 1) printf("NOT BAD\n");
    else printf("BAD GUGU\n");
  }
  return 0;
}

