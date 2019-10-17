// Author: Tony5t4rk Time: 2019-10-17 00:11:22 
#include <bits/stdc++.h>
const int inf = 1e9 + 5;
int n;
struct Point {
  int x, y, z, id;
};
bool operator < (const Point &k1, const Point k2) {
  if (k1.x != k2.x) return k1.x < k2.x;
  if (k1.y != k2.y) return k1.y < k2.y;
  if (k1.z != k2.z) return k1.z < k2.z;
  return k1.id < k2.id;
}
std::set<Point> set;
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int n;
  std::cin >> n;
  for (int i = 0, x, y, z; i < n; ++i) {
    std::cin >> x >> y >> z;
    set.insert((Point){x, y, z, i + 1});
  }
  for (int i = 0; i < n / 2; ++i) {
    Point base = *set.begin(), ans = (Point){inf, inf, inf, 0};
    set.erase(set.begin());
    std::vector<Point> vec;
    for (auto &p : set) if (p.x == (*set.begin()).x) {
      if (std::abs(p.y - base.y) < std::abs(ans.y - base.y)) ans = p;
      else if (std::abs(p.y - base.y) == std::abs(ans.y - base.y)) {
        if (std::abs(p.z - base.z) < std::abs(ans.z - base.z)) ans = p;
      }
      else break;
    }
    std::cout << base.id << ' ' << ans.id << '\n';
    set.erase(ans);
  }
  return 0;
}
