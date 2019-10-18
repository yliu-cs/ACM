// Author: Tony5t4rk Time: 2019-10-17 22:29:15 
#include <bits/stdc++.h>
const int N = 1e5 + 5;
const int M = 1e5 + 5;
int n, m, k;
std::vector<int> r[M], c[N];
bool Check() {
  int x = 1, y = 1, dir = 1;
  int minx = 1, maxx = n, miny = 1, maxy = m;
  bool f = true;
  long long cnt = 1;
  while (true) {
    if (dir == 1) {
      int right = r[x][std::lower_bound(r[x].begin(), r[x].end(), y) - r[x].begin()] - 1;
      right = std::min(right, maxy);
      minx = x + 1;
      if (right == y && !f) break;
      else {
        cnt += right - y;
        y = right;
      }
    }
    else if (dir == 2) {
      int bottom = c[y][std::lower_bound(c[y].begin(), c[y].end(), x) - c[y].begin()] - 1;
      bottom = std::min(bottom, maxx);
      maxy = y - 1;
      if (bottom == x) break;
      else {
        cnt += bottom - x;
        x = bottom;
      }
    }
    else if (dir == 3) {
      int left = r[x][std::lower_bound(r[x].begin(), r[x].end(), y) - r[x].begin() - 1] + 1;
      left = std::max(left, miny);
      maxx = x - 1;
      if (left == y) break;
      else {
        cnt += y - left;
        y = left;
      }
    }
    else if (dir == 4) {
      int top = c[y][std::lower_bound(c[y].begin(), c[y].end(), x) - c[y].begin() - 1] + 1;
      top = std::max(top, minx);
      miny = y + 1;
      if (top == x) break;
      else {
        cnt += x - top;
        x = top;
      }
    }
    f = false;
    dir = dir == 4 ? 1 : (dir + 1);
  }
  return cnt == 1ll * n * m - k;
}
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cin >> n >> m >> k;
  for (int i = 1; i <= k; ++i) {
    int x, y;
    std::cin >> x >> y;
    r[x].push_back(y);
    c[y].push_back(x);
  }
  for (int i = 1; i <= n; ++i) {
    r[i].push_back(0);
    r[i].push_back(m + 1);
    std::sort(r[i].begin(), r[i].end());
  }
  for (int i = 1; i <= m; ++i) {
    c[i].push_back(0);
    c[i].push_back(n + 1);
    std::sort(c[i].begin(), c[i].end());
  }
  if (Check()) std::cout << "Yes" << '\n';
  else std::cout << "No" << '\n';
  return 0;
}
