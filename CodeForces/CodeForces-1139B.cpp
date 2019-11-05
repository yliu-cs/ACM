#include <bits/stdc++.h>

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0); std::cout.tie(0);

  long long n; std::cin >> n;
  std::vector<long long> a(n);
  for (auto &it : a) std::cin >> it;

  std::vector<long long> b(n);
  b[n - 1] = a[n - 1];
  long long ans = b[n - 1];
  for (int i = n - 2; i >= 0; --i) {
    b[i] = std::max((long long)0, std::min(a[i], b[i + 1] - 1ll));
    ans += b[i];
  }

  std::cout << ans << '\n';
  return 0;
}
