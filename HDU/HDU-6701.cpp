#include <bits/stdc++.h>
const int maxn = 3e5 + 5;
struct SegTree {
  int n;
  int val[maxn * 4], max[maxn * 4];
  int Unite(const int &k1, const int &k2) {
    return val[k1] > val[k2] ? k1 : k2;
  }
  void Pull(int o) {
    max[o] = Unite(max[o * 2], max[o * 2 + 1]);
  }
  void Build(int o, int l, int r) {
    if (l == r) {
      max[o] = l;
      return;
    }
    int m = (l + r) / 2;
    Build(o * 2, l, m);
    Build(o * 2 + 1, m + 1, r);
    Pull(o);
  }
  void Init(int _n, int arr[]) {
    n = _n;
    for (int i = 1; i <= n; ++i) val[i] = arr[i];
    Build(1, 1, n);
  }
  int Query(int o, int l, int r, int ll, int rr) {
    if (ll <= l && rr >= r) return max[o];
    int m = (l + r) / 2, ret = 0;
    if (ll <= m) ret = Unite(ret, Query(o * 2, l, m, ll, rr));
    if (rr > m) ret = Unite(ret, Query(o * 2 + 1, m + 1, r, ll, rr));
    return ret;
  }
  int Query(int ll, int rr) { return Query(1, 1, n, ll, rr); }
};
int t;
int n, k;
int a[maxn];
SegTree T;
long long ans;
int tpr[maxn], tpl[maxn];
bool vis[maxn];
void Dfs(int l, int r) {
  if (l > r) return;
  int idx = T.Query(l, r), max = a[idx], len = max - k;
  if (idx - l < r - idx) {
    for (int ll = l; ll <= idx; ++ll) {
      int rr = std::min(r, tpr[ll]), lr = ll + len - 1;
      if (lr <= idx) ans += std::max(0, rr - idx + 1);
      else ans += std::max(0, rr - lr + 1);
    }
  }
  else {
    for (int rr = idx; rr <= r; ++rr) {
      int ll = std::max(l, tpl[rr]), rl = rr - len + 1;
      if (rl >= idx) ans += std::max(0, idx - ll + 1);
      else ans += std::max(0, rl - ll + 1);
    }
  }
  Dfs(l, idx - 1);
  Dfs(idx + 1, r);
}
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cin >> t;
  for (int cas = 1; cas <= t; ++cas) {
    std::cin >> n >> k;
    for (int i = 1; i <= n; ++i) std::cin >> a[i];
    memset(vis, false, sizeof(vis));
    for (int l = 1, r = l; l <= n; ++l) {
      r = std::max(l, r);
      vis[a[l]] = true;
      while (!vis[a[r + 1]] && r + 1 <= n) {
        ++r;
        vis[a[r]] = true;
      }
      tpr[l] = r;
      vis[a[l]] = false;
    }
    memset(vis, false, sizeof(vis));
    for (int r = n, l = r; r >= 1; --r) {
      l = std::min(l, r);
      vis[a[r]] = true;
      while (!vis[a[l - 1]] && l - 1 >= 1) {
        --l;
        vis[a[l]] = true;
      }
      tpl[r] = l;
      vis[a[r]] = false;
    }
    T.Init(n, a);
    ans = 0;
    Dfs(1, n);
    std::cout << ans << '\n';
  }
  return 0;
}