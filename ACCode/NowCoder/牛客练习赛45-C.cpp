#include <bits/stdc++.h>

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr); std::cout.tie(nullptr);

  int n; std::cin >> n;

  if ((n & 1) && n != 1) {
    std::cout << -1 << '\n';
    return 0;
  }

  std::vector<int> ans(n, 0);
  for (int i = 0, cur = n - 1; i < n / 2; ++i, cur -= 2) ans[i] = cur;
  ans[n / 2] = 0;
  for (int i = n / 2 + 1, cur = n - 2; i < n; ++i, cur -= 2) ans[i] = cur;

  for (int &v : ans) std::cout << v << ' ';
  std::cout << '\n';
  return 0;
}

