#include <bits/stdc++.h>

const int N = 2e5 + 5;

int n, m;
long long w[N];
std::vector<int> g1[N], g2[N];
int dfncnt, dfn[N], low[N], stk[N], stksz;
int bcccnt, bcc[N], bccsz[N];
long long bccw[N];
int s;
long long ans;

void Tarjan(int u, int p) {
  dfn[u] = low[u] = ++dfncnt;
  stk[++stksz] = u;
  for (auto &v : g1[u]) {
    if (v == p) {
      continue;
    }
    if (dfn[v]) {
      low[u] = std::min(low[u], low[v]);
      continue;
    }
    Tarjan(v, u);
    low[u] = std::min(low[u], low[v]);
  }
  if (low[u] == dfn[u]) {
    ++bcccnt;
    while (true) {
      int x = stk[stksz--];
      bcc[x] = bcccnt;
      ++bccsz[bcccnt];
      bccw[bcccnt] += w[x];
      if (x == u) {
        break;
      }
    }
  }
}

void Dfs1(int u, int p) {
  for (auto &v : g2[u]) {
    if (v == p) {
      continue;
    }
    Dfs1(v, u);
    if (bccsz[v] != 1) {
      bccw[u] += bccw[v];
      bccw[v] = 0;
      bccsz[u] += bccsz[v];
    }
  }
}

void Dfs2(int u, int p, long long sum) {
  ans = std::max(ans, sum);
  for (auto &v : g2[u]) {
    if (v == p) {
      continue;
    }
    Dfs2(v, u, sum + bccw[v]);
  }
}

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cin >> n >> m;
  for (int i = 1; i <= n; ++i) {
    std::cin >> w[i];
  }
  for (int i = 1; i <= m; ++i) {
    int u, v;
    std::cin >> u >> v;
    g1[u].emplace_back(v);
    g1[v].emplace_back(u);
  }
  Tarjan(1, 0);
  for (int u = 1; u <= n; ++u) {
    for (auto &v : g1[u]) {
      if (bcc[v] != bcc[u]) {
        g2[bcc[u]].push_back(bcc[v]);
      }
    }
  }
  std::cin >> s;
  s = bcc[s];
  Dfs1(s, 0);
  Dfs2(s, 0, bccw[s]);
  std::cout << ans << '\n';
  return 0;
}

