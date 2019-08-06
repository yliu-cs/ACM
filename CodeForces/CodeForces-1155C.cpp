#include <bits/stdc++.h>
typedef long long ll;

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr); std::cout.tie(nullptr);

  ll n, m; std::cin >> n >> m;
  std::vector<ll> x(n);
  for (auto &v : x) std::cin >> v;

  std::sort(x.begin(), x.end());
  ll gcd = x[1] - x[0];
  for (int i = 2; i < n; ++i) gcd = std::__gcd(gcd, x[i] - x[i - 1]);

  std::vector<ll> p(m);
  for (auto &v : p) std::cin >> v;

  ll ans = -1;
  for (int i = 0; i < m; ++i) {
    if (gcd % p[i] == 0) {
      ans = i + 1;
      break;
    }
  }

  if (ans != -1) {
    std::cout << "YES\n";
    std::cout << x[0] << ' ' << ans << '\n';
  }
  else std::cout << "NO\n";
  return 0;
}

