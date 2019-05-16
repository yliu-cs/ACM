#include <bits/stdc++.h>
#include <bits/extc++.h>
typedef long long ll;
const ll inf = 1e6 + 5;

struct point { ll x, y; };

ll GetDis(point k1, point k2) {
  if (k1.x == k2.x) return abs(k1.y - k2.y);
  return abs(k1.x - k2.x);
}

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr); std::cout.tie(nullptr);

  freopen("intel.in", "r", stdin);
  freopen("intel.out", "w", stdout);

  int n; std::cin >> n;

  ll v_min = inf, v_max = -inf, h_min = inf, h_max = -inf;
  std::vector<point> p(n);
  for (int i = 0; i < n; ++i) {
    std::cin >> p[i].x >> p[i].y;
    v_min = std::min(v_min, p[i].x);
    v_max = std::max(v_max, p[i].x);
    h_min = std::min(h_min, p[i].y);
    h_max = std::max(h_max, p[i].y);
  }

  ll ans = 0;
  for (int i = 0; i < n; ++i) ans += GetDis(p[i], p[(i + 1) % n]);
  ans -= 2ll * abs(v_min - v_max) + 2ll * abs(h_min - h_max);

  std::cout << ans << '\n';

  return 0;
}

