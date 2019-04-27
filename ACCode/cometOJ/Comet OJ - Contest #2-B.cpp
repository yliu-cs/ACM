#include <bits/stdc++.h>
typedef double db;
const db eps = 1e-6;

int Sgn(db k) {return fabs(k) < eps ? 0 : (k < 0 ? -1 : 1);}
int Cmp(db k1, db k2) {return Sgn(k1 - k2);}

db a, b, c, d;

db F(db x) {
  return ((x - a) / (b - a)) * (((c + d) - 2.0 * x) * 0.5);
}

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr); std::cout.tie(nullptr);
  std::cout << std::fixed << std::setprecision(4);

  std::cin >> a >> b >> c >> d;
  if (Cmp(a, d) >= 0) {
    std::cout << 0.0 << '\n';
    return 0;
  }

  db l = a, r = b;
  while (Cmp(l, r) != 0) {
    db m = (l + r) * 0.5;
    if (F(m + eps) > F(m - eps)) l = m;
    else r = m;
  }

  db ans = F(r);
  if (Sgn(ans) == 0) std::cout << 0.0 << '\n';
  else std::cout << ans << '\n';
  return 0;
}

