#include <bits/stdc++.h>
const int maxn = 1e6 + 5;
long long a[maxn], b[maxn];
int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int n;
    scanf("%d", &n);
    long long ans = 0, sum = 0;
    for (int i = 1; i <= n; ++i) {
      scanf("%lld%lld", &a[i], &b[i]);
      sum += b[i];
    }
    for (int i = 1; i <= n; ++i) {
      long long tmp = 0;
      if (b[i] > ans) {
        sum -= b[i] - ans;
        tmp = b[i] - ans;
      }
      long long min = std::min(a[i], sum);
      sum -= min;
      ans += min;
      sum += tmp;
    }
    printf("%lld\n", ans);
  }
  return 0;
}
