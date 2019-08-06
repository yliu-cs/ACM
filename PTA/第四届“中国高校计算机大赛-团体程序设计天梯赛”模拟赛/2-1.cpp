#include <bits/stdc++.h>

int main() {
  struct node {int pos, v, next;};
  std::vector<node> l1, l2;
  std::map<int, int> pos;
  int s, n; scanf("%d%d", &s, &n);
  std::vector<node> init(n);
  for (int i = 0; i < n; ++i) {
    scanf("%d%d%d", &init[i].pos, &init[i].v, &init[i].next);
    pos[init[i].pos] = i;
  }
  std::set<int> vis;
  int cur = s;
  for (int i = 0; i < n && cur != -1; ++i) {
    if (vis.find(abs(init[pos[cur]].v)) == vis.end()) {
      l1.emplace_back(init[pos[cur]]);
      vis.insert(abs(init[pos[cur]].v));
    }
    else {
      l2.emplace_back(init[pos[cur]]);
    }
    cur = init[pos[cur]].next;
  }
  for (int i = 0; i < (int)l1.size(); ++i) {
    printf("%05d %d ", l1[i].pos, l1[i].v);
    if (i == (int)l1.size() - 1) printf("-1\n");
    else printf("%05d\n", l1[i + 1].pos);
  }
  for (int i = 0; i < (int)l2.size(); ++i) {
    printf("%05d %d ", l2[i].pos, l2[i].v);
    if (i == (int)l2.size() - 1) printf("-1\n");
    else printf("%05d\n", l2[i + 1].pos);
  }
  return 0;
}
