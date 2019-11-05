#include <bits/stdc++.h>
const int inf = 7e5 + 5;
const int maxn = 1e3 + 5;

int t;
int n;
std::map<int, std::set<int>> map;

int main() {
  scanf("%d", &t);
  for (int cas = 1; cas <= t; ++cas) {
    map.clear();
    scanf("%d", &n);
    for (int i = 1, x, y; i <= n; ++i) {
      scanf("%d%d", &x, &y);
      map[x].emplace(y);
    }
    int sum = 0;
    for (auto &it : map) {
      int x = it.first;
      std::set<int> set = it.second;
      sum += set.size();
      if (sum * 2 == n) {
        printf("%d %d %d %d\n", x, -inf, x + 1, inf);
        break;
      }
      else if (sum * 2 > n) {
        int y;
        while (sum * 2 > n) {
          y = *set.begin();
          set.erase(set.begin());
          --sum;
        }
        printf("%d %d %d %d\n", x + 1, y + inf + 1, x - 1, y - inf);
        break;
      }
    }
  }
  return 0;
}