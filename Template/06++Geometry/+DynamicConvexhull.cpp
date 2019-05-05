// CodeForces 70D 动态凸包
#include <bits/stdc++.h>
typedef double db;
const int maxn = 1e5 + 5;
const db eps = 1e-9;
int Sgn(db k) { return fabs(k) < eps ? 0 : (k < 0 ? -1 : 1); }
int Cmp(db k1, db k2) { return Sgn(k1 - k2); }

struct point { db x, y; };
point operator - (point k1, point k2) { return (point){k1.x - k2.x, k1.y - k2.y}; }
point operator + (point k1, point k2) { return (point){k1.x + k2.x, k1.y + k2.y}; }
db operator * (point k1, point k2) { return k1.x * k2.x + k1.y * k2.y; }
db operator ^ (point k1, point k2) { return k1.x * k2.y - k1.y * k2.x; }
db GetLen(point k) { return sqrt(k * k); }

int n;
point basic;
point p[maxn];
std::set<point> set;

bool operator < (point k1, point k2) {
  k1 = k1 - basic; k2 = k2 - basic;
  db Ang1 = atan2(k1.y, k1.x), Ang2 = atan2(k2.y, k2.x);
  db Len1 = GetLen(k1), Len2 = GetLen(k2);
  if (Cmp(Ang1, Ang2) != 0) return Cmp(Ang1, Ang2) < 0;
  return Cmp(Len1, Len2) < 0;
}

std::set<point>::iterator Prev(std::set<point>::iterator k) {
  if (k == set.begin()) k = set.end();
  return --k;
}

std::set<point>::iterator Next(std::set<point>::iterator k) {
  ++k;
  return k == set.end() ? set.begin() : k;
}

bool Query(point k) {
  std::set<point>::iterator it = set.lower_bound(k);
  if (it == set.end()) it = set.begin();
  return Sgn((k - *(Prev(it))) ^ (*(it) - *(Prev(it)))) <= 0;
}

void Insert(point k) {
  if (Query(k)) return;
  set.insert(k);
  std::set<point>::iterator cur = Next(set.find(k));
  while (set.size() > 3 && Sgn((k - *(Next(cur))) ^ (*(cur) - *(Next(cur)))) <= 0) {
    set.erase(cur);
    cur = Next(set.find(k));
  }
  cur = Prev(set.find(k));
  while (set.size() > 3 && Sgn((k - *(cur)) ^ (*(cur) - *(Prev(cur)))) >= 0) {
    set.erase(cur);
    cur = Prev(set.find(k));
  }
}

int main() {
  scanf("%d", &n);
  basic.x = basic.y = 0.0;
  for (int i = 1, T; i <= 3; ++i) {
    scanf("%d%lf%lf", &T, &p[i].x, &p[i].y);
    basic.x += p[i].x; basic.y += p[i].y;
  }
  basic.x /= 3.0; basic.y /= 3.0;
  for (int i = 1; i <= 3; ++i) set.insert(p[i]);
  for (int i = 4, T; i <= n; ++i) {
    scanf("%d%lf%lf", &T, &p[i].x, &p[i].y);
    if (T == 1) Insert(p[i]);
    else {
      if (Query(p[i])) printf("YES\n");
      else printf("NO\n");
    }
  }
  return 0;
}