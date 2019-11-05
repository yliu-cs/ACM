#include <bits/stdc++.h>
const int maxn = 3e6 + 5;
const long long inf = 1e18 + 5;

struct SegTree {
  int n;
  long long min[maxn << 2];
  long long max[maxn << 2];

  void Pull(int o) {
    min[o] = std::min(min[o << 1], min[o << 1 | 1]);
    max[o] = std::max(max[o << 1], max[o << 1 | 1]);
  }

  void Build(int o, int l, int r, long long arr[]) {
    if (l == r) {
      min[o] = max[o] = arr[l];
      return;
    }
    int m = (l + r) / 2;
    Build(o << 1, l, m, arr);
    Build(o << 1 | 1, m + 1, r, arr);
    Pull(o);
  }

  long long QueryMax(int o, int l, int r, int ll, int rr) {
    if (ll <= l && rr >= r) return max[o];
    int m = (l + r) / 2;
    long long ret = -inf;
    if (ll > rr) return 0;
    if (ll <= m) ret = std::max(ret, QueryMax(o << 1, l, m, ll, rr));
    if (rr > m) ret = std::max(ret, QueryMax(o << 1 | 1, m + 1, r, ll, rr));
    return ret;
  }
  long long QueryMax(int ll, int rr) {
    return QueryMax(1, 1, n, ll, rr);
  }

  long long QueryMin(int o, int l, int r, int ll, int rr) {
    if (ll <= l && rr >= r) return min[o];
    int m = (l + r) / 2;
    long long ret = inf;
    if (ll > rr) return 0;
    if (ll <= m) ret = std::min(ret, QueryMin(o << 1, l, m, ll, rr));
    if (rr > m) ret = std::min(ret, QueryMin(o << 1 | 1, m + 1, r, ll, rr));
    return ret;
  }
  long long QueryMin(int ll, int rr) {
    return QueryMin(1, 1, n, ll, rr);
  }
};

int n;
long long a[maxn];
long long b[maxn];
long long pref[maxn];
SegTree segtree;
int l[maxn], r[maxn];

void Init() {
  std::stack<int> s;
  for (int i = 1; i <= n; ++i) {
    while (!s.empty() && a[s.top()] >= a[i]) s.pop();
    if (s.empty()) l[i] = 1;
    else l[i] = s.top() + 1;
    s.push(i);
  }
  while (!s.empty()) s.pop();
  for (int i = n; i >= 1; --i) {
    while (!s.empty() && a[s.top()] >= a[i]) s.pop();
    if (s.empty()) r[i] = n;
    else r[i] = s.top() - 1;
    s.push(i);
  }
}

int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i) scanf("%lld", &a[i]);
  for (int i = 1; i <= n; ++i) scanf("%lld", &b[i]);
  for (int i = 1; i <= n; ++i) pref[i] = pref[i - 1] + b[i];
  Init();
  segtree.n = n;
  segtree.Build(1, 1, n, pref);
  long long ans = -inf;
  for (int i = 1; i <= n; ++i) {
    long long sum = 0;
    if (a[i] >= 0) {
      sum = segtree.QueryMax(i, r[i]) - segtree.QueryMin(l[i], i - 1);
      if (l[i] > i - 1) sum -= pref[i - 1];
    }
    else {
      sum = segtree.QueryMin(i, r[i]) - segtree.QueryMax(l[i], i - 1);
      if (l[i] > i - 1) sum -= pref[i - 1];
    }
    ans = std::max(ans, sum * a[i]);
  }
  printf("%lld\n", ans);
  return 0;
}