// luogu-judger-enable-o2
#include <bits/stdc++.h>
const int maxn = 5e5 + 5;
const int maxlog = 25;

int n, q, rt;
std::vector<int> g[maxn];
int arr[maxn << 1];
int dep[maxn << 1];
int fi[maxn], fa[maxn];
int tot;
int dp[maxn << 1][maxlog];

void Dfs(int u, int p, int d) {
  arr[++tot] = u;
  fi[u] = tot;
  dep[tot] = d;
  fa[u] = p;
  for (int &v : g[u]) {
    if (v == p) continue;
    Dfs(v, u, d + 1);
    arr[++tot] = u;
    dep[tot] = d;
  }
}

void Init() {
  for (int i = 1; i <= 2 * n - 1; ++i) dp[i][0] = i;
  for (int j = 1; (1 << j) <= 2 * n - 1; ++j) {
    for (int i = 1; i + (1 << j) - 1 <= 2 * n - 1; ++i) {
      dp[i][j] = dep[dp[i][j - 1]] < dep[dp[i + (1 << (j - 1))][j - 1]] ? dp[i][j - 1] : dp[i + (1 << (j - 1))][j - 1];
    }
  }
}

int Query(int l, int r) {
  if(l > r) std::swap(l, r);
  int len = (int)log2(r - l + 1);
  return dep[dp[l][len]] <= dep[dp[r - (1 << len) + 1][len]] ? dp[l][len] : dp[r - (1 << len) + 1][len];
}

int GetLCA(int u, int v) { return arr[Query(fi[u], fi[v])]; }

int main() {
  scanf("%d%d%d", &n, &q, &rt);
  for (int i = 1, u, v; i < n; ++i) {
    scanf("%d%d", &u, &v);
    g[u].push_back(v);
    g[v].push_back(u);
  }
  Dfs(rt, 0, 0);
  fa[1] = 0;
  Init();
  for (int i = 1, u, v; i <= q; ++i) {
    scanf("%d%d", &u, &v);
    printf("%d\n", GetLCA(u, v));
  }
  return 0;
}