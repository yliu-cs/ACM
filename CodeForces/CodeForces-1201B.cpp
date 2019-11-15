#include <bits/stdc++.h>

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int n;
  std::cin >> n;
  std::vector<int> a(n);
  long long sum = 0;
  for (int i = 0; i < n; ++i) {
    std::cin >> a[i];
    sum += a[i];
  }
  if (sum & 1) {
    std::cout << "NO" << '\n';
    return 0;
  }
  std::sort(a.begin(), a.end());
  sum -= a[n - 1];
  if (sum >= a[n - 1]) {
    std::cout << "YES" << '\n';
  }
  else {
    std::cout << "NO" << '\n';
  }
  return 0;
}

