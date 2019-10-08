// Author: Tony5t4rk Time: 2019-10-08 13:04:38 
#include <bits/stdc++.h>
const int maxn = 2e5 + 5;
int t, n;
long long p[maxn], pref[maxn];
long long x, a, y, b, k, lcm;
bool Check(int key) {
  int cnt2 = key / lcm, cnt0 = key / a, cnt1 = key / b;
  long long sum = 0;
  sum += pref[cnt2] * (x + y) / 100;
  sum += (pref[cnt0] - pref[cnt2]) * x / 100;
  sum += (pref[cnt1 + cnt0 - cnt2] - pref[cnt0]) * y / 100;
  return sum >= k;
}
int main() {
  scanf("%d", &t);
  while (t--) {
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) scanf("%lld", &p[i]);
    std::sort(p + 1, p + n + 1, [&](long long k1, long long k2) { return k1 > k2; });
    for (int i = 1; i <= n; ++i) pref[i] = pref[i - 1] + p[i];
    scanf("%lld%lld%lld%lld%lld", &x, &a, &y, &b, &k);
    if (x < y) {
      std::swap(x, y);
      std::swap(a, b);
    }
    lcm = a * b / std::__gcd(a, b);
    int l = 1, r = n, ans = -1;
    while (l <= r) {
      int m = (l + r) / 2;
      if (Check(m)) {
        ans = m;
        r = m - 1;
      }
      else l = m + 1;
    }
    printf("%d\n", ans);
  }
  return 0;
}
