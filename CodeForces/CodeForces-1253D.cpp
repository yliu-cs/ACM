#include <bits/stdc++.h>

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int n, m;
  std::cin >> n >> m;
  std::vector<int> pre(n);
  std::iota(pre.begin(), pre.end(), 0);
  std::function<int(int)> Find = [&](int x) {
    if (pre[x] == x) {
      return x;
    }
    pre[x] = Find(pre[x]);
    return pre[x];
  };
  auto Union = [&](int x, int y) {
    int xx = Find(x), yy = Find(y);
    if (xx != yy) {
      pre[std::min(xx, yy)] = std::max(xx, yy);
    }
  };
  for (int i = 0; i < m; ++i) {
    int u, v;
    std::cin >> u >> v;
    --u;
    --v;
    Union(u, v);
  }
  int ptr = 0, ans = 0;
  while (ptr < n) {
    int max = Find(ptr);
    for (int i = ptr + 1; i <= max; ++i) {
      if (Find(ptr) != Find(i)) {
        Union(ptr, i);
        ++ans;
        max = std::max(max, Find(ptr));
      }
    }
    ptr = max + 1;
  }
  std::cout << ans << '\n';
  return 0;
}

