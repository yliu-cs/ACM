// Author: Tony5t4rk Time: 2019-10-22 16:14:38 
#include <bits/stdc++.h>
const int N = 3e5 + 5;
int n;
int p[N], pos[N];
std::vector<std::pair<int, int>> ans;
void Transfer(int x, int y) {
  ans.push_back({x, y});
  std::swap(pos[p[x]], pos[p[y]]);
  std::swap(p[x], p[y]);
}
void Move(int ori, int tar) {
  if (2 * std::abs(tar - ori) >= n) Transfer(ori, tar);
  else if (ori * 2 <= n && tar * 2 <= n) {
    Transfer(ori, n);
    Transfer(tar, n);
    Transfer(ori, n);
  }
  else if (ori * 2 > n && tar * 2 > n) {
    Transfer(ori, 1);
    Transfer(tar, 1);
    Transfer(ori, 1);
  }
  else {
    Transfer(ori, 1);
    Transfer(1, n);
    Transfer(tar, n);
    Transfer(1, n);
    Transfer(ori, 1);
  }
}
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i) {
    scanf("%d", &p[i]);
    pos[p[i]] = i;
  }
  for (int i = 1; i <= n; ++i) {
    if (pos[i] == i) continue;
    Move(pos[i], i);
  }
//  for (int i = 1; i <= n; ++i) std::cerr << p[i] << ' ';
  std::cout << ans.size() << '\n';
  for (auto &v : ans) std::cout << v.first << ' ' << v.second << '\n';
  return 0;
}
