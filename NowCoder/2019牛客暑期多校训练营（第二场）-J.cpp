#include <bits/stdc++.h>
const int inf = 1e9 + 5;
const int maxn = 1e7 + 7;
const int offset = 1e7 + 2;
int l[maxn], r[maxn];
int f[maxn], g[maxn];
int pre[maxn * 3], cnt[maxn * 3], lazy[maxn * 3];
int main() {
  int n;
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i) scanf("%d%d", &l[i], &r[i]);
  f[1] = r[1] - l[1] + 1;
  for (int i = 2; i <= n; ++i) f[i] = std::max(0, f[i - 1] - (l[i] - r[i - 1] - 1)) + r[i] - l[i] + 1;
  g[n] = r[n] - l[n] + 1;
  for (int i = n - 1; i >= 1; --i) g[i] = std::max(0, g[i + 1] - (l[i + 1] - r[i] - 1)) + r[i] - l[i] + 1;
  int i = 1;
  long long ans = 0;
  while (i <= n) {
    int j = i + 1;
    while (j <= n && g[j] + f[j - 1] >= l[j] - r[j - 1] - 1) ++j;
    --j;
    int ll = std::max(0, l[i] - g[i]), rr = std::min((int)1e9 - 1, r[j] + f[j]);
    int idx = i, min = inf, max = 0;
    pre[0] = 0;
    for (int k = ll; k <= rr; ++k) {
      if (k >= l[idx] && k <= r[idx]) pre[k - ll + 1] = pre[k - ll] + 1;
      else pre[k - ll + 1] = pre[k - ll] - 1;
      if (k == r[idx]) ++idx;
      min = std::min(min, pre[k - ll + 1] + offset);
      max = std::max(max, pre[k - ll + 1] + offset);
      ans += pre[k - ll + 1] > 0;
      ++cnt[pre[k - ll + 1] + offset];
    }
    for (int k = max - 1; k >= min; --k) cnt[k] += cnt[k + 1];
    for (int k = ll; k <= rr; ++k) {
      int v = pre[k - ll + 1] + offset;
      ans += cnt[v + 1] - lazy[v + 1];
      cnt[v + 1] -= lazy[v + 1];
      lazy[v] += lazy[v + 1] + 1;
      lazy[v + 1] = 0;
    }
    for (int k = min; k <= max; ++k) {
      cnt[k] = 0;
      lazy[k] = 0;
    }
    i = j + 1;
  }
  printf("%lld\n", ans);
  return 0;
}
