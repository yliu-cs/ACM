#include <bits/stdc++.h>

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int n, m;
  std::cin >> n >> m;
  std::vector<std::vector<std::pair<int, int>>> fact(2);
  for (int i = 0; i < m; ++i) {
    int t, l, r;
    std::cin >> t >> l >> r;
    --l;
    --r;
    fact[t].push_back({l, r});
  }
  std::vector<int> ans(n, -1);
  std::sort(fact[1].begin(), fact[1].end());
  for (auto &pr : fact[1]) {
    int l = pr.first, r = pr.second;
    if (ans[l] == -1) {
      ans[l] = n - l;
    }
    for (int i = l + 1; i <= r; ++i) {
      ans[i] = ans[i - 1];
    }
  }
  for (int i = 0; i < n; ++i) {
    if (ans[i] == -1) {
      ans[i] = n - i;
    }
  }
  std::sort(fact[0].begin(), fact[0].end());
  for (auto &pr : fact[0]) {
    int l = pr.first, r = pr.second;
    bool f = false;
    for (int i = l + 1; i <= r; ++i) {
      if (ans[i] < ans[i - 1]) {
        f = true;
        break;
      }
    }
    if (!f) {
      std::cout << "NO" << '\n';
      return 0;
    }
  }
  std::cout << "YES" << '\n';
  for (int i = 0; i < n; ++i) {
    std::cout << ans[i] << ' ';
  }
  std::cout << '\n';
  return 0;
}

