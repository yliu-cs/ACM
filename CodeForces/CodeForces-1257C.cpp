#include <bits/stdc++.h>

const int N = 2e5 + 5;

int t, n, a[N], ans;
std::vector<int> idx[N];

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cin >> t;
  while (t--) {
    std::cin >> n;
    for (int i = 1; i <= n; ++i) {
      idx[i].clear();
    }
    for (int i = 1; i <= n; ++i) {
      std::cin >> a[i];
    }
    if (n < 2) {
      std::cout << -1 << '\n';
      continue;
    }
    for (int i = 1; i <= n; ++i) {
      idx[a[i]].push_back(i);
    }
    ans = N;
    for (int i = 1; i <= n; ++i) {
      for (int j = 0; j < (int)idx[i].size() - 1; ++j) {
        ans = std::min(ans, idx[i][j + 1] - idx[i][j] + 1);
      }
    }
    if (ans == N) {
      std::cout << -1 << '\n';
    }
    else {
      std::cout << ans << '\n';
    }
  }
  return 0;
}

