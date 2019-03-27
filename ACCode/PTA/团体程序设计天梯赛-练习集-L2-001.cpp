#include <bits/stdc++.h>

int n;
std::vector<int> m, f;
struct node {int v, l, r;};
int tot;
std::vector<node> t;

int Build(int l1, int r1, int l2, int r2) {
  int cur = tot++;
  t[cur].v = f[l2];
  for (int i = l1; i <= r1; ++i) {
    if (m[i] == f[l2]) {
      if (i - 1 >= l1) t[cur].l = Build(l1, i - 1, l2 + 1, l2 + i - l1);
      if (r1 >= i + 1) t[cur].r = Build(i + 1, r1, l2 + i + 1 - l1, r2);
      break;
    }
  }
  return cur;
}

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0); std::cout.tie(0);
  
  std::cin >> n;
  m.resize(n); f.resize(n);
  t.assign(n, (node){-1, -1, -1});
  for (auto &it : m) std::cin >> it;
  for (auto &it : f) std::cin >> it;

  Build(0, n - 1, 0, n - 1);

  std::queue<int> que;
  que.push(0);
  bool first = true;
  while (!que.empty()) {
    int cur = que.front(); que.pop();
    if (!first) std::cout << " ";
    std::cout << t[cur].v;
    if (first) first = false;
    if (t[cur].r != -1) que.push(t[cur].r);
    if (t[cur].l != -1) que.push(t[cur].l);
  }
  return 0;
}
