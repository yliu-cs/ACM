// Author: Tony5t4rk Time: 2019-10-20 17:15:36 
#include <bits/stdc++.h>
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int n;
  std::cin >> n;
  std::vector<int> a(n);
  for (auto &v : a) std::cin >> v;
  std::sort(a.begin(), a.end());
  long long w = 0, h = 0;
  for (int i = 0; i < n; ++i) {
    if (i < n / 2) h += a[i];
    else w += a[i];
  }
  std::cout << h * h + w * w << '\n';
  return 0;
}
