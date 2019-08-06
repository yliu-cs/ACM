#include <bits/stdc++.h>
typedef double db;
const db eps = 1e-9;

int Sgn(db x) {return fabs(x) < eps ? 0 : (x < 0 ? -1 : 1);}
int Cmp(db k1, db k2) {return Sgn(k1 - k2);}

struct point {db x, y;};
point operator - (point k1, point k2) {return (point){k1.x - k2.x, k1.y - k2.y};}
point operator + (point k1, point k2) {return (point){k1.x + k2.x, k1.y + k2.y};}
db operator * (point k1, point k2) {return k1.x * k2.x + k1.y * k2.y;}
db operator ^ (point k1, point k2) {return k1.x * k2.y - k1.y * k2.x;}
point operator * (point k1, db k2) {return (point){k1.x * k2, k1.y * k2};}
point operator / (point k1, db k2) {return (point){k1.x / k2, k1.y / k2};}
db GetDisP2P(point k1, point k2) {return sqrt((k1 - k2) * (k1 - k2));}
struct circle {point o; db r;};

circle GetCircle(point k1, point k2, point k3) {
  db a1 = k2.x - k1.x, b1 = k2.y - k1.y, c1 = (a1 * a1 + b1 * b1) / 2;
  db a2 = k3.x - k1.x, b2 = k3.y - k1.y, c2 = (a2 * a2 + b2 * b2) / 2;
  db d = a1 * b2 - a2 * b1;
  point o = (point){k1.x + (c1 * b2 - c2 * b1) / d, k1.y + (a1 * c2 - a2 * c1) / d};
  return (circle){o, GetDisP2P(k1, o)};
}

circle MinCircle(std::vector<point> p) {
  random_shuffle(p.begin(), p.end());
  int n = (int)p.size();
  circle ret = (circle){p[0], 0.0};
  for (int i = 1; i < n; ++i) {
    if (Cmp(GetDisP2P(ret.o, p[i]), ret.r) <= 0) continue;
    ret = (circle){p[i], 0.0};
    for (int j = 0; j < i; ++j) {
      if (Cmp(GetDisP2P(ret.o, p[j]), ret.r) <= 0) continue;
      ret.o = (p[i] + p[j]) / 2; ret.r = GetDisP2P(ret.o, p[i]);
      for (int k = 0; k < j; ++k) {
        if (Cmp(GetDisP2P(ret.o, p[k]), ret.r) <= 0) continue;
        ret = GetCircle(p[i], p[j], p[k]);
      }
    }
  }
  return ret;
}

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr); std::cout.tie(nullptr);
  std::cout << std::fixed << std::setprecision(9);

  freopen("robots.in", "r", stdin);

  int t; std::cin >> t;
  for (int cas = 1; cas <= t; ++cas) {
    int n; db R, r; std::cin >> n >> R >> r;
    std::vector<point> p;
    p.push_back((point){0.0, 0.0});
    for (int i = 1; i <= n; ++i) {
      db x, y; std::cin >> x >> y;
      p.push_back(p.back() + (point){x, y});
    }
    
    circle o = MinCircle(p);

    std::cout << -o.o.x << " " << -o.o.y << '\n';
  }
  return 0;
}
