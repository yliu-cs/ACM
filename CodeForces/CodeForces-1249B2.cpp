// Author: Tony5t4rk Time: 2019-10-23 13:34:36 
#include <bits/stdc++.h>
const int N = 2e5 + 5;
int t, n;
int p[N], pre[N];
int Find(int x) {
  return pre[x] == x ? x : pre[x] = Find(pre[x]);
}
void Union(int x, int y) {
  pre[Find(x)] = Find(y);
}
std::map<int, std::set<int>> map;
int main() {
  scanf("%d", &t);
  while (t--) {
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) pre[i] = i;
    for (int i = 1; i <= n; ++i) {
      scanf("%d", &p[i]);
      if (Find(i) != Find(p[i])) Union(i, p[i]);
    }
    map.clear();
    for (int i = 1; i <= n; ++i) map[Find(i)].insert(i);
    for (int i = 1; i <= n; ++i) printf("%d ", (int)map[Find(i)].size());
    printf("\n");
  }
  return 0;
}
