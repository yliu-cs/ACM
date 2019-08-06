#include <bits/stdc++.h>

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0); std::cout.tie(0);

  int n; std::cin >> n;

  long long ans = 0;
  for (int i = 2; i < n; ++i) ans += i * (i + 1);

  std::cout << ans << '\n';
  return 0;
}
