#include <bits/stdc++.h>
typedef double db;
const db eps = 1e-6;

int Sgn(db x) {return fabs(x) < eps ? 0 : (x < 0 ? -1 : 1);}
int Cmp(db k1, db k2) {return Sgn(k1 - k2);}

int n;
std::vector<db> arr;

db F(db x) {
  db ret = 0.0;
  for (int i = n; i >= 0; --i) ret = ret * x + arr[i];
  return ret;
}

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr); std::cout.tie(nullptr);
  std::cout << std::fixed << std::setprecision(5);

  db l, r; std::cin >> n >> l >> r;
  arr.resize(n + 1);
  for (int i = n; i >= 0; --i) std::cin >> arr[i];

  while (Cmp(l, r) != 0) {
    db m = (l + r) * 0.5;
    // if (Cmp(F(m + eps), F(m - eps)) > 0) l = m;
    if (F(m + eps) > F(m - eps)) l = m;
    else r = m;
  }

  std::cout << r << '\n';
  return 0;
}