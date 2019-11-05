#include <bits/stdc++.h>
typedef double db;
const db eps = 1e-9;

namespace Geometry {
  int Sgn(db k) {return fabs(k) < eps ? 0 : (k < 0 ? -1 : 1);}
  int Cmp(db k1, db k2) {return Sgn(k1 - k2);}
  db max(db k1, db k2) {return Cmp(k1, k2) > 0 ? k1 : k2;}
  db min(db k1, db k2) {return Cmp(k1, k2) < 0 ? k1 : k2;}
  struct point {db x, y;};
  point operator + (point k1, point k2) {return (point){k1.x + k2.x, k1.y + k2.y};}
  point operator - (point k1, point k2) {return (point){k1.x - k2.x, k1.y - k2.y};}
  db operator * (point k1, point k2) {return k1.x * k2.x + k1.y * k2.y;}
  db operator ^ (point k1, point k2) {return k1.x * k2.y - k1.y * k2.x;}
  db GetDisP2P(point k1, point k2) {return sqrt((k2 - k1) * (k2 - k1));}
  db GetAng(point k1, point k2) {return fabs(atan2(fabs(k1 ^ k2), k1 * k2));}
  struct line {point s, t;};
  typedef line seg;
  db GetLen(seg k) {return sqrt((k.t - k.s) * (k.t - k.s));}
  db GetDisP2Line(point k1, line k2) {return fabs((k1 - k2.s) ^ (k2.t - k2.s)) / GetLen(k2);}
  db GetDisP2Seg(point k1, seg k2) {
    if (Sgn((k1 - k2.s) * (k2.t - k2.s)) < 0 || Sgn((k1 - k2.t) * (k2.s - k2.t)) < 0) {
      return min(GetDisP2P(k1, k2.s), GetDisP2P(k1, k2.t));
    }
    return GetDisP2Line(k1, k2);
  }
  struct circle {point o; db r;};
}
using namespace Geometry;

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr); std::cout.tie(nullptr);
  std::cout << std::fixed << std::setprecision(10);

  point s, t;
  std::cin >> s.x >> s.y;
  std::cin >> t.x >> t.y;
  circle blue, red;
  std::cin >> blue.o.x >> blue.o.y >> blue.r;
  std::cin >> red.o.x >> red.o.y >> red.r;

  if (Cmp(GetDisP2Seg(red.o, (seg){s, t}), red.r) >= 0) {
    std::cout << GetDisP2P(s, t) << '\n';
    return 0;
  }

  db dis_o2s = GetDisP2P(red.o, s), dis_o2t = GetDisP2P(red.o, t);
  db ang = GetAng(s - red.o, t - red.o) - acos(red.r / dis_o2s) - acos(red.r / dis_o2t);
  db ans = sqrt(dis_o2s * dis_o2s - red.r * red.r) + sqrt(dis_o2t * dis_o2t - red.r * red.r);
  ans += ang * red.r;

  std::cout << ans << '\n';
  return 0;
}
