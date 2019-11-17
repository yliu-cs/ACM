#include <bits/stdc++.h>

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int n, m;
  std::cin >> n >> m;
  std::vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    std::cin >> a[i];
  }
  std::sort(a.begin(), a.end());
  std::vector<long long> sum(m);
  std::vector<long long> ans(n, 0);
  for (int i = 0; i < n; ++i) {
    if (i != 0) {
      ans[i] = ans[i - 1];
    }
    sum[i % m] += a[i];
    ans[i] += sum[i % m];
  }
  for (int i = 0; i < n; ++i) {
    std::cout << ans[i] << ' ';
  }
  std::cout << '\n';
  return 0;
}

