#include <bits/stdc++.h>

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int n, k;
  std::cin >> n >> k;
  std::vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    std::cin >> a[i];
  }
  std::sort(a.begin(), a.end());
  long long l = a[n / 2], r = a[n - 1] + k, ans;
  while (l <= r) {
    long long m = (l + r) / 2, cnt = 0;
    for (int i = n - 1; i >= n / 2; --i) {
      if (a[i] >= m) {
        continue;
      }
      cnt += m - a[i];
    }
    if (cnt > k) {
      r = m - 1;
    }
    else {
      ans = m;
      l = m + 1;
    }
  }
  std::cout << ans << '\n';
  return 0;
}

