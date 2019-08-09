#include <bits/stdc++.h>
const int maxn = 4e5 + 5;

struct SegTree {
  long long sum[maxn * 8], cnt[maxn * 8], len[maxn * 8];
  void Pull(int o) {
     sum[o] = sum[o * 2] + sum[o * 2 + 1];
  }
  void Push(int o) {
    if (cnt[o] != 0) {
      cnt[o * 2] += cnt[o];
      cnt[o * 2 + 1] += cnt[o];
      sum[o * 2] += cnt[o] * len[o * 2];;
      sum[o * 2 + 1] += cnt[o] * len[o * 2 + 1];;
      cnt[o] = 0;
    }
  }
  void Build(int o, int l, int r, int arr[]) {
    sum[o] = cnt[o] = 0;
    if (l == r) {
      len[o] = arr[l + 1] - arr[l];
      return;
    }
    int m = (l + r) / 2;
    Build(o * 2, l, m, arr);
    Build(o * 2 + 1, m + 1, r, arr);
    len[o] = len[o * 2] + len[o * 2 + 1];
  }
  void Modify(int o, int l, int r, int ll, int rr) {
    if (ll <= l && rr >= r) {
      ++cnt[o];
      sum[o] += len[o];
      return;
    }
    Push(o);
    int m = (l + r) / 2;
    if (ll <= m) Modify(o * 2, l, m, ll, rr);
    if (rr > m) Modify(o * 2 + 1, m + 1, r, ll, rr);
    Pull(o);
  }
  int Query(int o, int l, int r, long long x, int arr[]) {
    if (l == r) {
      assert(cnt[o] != 0);
      if (x % cnt[o] == 0) return arr[l] + x / cnt[o] - 1;
      else return arr[l] + x / cnt[o];
    }
    Push(o);
    int m = (l + r) / 2;
    if (sum[o * 2] >= x) return Query(o * 2, l, m, x, arr);
    else return Query(o * 2 + 1, m + 1, r, x - sum[o * 2], arr);
  }
};

int x[maxn], y[maxn];
int l[maxn], r[maxn];
int arr[maxn * 2];
SegTree T;

int main() {
  int n;
  scanf("%d", &n);
  int a1, b1, c1, m1;
  scanf("%d%d%d%d%d%d", &x[1], &x[2], &a1, &b1, &c1, &m1);
  int a2, b2, c2, m2;
  scanf("%d%d%d%d%d%d", &y[1], &y[2], &a2, &b2, &c2, &m2);
  int tot = 0;
  for (int i = 1; i <= n; ++i) {
    if (i >= 3) {
      x[i] = (1ll * a1 * x[i - 1] + 1ll * b1 * x[i - 2] + c1) % m1;
      y[i] = (1ll * a2 * y[i - 1] + 1ll * b2 * y[i - 2] + c2) % m2;
    }
    l[i] = std::min(x[i], y[i]) + 1;
    r[i] = std::max(x[i], y[i]) + 1;
    arr[++tot] = l[i];
    arr[++tot] = r[i] + 1;
  }
  std::sort(arr + 1, arr + tot + 1);
  int sz = std::unique(arr + 1, arr + tot + 1) - arr - 1;
  for (int i = 1; i <= n; ++i) {
    l[i] = std::lower_bound(arr + 1, arr + sz + 1, l[i]) - arr;
    r[i] = std::lower_bound(arr + 1, arr + sz + 1, r[i] + 1) - arr;
  }
  T.Build(1, 1, sz - 1, arr);
  long long cnt = 0;
  for (int i = 1; i <= n; ++i) {
    cnt += arr[r[i]] - arr[l[i]] + 1;
    T.Modify(1, 1, sz - 1, l[i], r[i] - 1);
    printf("%d\n", T.Query(1, 1, sz - 1, (T.sum[1] + 1) / 2, arr));
  }
  return 0;
}

