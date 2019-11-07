#include <bits/stdc++.h>

const int N = 3e4 + 5;
const long long INF = 1e18 + 5;

int t, n;
long long k, a[N], b[N];

bool Check(long long x) {
  for (int i = 1; i <= n; ++i) {
    b[i] = a[i];
  }
  long long cnt = 0;
  for (int i = 1; i <= n; ++i) {
    cnt += b[i] / x;
    b[i] = b[i] % x;
    if (i + 1 <= n && b[i] != 0 && b[i] + b[i + 1] >= x) {
      ++cnt;
      b[i + 1] -= x - b[i];
      b[i] = 0;
    }
  }
  return cnt >= k;
}

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cin >> t;
  while (t--) {
    std::cin >> n >> k;
    for (int i = 1; i <= n; ++i) {
      std::cin >> a[i];
    }
    long long l = 1, r = INF, ans = 0;
    while (l <= r) {
      long long m = (l + r) / 2;
      if (Check(m)) {
        ans = m;
        l = m + 1;
      }
      else {
        r = m - 1;
      }
    }
    std::cout << ans * k << '\n';
  }
  return 0;
}

