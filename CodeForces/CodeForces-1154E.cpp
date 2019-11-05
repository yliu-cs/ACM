#include <bits/stdc++.h>

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr); std::cout.tie(nullptr);

  int n, k; std::cin >> n >> k;
  std::vector<int> arr(n + 1);
  std::vector<int> l(n + 2), r(n + 2);
  std::map<int, int> pos, rev;
  for (int i = 1; i <= n; ++i) {
    std::cin >> arr[i];
    pos[arr[i]] = i;
    l[i] = i - 1; r[i] = i + 1;
  }

  int max = n, cur = 1;
  std::vector<int> ans(n + 1, 0);
  std::vector<bool> vis(n + 1, false);
  while (max) {
    int m = pos[max];
    for (int t = 0; m && t <= k; ++t, m = l[m]) {
      vis[arr[m]] = true;
      ans[m] = cur;
    }
    int l_lim = m;
    m = pos[max];
    for (int t = 0; m <= n && t <= k; ++t, m = r[m]) {
      vis[arr[m]] = true;
      ans[m] = cur;
    }
    int r_lim = m;
    r[l_lim] = r_lim; l[r_lim] = l_lim;
    while (max >= 0 && vis[max]) --max;
    cur = cur == 1 ? 2 : 1;
  }

  for (int i = 1; i <= n; ++i) std::cout << ans[i];
  std::cout << '\n';
  return 0;
}

