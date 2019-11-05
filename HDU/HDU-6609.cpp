#include <bits/stdc++.h>
const int maxn = 2e5 + 5;

struct SegTree {
  int cnt[maxn * 4];
  long long sum[maxn * 4];
  void Pull(int o) {
    sum[o] = sum[o * 2] + sum[o * 2 + 1];
    cnt[o] = cnt[o * 2] + cnt[o * 2 + 1];
  }
  void Build(int o, int l, int r) {
    sum[o] = cnt[o] = 0;
    if (l == r) return;
    int m = (l + r) / 2;
    Build(o * 2, l, m);
    Build(o * 2 + 1, m + 1, r);
    Pull(o);
  }
  void Modify(int o, int l, int r, int idx, int arr[]) {
    if (l == r) {
      ++cnt[o];
      sum[o] += arr[idx];
      return;
    }
    int m = (l + r) / 2;
    if (idx <= m) Modify(o * 2, l, m, idx, arr);
    else Modify(o * 2 + 1, m + 1, r, idx, arr);
    Pull(o);
  }
  int Query(int o, int l, int r, long long x, int arr[]) {
    if (l == r) {
      return std::min(x / arr[l], 1ll * cnt[o]);
    }
    int m = (l + r) / 2;
    if (sum[o * 2] >= x) return Query(o * 2, l, m, x, arr);
    else return cnt[o * 2] + Query(o * 2 + 1, m + 1, r, x - sum[o * 2], arr);
  }
};

int arr[maxn];
int w[maxn];
SegTree T;

int main() {
  int t;
  scanf("%d", &t);
  for (int cas = 1; cas <= t; ++cas) {
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; ++i) {
      scanf("%d", &w[i]);
      arr[i] = w[i];
    }
    std::sort(arr + 1, arr + n + 1);
    int sz = std::unique(arr + 1, arr + n + 1) - arr - 1;
    T.Build(1, 1, sz);
    for (int i = 1; i <= n; ++i) {
      int v = std::lower_bound(arr + 1, arr + n + 1, w[i]) - arr;
      printf("%d ", i - T.Query(1, 1, sz, m - w[i], arr) - 1);
      T.Modify(1, 1, sz, v, arr);
    }
    printf("\n");
  }
  return 0;
}
