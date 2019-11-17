#include <bits/stdc++.h>

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int t;
  std::cin >> t;
  while (t--) {
    int n;
    std::cin >> n;
    std::vector<int> a(n);
    for (int i = 0; i < n; ++i) {
      std::cin >> a[i];
    }
    std::vector<int> b(n);
    for (int i = 0; i < n; ++i) {
      std::cin >> b[i];
    }
    int l = -1, r = -1;
    for (int i = 0; i < n; ++i) {
      if (a[i] != b[i]) {
        if (l == -1) {
          l = i;
        }
        r = i;
      }
    }
    if (l == -1) {
      std::cout << "YES" << '\n';
      continue;
    }
    int k = b[l] - a[l];
    if (k < 0) {
      std::cout << "NO" << '\n';
      continue;
    }
    for (int i = l; i <= r; ++i) {
      a[i] += k;
    }
    bool f = true;
    for (int i = 0; i < n; ++i) {
      if (a[i] != b[i]) {
        f = false;
      }
    }
    if (f) {
      std::cout << "YES" << '\n';
    }
    else {
      std::cout << "NO" << '\n';
    }
  }
  return 0;
}

