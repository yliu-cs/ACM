#include <bits/stdc++.h>

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr); std::cout.tie(nullptr);

  long long n; std::cin >> n;
  std::vector<long long> a(n + 1);
  std::cin >> a[1];
  std::vector<long long> b(n + 1, a[1]);
  long long m; std::cin >> m;

  for (long long i = 2; i <= n; ++i) {
    a[i] = (a[i - 1] + 7ll * i) % m;
    for (long long j = 1; i * j <= n; ++j) b[i * j] += a[i];
  }

  long long ans = 0;
  for (int i = 1; i <= n; ++i) ans ^= b[i];

  std::cout << ans << '\n';
  return 0;
}

