#include <bits/stdc++.h>
const int maxn = 1e5 + 5;
const int inf = 1e9 + 5;

int n, k;
std::vector<int> g[maxn];
int ma[maxn], se[maxn];
bool maf[maxn];
std::set<int> set;

void Dfs1(int u, int p, int d) {
  if (set.find(u) != set.end()) ma[u] = d;
  for (int &v : g[u]) {
    if (v == p) continue;
    Dfs1(v, u, d + 1);
    if (ma[v] > ma[u]) {
      se[u] = ma[u];
      ma[u] = ma[v];
    }
    else if (ma[v] == ma[u]) maf[u] = true;
    else if (ma[v] > se[u]) se[u] = ma[v];
  }
}

int ans;

void Dfs2(int u, int p, int dis, int max) {
  ans = std::min(ans, std::max(ma[u] - dis, max));
  for (int &v : g[u]) {
    if (v == p) continue;
    if (ma[u] == ma[v]) {
      if (maf[u] == true) {
        Dfs2(v, u, dis + 1, std::max(max + 1, ma[u] - dis + 1));
      }
      else {
        Dfs2(v, u, dis + 1, std::max(max + 1, se[u] - dis + 1));
      }
    }
    else Dfs2(v, u, dis + 1, std::max(max + 1, ma[u] - dis + 1));
  }
}

int main() {
  scanf("%d%d", &n, &k);
  for (int i = 1, u, v; i < n; ++i) {
    scanf("%d%d", &u, &v);
    g[u].emplace_back(v);
    g[v].emplace_back(u);
  }
  for (int i = 0, x; i < k; ++i) {
    scanf("%d", &x);
    set.insert(x);
  }
  memset(ma, 0, sizeof(ma));
  memset(se, 0, sizeof(se));
  Dfs1(1, 0, 0);
  memset(maf, false, sizeof(maf));
  ans = inf;
  Dfs2(1, 0, 0, 0);
  printf("%d\n", ans);
  return 0;
}