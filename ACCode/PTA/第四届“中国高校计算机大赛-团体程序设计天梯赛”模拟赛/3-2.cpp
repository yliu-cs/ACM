#include <bits/stdc++.h>
typedef double db;
const db eps = 1e-9;

int Sgn(db k) {return fabs(k) < eps ? 0 : (k < 0 ? -1 : 1);}
int Cmp(db k1, db k2) {return Sgn(k1 - k2);}
struct point {db x, y;};
point operator - (point k1, point k2) {return (point){k1.x - k2.x, k1.y - k2.y};}
point operator + (point k1, point k2) {return (point){k1.x + k2.x, k1.y + k2.y};}
db operator * (point k1, point k2) {return k1.x * k2.x + k1.y * k2.y;}
db operator ^ (point k1, point k2) {return k1.x * k2.y - k1.y * k2.x;}
struct line {point s, t;};
typedef line seg;
bool IsLineInterSeg(line k1, seg k2) {
  return Sgn((k2.s - k1.t) ^ (k1.s - k1.t)) * Sgn((k2.t - k1.t) ^ (k1.s - k1.t)) <= 0;
}

std::vector<seg> fru;
std::vector<point> p;

bool Check(line x) {
  for (auto &f : fru) {
    if (!IsLineInterSeg(x, f)) return false;
  }
  std::cout << (int)x.s.x << " " << (int)x.s.y << " " << (int)x.t.x << " " << (int)x.t.y;
  return true;
}

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0); std::cout.tie(0);

  int n; std::cin >> n;
  for (int i = 0; i < n; ++i) {
    db x, y1, y2; std::cin >> x >> y1 >> y2;
    p.emplace_back((point){x, y1});
    p.emplace_back((point){x, y2});
    fru.emplace_back((seg){(point){x, y1}, (point){x, y2}});
  }

  for (int i = 0; i < (int)p.size(); ++i) {
    for (int j = i + 1; j < (int)p.size(); ++j) {
      if (Check((line){p[i], p[j]})) return 0;
    }
  }
  return 0;
}
