#include <bits/stdc++.h>
typedef double db;
const db eps = 1e-9;
int Sgn(db k) { return std::fabs(k) < eps ? 0 : (k < 0 ? -1 : 1); }
int Cmp(db k1, db k2) { return Sgn(k1 - k2); }
db Max(db k1, db k2) { return Cmp(k1, k2) > 0 ? k1 : k2; }
db Min(db k1, db k2) { return Cmp(k1, k2) < 0 ? k1 : k2; }
struct point { db x, y; };
point operator + (point k1, point k2) { return (point){k1.x + k2.x, k1.y + k2.y}; }
point operator - (point k1, point k2) { return (point){k1.x - k2.x, k1.y - k2.y}; }
point operator * (point k1, db k2) { return (point){k1.x * k2, k1.y * k2}; }
point operator / (point k1, db k2) { return (point){k1.x / k2, k1.y / k2}; }
db operator * (point k1, point k2) { return k1.x * k2.x + k1.y * k2.y; }
db operator ^ (point k1, point k2) { return k1.x * k2.y - k1.y * k2.x; }
db GetLen(point k) { return std::sqrt(k * k); }
db GetLen2(point k) { return k * k; }
db GetDis(point k1, point k2) { return GetLen(k2 - k1); }
db GetDis2(point k1, point k2) { return GetLen2(k2 - k1); }
struct seg { point s, t; };
db GetLen(seg k) { return GetLen(k.t - k.s); }
db GetLen2(seg k) { return GetLen2(k.t - k.s); }
bool IsInter(seg k1, seg k2) {
  return
    Max(k1.s.x, k1.t.x) >= Min(k2.s.x, k2.t.x) &&
    Max(k2.s.x, k2.t.x) >= Min(k1.s.x, k1.t.x) &&
    Max(k1.s.y, k1.t.y) >= Min(k2.s.y, k2.t.y) &&
    Max(k2.s.y, k2.t.y) >= Min(k1.s.y, k1.t.y) &&
    Sgn((k2.s - k1.t) ^ (k1.s - k1.t)) * Sgn((k2.t - k1.t) ^ (k1.s - k1.t)) <= 0 &&
    Sgn((k1.s - k2.t) ^ (k2.s - k2.t)) * Sgn((k1.t - k2.t) ^ (k2.s - k2.t)) <= 0;
}
typedef std::vector<point> polygon;
polygon GrahamScan(std::vector<point> p) {
  polygon ret;
  if (p.size() < 3) {
    for (auto &v : p) ret.push_back(v);
    return ret;
  }
  int idx = 0;
  for (int i = 0; i < p.size(); ++i)
    if (Cmp(p[i].x, p[idx].x) < 0 || (!Cmp(p[i].x, p[idx].x) && Cmp(p[i].y, p[idx].y) < 0))
      idx = i;
  std::swap(p[0], p[idx]);
  std::sort(p.begin() + 1, p.end(),
    [&](const point &k1, const point &k2) {
      db ck = (k1 - p[0]) ^ (k2 - p[0]);
      if (Sgn(ck) > 0) return true;
      else if (!Sgn(ck) && Cmp(GetDis(k1, p[0]), GetDis(k2, p[0])) <= 0) return true;
      return false;
    }
  );
  ret.push_back(p[0]);
  for (int i = 1; i < p.size(); ++i) {
    while (ret.size() > 1 && Sgn((ret.back() - ret[ret.size() - 2]) ^ (p[i] - ret[ret.size() - 2])) <= 0) ret.pop_back();
    ret.push_back(p[i]);
  }
  return ret;
}
bool IsIn(point p, const polygon &ch) {
  point base = ch[0];
  if (Sgn((p - base) ^ (ch[1] - p)) > 0 || Sgn((p - base) ^ (ch.back() - base)) < 0) return false;
  if (!Sgn((p - base) ^ (ch[1] - p)) && Cmp(GetDis(p, base), GetDis(ch[1], base)) <= 0) return true;
  int idx = std::lower_bound(ch.begin(), ch.end(), p,
      [&](const point &k1, const point &k2) {
        return Sgn((k1 - base) ^ (k2 - base)) > 0;
      }
  ) - ch.begin() - 1;
  return Sgn((ch[idx + 1] - ch[idx]) ^ (p - ch[idx])) >= 0;
}
bool Check(const polygon &ch1, const polygon &ch2) {
  int sz1 = ch1.size(), sz2 = ch2.size();
  for (auto &p : ch1) if (IsIn(p, ch2)) return false;
  for (auto &p : ch2) if (IsIn(p, ch1)) return false;
  for (int i = 0; i < sz1; ++i)
    for (int j = 0; j < sz2; ++j)
      if (IsInter((seg){ch1[i], ch1[(i + 1) % sz1]}, (seg){ch2[j], ch2[(j + 1) % sz2]})) return false;
  return true;
}
int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    std::vector<point> p[2];
    int n;
    scanf("%d", &n);
    for (int i = 1, f; i <= n; ++i) {
      db x, y;
      scanf("%lf%lf%d", &x, &y, &f);
      p[f == 1].push_back((point){x, y});
    }
    p[0] = GrahamScan(p[0]);
    p[1] = GrahamScan(p[1]);
    if (Check(p[0], p[1])) printf("Successful!\n");
    else printf("Infinite loop!\n");
  }
  return 0;
}
