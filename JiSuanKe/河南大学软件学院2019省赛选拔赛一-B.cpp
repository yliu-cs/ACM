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
db GetDisP2P(point k1, point k2) {return sqrt((k2 - k1) * (k2 - k1));}
db GetAng(point k1, point k2) {return fabs(atan2(fabs(k1 ^ k2), k1 * k2));}
typedef std::vector<point> poly;

bool IsConvexhull(std::vector<point> &p) {
  int n = (int)p.size();
  for (int i = 0; i < n; ++i) {
    if (Sgn((p[(i + 1) % n] - p[i]) ^ (p[(i + 2) % n] - p[(i + 1) % n])) < 0) return false;
  }
  return true;
}

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr); std::cout.tie(nullptr);

  int t; std::cin >> t;
  for (int cas = 1; cas <= t; ++cas) {
    int n; std::cin >> n;
    std::vector<point> p(n);
    for (auto &v : p) std::cin >> v.x >> v.y;

    int low = 0;
    for (int i = 0; i < n; ++i)
      if (Cmp(p[i].x, p[low].x) < 0 || (Cmp(p[i].x, p[low].x) == 0 && Cmp(p[i].y, p[low].y) < 0))
        low = i;
    std::swap(p[0], p[low]);
    std::sort(p.begin() + 1, p.end(), [&](point k1, point k2) {
      db tmp = ((k1 - p[0]) ^ (k2 - p[0]));
      if (Sgn(tmp) > 0) return true;
      else if (Sgn(tmp) == 0 && Cmp(GetDisP2P(k2, p[0]), GetDisP2P(k1, p[0])) > 0) return true;
      return false;
    });

    if (!IsConvexhull(p)) {
      std::cout << "NO" << '\n';
      continue;
    }

    bool flag = true;
    db len = GetDisP2P(p[1], p[0]), ang = GetAng(p[0] - p[1], p[2] - p[1]);
    for (int i = 1; i < n - 1; ++i) {
      if (Cmp(GetDisP2P(p[i], p[i - 1]), len) != 0 || Cmp(GetAng(p[i - 1] - p[i], p[i + 1] - p[i]), ang) != 0) {
        flag = false;
        break;
      }
    }
    if (Cmp(GetDisP2P(p[0], p.back()), len) != 0 || Cmp(GetAng(p[1] - p[0], p.back() - p[0]), ang) != 0) {
      flag = false;
    }
    if (flag) std::cout << "YES" << '\n';
    else std::cout << "NO" << '\n';
  }
  return 0;
}
