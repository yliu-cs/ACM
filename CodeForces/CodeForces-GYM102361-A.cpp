// Author: Tony5t4rk Time: 2019-10-02 15:24:45 
#include <bits/stdc++.h>
struct Point {
  long long x, y;
  Point Base() {
    if (x < 0 || (x == 0 && y < 0)) return (Point){-x, -y};
    return (Point){x, y};
  }
};
Point operator - (Point k1, Point k2) { return (Point){k1.x - k2.x, k1.y - k2.y}; }
long long operator ^ (Point k1, Point k2) { return k1.x * k2.y - k1.y * k2.x; }
bool operator < (Point k1, Point k2) {
  k1 = k1.Base(); k2 = k2.Base();
  return (k1 ^ k2) < 0;
}
Point Rotate90(Point k) { return (Point){-k.y, k.x}; }
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int n, m;
  std::cin >> n >> m;
  std::vector<Point> pt(n), qry(m);
  for (auto &p : pt) std::cin >> p.x >> p.y;
  for (auto &p : qry) std::cin >> p.x >> p.y;
  std::map<Point, int> map;
  std::vector<int> ans(m, 0);
  for (int i = 0; i < m; ++i) {
    map.clear();
    for (int j = 0; j < n; ++j) ++map[pt[j] - qry[i]];
    for (int j = 0; j < n; ++j) {
      Point p = Rotate90(pt[j] - qry[i]);
      ans[i] += map.find(p) != map.end() ? map[p] : 0;
    }
    ans[i] /= 2;
  }
  for (int i = 0; i < n; ++i) {
    map.clear();
    for (int j = 0; j < n; ++j) if (i != j) ++map[pt[j] - pt[i]];
    for (int j = 0; j < m; ++j) {
      Point p = Rotate90(qry[j] - pt[i]);
      ans[j] += map.find(p) != map.end() ? map[p] : 0;
    }
  }
  for (int i = 0; i < m; ++i) std::cout << ans[i] << '\n';
  return 0;
}
