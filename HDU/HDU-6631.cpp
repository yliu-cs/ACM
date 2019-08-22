#include <bits/stdc++.h>
typedef double db;
const db eps = 1e-9;
const int maxn = 1e3 + 5;
int Sgn(db k) { return std::fabs(k) < eps ? 0 : (k < 0 ? -1 : 1); }
int Cmp(db k1, db k2) { return Sgn(k1 - k2); }
struct point { db x, y; };
bool operator == (point k1, point k2) { return Cmp(k1.x, k2.x) == 0 && Cmp(k1.y, k2.y) == 0; }
bool operator != (point k1, point k2) { return Cmp(k1.x, k2.x) != 0 || Cmp(k1.y, k2.y) != 0; }
point operator - (point k1, point k2) { return (point){k1.x - k2.x, k1.y - k2.y}; }
point operator + (point k1, point k2) { return (point){k1.x + k2.x, k1.y + k2.y}; }
point operator * (point k1, db k2) { return (point){k1.x * k2, k1.y * k2}; }
point operator / (point k1, db k2) { return (point){k1.x / k2, k1.y / k2}; }
db operator * (point k1, point k2) { return k1.x * k2.x + k1.y * k2.y; }
db operator ^ (point k1, point k2) { return k1.x * k2.y - k1.y * k2.x; }
db GetLen(point k) { return std::sqrt(k * k); }
point Rotate90(point k) { return (point){-k.y, k.x}; }
db GetDis(point k1, point k2) { return GetLen(k2 - k1); }
struct line { point s, t; };
typedef line seg;
bool IsInter(const line &k1, const seg &k2) {
  return Sgn((k2.s - k1.t) ^ (k1.s - k1.t)) * Sgn((k2.t - k1.t) ^ (k1.s - k1.t)) <= 0;
}
point Proj(const point &k1, const line &k2) {
  point k = k2.t - k2.s;
  return k2.s + k * (((k1 - k2.s) * k) / GetLen(k));
}
bool IsIn(const point &k1, const line &k2) { return Sgn((k1 - k2.s) ^ (k1 - k2.t)) == 0; }
int n;
point p[maxn];
bool Check(seg k1, seg k2, const line &k3) {
  return IsInter(k3, k1) || IsInter(k3, k2);
}
bool Judge() {
  for (int i = 0; i < n; ++i) {
    point a = p[i], b = p[(i + 1) % n], m = (a + b) / 2.;
    line axis = (line){m, m + Rotate90(a - b)};
    int l = (i - 1 + n) % n, r = (i + 2) % n;
    int cnt = 0, ctl = n / 2 - 1;
    if ((n & 1) && !IsIn(p[(i + n / 2 + 1) % n], axis)) ++cnt;
    while (ctl--) {
      point lp = Proj(p[l], axis), rp = Proj(p[r], axis);
      if (lp != rp || (lp == rp && Cmp(GetDis(p[l], lp), GetDis(p[r], rp)) != 0)) {
        ++cnt;
        if (Check((seg){p[l], p[(l - 1 + n) % n]}, (seg){p[l], p[(l + 1) % n]}, axis) && Check((seg){p[r], p[(r - 1 + n) % n]}, (seg){p[r], p[(r + 1) % n]}, axis)) ++cnt;
      }
      l = (l - 1 + n) % n; r = (r + 1) % n;
    }
    if (cnt <= 1) return true;
  }
  for (int i = 0; i < n; ++i) {
    point a = p[i], b = p[(i + 2) % n], m = (a + b) / 2.;
    line axis = (line){m, m + Rotate90(a)};
    int l = (i - 1 + n) % n, r = (i + 3) % n;
    int cnt = 0, ctl = n / 2 - 1;
    if (!IsIn(p[(i + 1) % n], axis)) ++cnt;
    if (n % 2 == 0 && !IsIn(p[(i + n / 2 + 1) % n], axis)) ++cnt;
    while (ctl--) {
      point lp = Proj(p[l], axis), rp = Proj(p[r], axis);
      if (lp != rp || (lp == rp && Cmp(GetDis(p[l], lp), GetDis(p[r], rp)) != 0)) {
        ++cnt;
        if (Check((seg){p[l], p[(l - 1 + n) % n]}, (seg){p[l], p[(l + 1) % n]}, axis) && Check((seg){p[r], p[(r - 1 + n) % n]}, (seg){p[r], p[(r + 1) % n]}, axis)) ++cnt;
      }
      l = (l - 1 + n) % n; r = (r + 1) % n;
    }
    if (cnt <= 1) return true;
  }
  return false;
}
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.setf(std::ios::fixed);
  std::cout.precision(15);
  int t;
  std::cin >> t;
  for (int cas = 1; cas <= t; ++cas) {
    std::cin >> n;
    for (int i = 0; i < n; ++i) std::cin >> p[i].x >> p[i].y;
    if (n <= 4) {
      std::cout << "Y" << '\n';
      continue;
    }
    if (Judge()) std::cout << "Y" << '\n';
    else std::cout << "N" << '\n';
  }
  return 0;
}