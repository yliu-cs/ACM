#include <bits/stdc++.h>
const int maxn = 1e5 + 5;

class FuncSegTree {
  public:
    int tot;
    int rt[maxn];
    int lson[maxn << 5], rson[maxn << 5];
    int cnt[maxn << 5];

    int Build(int l, int r) {
      int t = ++tot;
      int m = (l + r) >> 1;
      if (l != r) {
        lson[t] = Build(l, m);
        rson[t] = Build(m + 1, r);
      }
      return t;
    }

    int Modify(int prev, int l, int r, int v) {
      int t = ++tot;
      lson[t] = lson[prev]; rson[t] = rson[prev];
      cnt[t] = cnt[prev] + 1;
      int m = (l + r) >> 1;
      if (l != r) {
        if (v <= m) lson[t] = Modify(lson[t], l, m, v);
        else rson[t] = Modify(rson[t], m + 1, r, v);
      }
      return t;
    }

    int Query(int u, int v, int s, int t, int l, int r) {
      if (s <= l && t >= r) return cnt[v] - cnt[u];
      int m = (l + r) >> 1;
      int ret = 0;
      if (s <= m) ret += Query(lson[u], lson[v], s, t, l, m);
      if (t > m) ret += Query(rson[u], rson[v], s, t, m + 1, r);
      return ret;
    }
};

int n, k;
int origin[maxn], arr[maxn];
int size;
std::vector<int> g[maxn];
int dfs_clock;
int in[maxn], out[maxn];
int id[maxn];
FuncSegTree tree;

void DfsOrder(int u, int p) {
  in[u] = ++dfs_clock;
  id[dfs_clock] = u;
  for (int &v : g[u]) {
    if (v == p) continue;
    DfsOrder(v, u);
  }
  out[u] = dfs_clock;
}

int Get(int x) {
  return std::lower_bound(arr + 1, arr + size + 1, x) - arr;
}

long long dp[maxn];

void Dfs(int u, int p) {
  int s = Get(origin[u] - k), t = std::upper_bound(arr + 1, arr + size + 1, origin[u] + k) - arr - 1;
  dp[u] = tree.Query(tree.rt[in[u] - 1], tree.rt[out[u]], s, t, 1, size);
  for (int &v : g[u]) {
    if (v == p) continue;
    Dfs(v, u);
    dp[u] += dp[v];
  }
}

int main() {
  scanf("%d%d", &n, &k);

  for (int i = 1; i <= n; ++i) {
    scanf("%d", &origin[i]);
    arr[i] = origin[i];
  }

  std::sort(arr + 1, arr + n + 1);
  size = std::unique(arr + 1, arr + n + 1) - (arr + 1);

  for (int i = 2, p; i <= n; ++i) {
    scanf("%d", &p);
    g[i].push_back(p);
    g[p].push_back(i);
  }

  DfsOrder(1, 0);

  tree.tot = 0; tree.rt[0] = tree.Build(1, size);
  for (int i = 1; i <= n; ++i) tree.rt[i] = tree.Modify(tree.rt[i - 1], 1, size, Get(origin[id[i]]));

  Dfs(1, 0);

  for (int i = 1; i <= n; ++i) printf("%lld\n", dp[i]);
  return 0;
}

