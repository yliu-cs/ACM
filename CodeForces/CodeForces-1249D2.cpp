// Author: Tony5t4rk Time: 2019-10-23 22:57:35 
#include <bits/stdc++.h>
const int N = 2e5 + 5;
int n, k;
std::pair<int, int> seg[N];
std::vector<int> add[N], sub[N];
struct Node { int r, id; };
bool operator < (const Node &k1, const Node &k2) {
  if (k1.r != k2.r) return k1.r < k2.r;
  return k1.id < k2.id;
}
std::set<Node> set;
std::vector<int> ans;
int main() {
  scanf("%d%d", &n, &k);
  for (int i = 1; i <= n; ++i) {
    scanf("%d%d", &seg[i].first, &seg[i].second);
    add[seg[i].first].push_back(i);
    sub[seg[i].second + 1].push_back(i);
  }
  for (int i = 1; i < N; ++i) {
    for (auto &v : add[i]) set.insert((Node){seg[v].second, v});
    for (auto &v : sub[i]) set.erase((Node){seg[v].second, v});
    while ((int)set.size() > k) {
      auto it = set.end();
      it = std::prev(it);
      ans.push_back((*it).id);
      set.erase(it);
    }
  }
  printf("%d\n", (int)ans.size());
  for (auto &v : ans) printf("%d ", v);
  return 0;
}
