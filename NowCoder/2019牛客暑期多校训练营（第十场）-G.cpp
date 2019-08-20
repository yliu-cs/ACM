#include <bits/stdc++.h>
typedef double db;
const db inf = 1e100;
const db eps = 1e-9;
const int maxn = 3e2 + 5;
int Sgn(db k) { return std::fabs(k) < eps ? 0 : (k < 0 ? -1 : 1); }
int Cmp(db k1, db k2) { return Sgn(k1 - k2); }
db Min(db k1, db k2) { return Cmp(k1, k2) < 0 ? k1 : k2; }
db Max(db k1, db k2) { return Cmp(k1, k2) > 0 ? k1 : k2; }
struct point { db x, y; };
point operator + (point k1, point k2) { return (point){k1.x + k2.x, k1.y + k2.y}; }
point operator - (point k1, point k2) { return (point){k1.x - k2.x, k1.y - k2.y}; }
point operator * (point k1, db k2) { return (point){k1.x * k2, k1.y * k2}; }
point operator / (point k1, db k2) { return (point){k1.x / k2, k1.y / k2}; }
db operator * (point k1, point k2) { return k1.x * k2.x + k1.y * k2.y; }
db operator ^ (point k1, point k2) { return k1.x * k2.y - k1.y * k2.x; }
db GetLen(point k) { return std::sqrt(k * k); }
db GetDis(point k1, point k2) { return GetLen(k2 - k1); }
point Rotate90(point k) { return (point){-k.y, k.x}; }
int n;
point p[maxn];
db Check(point vec) {
  std::vector<db> ret;
  for (int i = 1; i <= n; ++i) ret.push_back((vec ^ p[i]) / GetLen(vec));
  std::sort(ret.begin(), ret.end(),
    [&](const db &k1, const db k2) {
      return Cmp(k1, k2) < 0;
    }
  );
  return std::fabs(ret[n / 2 - 1] - ret[n / 2]) / 2.;
}
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i) scanf("%lf%lf", &p[i].x, &p[i].y);
  db ans = -inf;
  for (int i = 1; i <= n; ++i) {
    for (int j = i + 1; j <= n; ++j) {
      ans = Max(ans, Check(Rotate90(p[j] - p[i])));
      ans = Max(ans, Check(p[j] - p[i]));
    }
  }
  printf("%.15lf\n", ans);
  return 0;
}
