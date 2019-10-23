// Author: Tony5t4rk Time: 2019-10-23 22:34:11 
#include <bits/stdc++.h>
const long long D = 40;
int t;
long long n;
long long a[D], pre[D];
void Init() {
  for (int i = 0; i < D; ++i) {
    a[i] = std::pow(3ll, (long long)i);
    if (!i) pre[i] = a[i];
    else pre[i] = pre[i - 1] + a[i];
  }
}
int main() {
  Init();
  scanf("%d", &t);
  while (t--) {
    scanf("%lld", &n);
    int idx = std::lower_bound(pre, pre + D, n) - pre;
    long long ans = pre[idx];
    for (int i = idx; i >= 0; --i) {
      if (ans - a[i] >= n) ans -= a[i];
    }
    std::cout << ans << '\n';
  }
  return 0;
}
