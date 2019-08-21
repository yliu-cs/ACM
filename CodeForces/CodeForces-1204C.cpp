// Author: Tony5t4rk Time: 2019-08-20 23:03:23 
#include <bits/stdc++.h>
const int inf = 0x3f3f3f3f;
const int maxn = 1e2 + 5;
int dis[maxn][maxn];
void Floyd(int n) {
  for (int k = 1; k <= n; ++k)
    for (int i = 1; i <= n; ++i)
      for (int j = 1; j <= n; ++j)
        dis[i][j] = std::min(dis[i][j], dis[i][k] + dis[k][j]);
}
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int n; std::cin >> n;
  memset(dis, inf, sizeof(dis));
  for (int i = 1; i <= n; ++i) {
    std::string s;
    std::cin >> s;
    for (int j = 1; j <= n; ++j) {
      if (s[j - 1] == '1') dis[i][j] = 1;
    }
  }
  Floyd(n);
  int m; std::cin >> m;
  std::stack<int> path;
  for (int i = 0, x; i < m; ++i) {
    std::cin >> x;
    if (path.size() < 2) path.push(x);
    else {
      bool f = true;
      while (f && path.size() >= 2) {
        f = false;
        int m = path.top(); path.pop();
        int l = path.top(); path.pop();
        if (l != x && dis[l][x] == dis[l][m] + dis[m][x]) {
          path.push(l);
          f = true;
        }
        else {
          path.push(l);
          path.push(m);
        }
      }
      path.push(x);
    }
  }
  std::stack<int> ans;
  while (!path.empty()) {
    ans.push(path.top());
    path.pop();
  }
  std::cout << ans.size() << '\n';
  while (!ans.empty()) {
    std::cout << ans.top() << ' ';
    ans.pop();
  }
  std::cout << '\n';
  return 0;
}
