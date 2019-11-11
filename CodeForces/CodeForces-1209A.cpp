#include <bits/stdc++.h>

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int n;
  std::cin >> n;
  std::vector<int> a(n);
  for (auto &v : a) {
    std::cin >> v;
  }
  std::sort(a.begin(), a.end());
  std::vector<int> col(n, -1);
  int tot = 0;
  for (int i = 0; i < n; ++i) {
    if (col[i] != -1) {
      continue;
    }
    ++tot;
    for (int j = i; j < n; ++j) {
      if (a[j] % a[i] == 0) {
        col[j] = tot;
      }
    }
  }
  std::cout << tot << '\n';
  return 0;
}

