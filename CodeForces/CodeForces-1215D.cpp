// Author: Tony5t4rk Time: 2019-10-21 21:00:23 
#include <bits/stdc++.h>
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int n;
  std::string str;
  std::cin >> n >> str;
  std::vector<int> cnt(2, 0), sum(2, 0);
  for (int i = 0; i < n; ++i) {
    if (str[i] == '?') ++cnt[(i >= n / 2)];
    else sum[(i >= n / 2)] += (str[i] - '0');
  }
  if (cnt[0] >= cnt[1]) {
    std::swap(cnt[0], cnt[1]);
    std::swap(sum[0], sum[1]);
  }
  if (9 * ((cnt[1] - cnt[0]) / 2) == (sum[0] - sum[1])) std::cout << "Bicarp" << '\n';
  else std::cout << "Monocarp" << '\n';
  return 0;
}
