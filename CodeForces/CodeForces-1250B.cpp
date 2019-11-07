#include <bits/stdc++.h>

const int K = 8e3 + 5;
const long long INF = 1e18 + 5;

int n, k, max, t[K];
long long ans;

int Cal(int x) {
  int ret = 0;
  for (int i = 1; i <= x; ++i) {
    ret = std::max(ret, t[i] + t[2 * x - i + 1]);
  }
  for (int i = 2 * x + 1; i <= k; ++i) {
    ret = std::max(ret, t[i]);
  }
  return ret;
}

int main() {
  scanf("%d%d", &n, &k);
  for (int i = 1; i <= n; ++i) {
    int x;
    scanf("%d", &x);
    ++t[x];
  }
  std::sort(t + 1, t + k + 1);
  ans = INF;
  for (int i = k; i >= (k + 1) / 2; --i) {
    ans = std::min(ans, 1ll * i * Cal(k - i));
  }
  printf("%I64d\n", ans);
  return 0;
}

