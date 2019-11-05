#include <bits/stdc++.h>
const long long inf = 1e15 + 5;

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr); std::cout.tie(nullptr);
  
  int n; std::cin >> n;
  struct per {long long a, b, diff;};
  std::vector<per> p(n);
  for (int i = 0; i < n; ++i) {
    std::cin >> p[i].a >> p[i].b;
    p[i].diff = p[i].a - p[i].b;
  }

  std::sort(p.begin(), p.end(), [&](per k1, per k2) {return k1.diff > k2.diff;});

  long long ans = 0;
  for (int i = 0; i < n; ++i) ans += p[i].a * i + p[i].b * (n - i - 1);

  std::cout << ans << '\n';
  return 0;
}

