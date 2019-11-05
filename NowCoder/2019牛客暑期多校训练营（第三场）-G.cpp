#include <bits/stdc++.h>
const int maxn = 3e5 + 5;

int t;
int n;
int a[maxn];
long long pref[maxn];
long long ans;

int max[maxn << 2];

int Unite(const int &k1, const int &k2) {
  return a[k1] > a[k2] ? k1 : k2;
}

void Pull(int o) {
  max[o] = Unite(max[o << 1], max[o << 1 | 1]);
}

void Build(int o, int l, int r) {
  if (l == r) {
    max[o] = l;
    return;
  }
  int m = (l + r) >> 1;
  Build(o << 1, l, m);
  Build(o << 1 | 1, m + 1, r);
  Pull(o);
}

int Query(int o, int l, int r, int ll, int rr) {
  if (ll <= l && rr >= r) return max[o];
  int m = (l + r) >> 1;
  int ret = 0;
  if (ll <= m) ret = Unite(ret, Query(o << 1, l, m, ll, rr));
  if (rr > m) ret = Unite(ret, Query(o << 1 | 1, m + 1, r, ll, rr));
  return ret;
}

int CntLower(int l, int r, long long x) {
  int bl = l, br = r, idx = l - 1;
  while (bl <= br) {
    int bm = (bl + br) >> 1;
    if (pref[bm] <= x) {
      idx = bm;
      bl = bm + 1;
    }
    else br = bm - 1;
  }
  return idx - l + 1;
}

int CntUpper(int l, int r, long long x) {
  int bl = l, br = r, idx = r + 1;
  while (bl <= br) {
    int bm = (bl + br) >> 1;
    if (pref[bm] >= x) {
      idx = bm;
      br = bm - 1;
    }
    else bl = bm + 1;
  }
  return r - idx + 1;
}

void Dfs(int l, int r) {
  if (r <= l) return;
  int idx = Query(1, 1, n, l, r);
  if (idx - l < r - idx) {
    for (int i = l; i <= idx; ++i) ans += CntUpper(idx, r, pref[i - 1] + 2ll * a[idx]);
  }
  else {
    for (int i = idx; i <= r; ++i) ans += CntLower(l - 1, idx - 1, pref[i] - 2ll * a[idx]);
  }
  Dfs(l, idx - 1);
  Dfs(idx + 1, r);
}

int main () {
  scanf("%d", &t);
  for (int cas = 1; cas <= t; ++cas) {
    scanf("%d", &n);
    pref[0] = 0;
    for (int i = 1; i <= n; ++i) {
      scanf("%d", &a[i]);
      pref[i] = pref[i - 1] + a[i];
    }
    Build(1, 1, n);
    ans = 0;
    Dfs(1, n);
    printf("%lld\n", ans);
  }
  return 0;
}
