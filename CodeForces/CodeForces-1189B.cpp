#include <bits/stdc++.h>

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int n;
  std::cin >> n;
  std::vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    std::cin >> a[i];
  }
  std::sort(a.begin(), a.end());
  std::vector<int> ans(n);
  int l = 0, r = n - 1, ptr = 0;
  while (l <= r) {
    ans[l++] = a[ptr++];
    if (l > r) {
      break;
    }
    ans[r--] = a[ptr++];
  }
  for (int i = 0; i < n; ++i) {
    int l = ans[(i - 1 + n) % n], r = ans[(i + 1) % n];
    if (ans[i] >= l + r) {
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

