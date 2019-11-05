#include <bits/stdc++.h>
typedef double db;
const db eps = 1e-9;

int Sgn(db k) { return fabs(k) < eps ? 0 : (k < 0 ? -1 : 1); }
int Cmp(db k1, db k2) { return Sgn(k1 - k2); }

struct point { db x, y; };
point operator - (point k1, point k2) { return (point){k1.x - k2.x, k1.y - k2.y}; }
point operator + (point k1, point k2) { return (point){k1.x + k2.x, k1.y + k2.y}; }
db operator * (point k1, point k2) { return k1.x * k2.x + k1.y * k2.y; }
db operator ^ (point k1, point k2) { return k1.x * k2.y - k1.y * k2.x; }
db GetDisP2P(point k1, point k2) { return sqrt((k1 - k2) * (k1 - k2)); }
db GetLen(point k) { return sqrt(k * k); }

typedef std::vector<point> poly;
poly Grahamscan(std::vector<point> p) {
  poly ret;
  if ((int)p.size() < 3) {
    for (point &v : p) ret.emplace_back(v);
    return ret;
  }
  int idx = 0;
  for (int i = 0; i < (int)p.size(); ++i)
    if (Cmp(p[i].x, p[idx].x) < 0 || (Cmp(p[i].x, p[idx].x) == 0 && Cmp(p[i].y, p[idx].y) < 0))
      idx = i;
  std::swap(p[0], p[idx]);
  std::sort(p.begin() + 1, p.end(), [&](point k1, point k2) {
    db tmp = (k1 - p[0]) ^ (k2 - p[0]);
    if (Sgn(tmp) > 0) return true;
    else if (Sgn(tmp) == 0 && Cmp(GetDisP2P(k1, p[0]), GetDisP2P(k2, p[0])) < 0) return true;
    return false;
  });
  ret.emplace_back(p[0]);
  for (int i = 1; i < (int)p.size(); ++i) {
    while ((int)ret.size() >= 2 && Sgn((ret.back() - ret[(int)ret.size() - 2]) ^ (p[i] - ret[(int)ret.size() - 2])) <= 0) ret.pop_back();
    ret.emplace_back(p[i]);
  }
  return ret;
}

poly Minkowski(const poly &k1, const poly &k2) {
  int sz1 = (int)k1.size(), sz2 = (int)k2.size();
  std::queue<point> buf1, buf2;
  for (int i = 0; i < sz1; ++i) buf1.push(k1[(i + 1) % sz1] - k1[i]);
  for (int i = 0; i < sz2; ++i) buf2.push(k2[(i + 1) % sz2] - k2[i]);
  poly ret;
  ret.push_back(k1[0] + k2[0]);
  while (!buf1.empty() && !buf2.empty()) {
    point tmp1 = buf1.front(), tmp2 = buf2.front();
    if (Sgn(tmp1 ^ tmp2) > 0) {
      ret.push_back(ret.back() + tmp1);
      buf1.pop();
    }
    else {
      ret.push_back(ret.back() + tmp2);
      buf2.pop();
    }
  }
  while (!buf1.empty()) {
    ret.push_back(ret.back() + buf1.front());
    buf1.pop();
  }
  while (!buf2.empty()) {
    ret.push_back(ret.back() + buf2.front());
    buf2.pop();
  }
  return Grahamscan(ret);
}

bool IsIn(point p, const poly &ch) {
  point base = ch[0];
  if (Sgn((p - base) ^ (ch[1] - p)) > 0 || Sgn((p - base) ^ (ch.back() - base)) < 0) return false;
  if (Sgn((p - base) ^ (ch[1] - p)) == 0 && Cmp(GetLen(p - base), GetLen(ch[1] - base)) <= 0) return true;
  int idx = std::lower_bound(ch.begin(), ch.end(), p, [&] (point k1, point k2) { return Sgn((k1 - base) ^ (k2 - base)) > 0; }) - ch.begin() - 1;
  return Sgn((ch[idx + 1] - ch[idx]) ^ (p - ch[idx])) >= 0;
}

int main() {
  int n, m, q; scanf("%d%d%d", &n, &m, &q);
  std::vector<point> p1(n), p2(m);
  for (point &v : p1) scanf("%lf%lf", &v.x, &v.y);
  for (point &v : p2) {
    scanf("%lf%lf", &v.x, &v.y);
    v.x *= -1;
    v.y *= -1;
  }
  p1 = Grahamscan(p1);
  p2 = Grahamscan(p2);
  poly ch = Minkowski(p1, p2);
  for (int i = 0; i < q; ++i) {
    point vec; scanf("%lf%lf", &vec.x, &vec.y);
    if (IsIn(vec, ch)) printf("1\n");
    else printf("0\n");
  }
  return 0;
}

