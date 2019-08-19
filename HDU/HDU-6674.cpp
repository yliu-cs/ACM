#include <bits/stdc++.h>
int GetSum(int x) {
  int ret = 0;
  while (x) {
    ret += x % 10;
    x /= 10;
  }
  return ret;
}
int main() {
  int t;
  std::cin >> t;
  for (int cas = 1; cas <= t; ++cas) {
    int v;
    std::cin >> v;
    int sum = GetSum(v);
    std::vector<int> ans;
    for (int i = 1; i <= sum; ++i) {
      if (sum % i == 0 && v % i == 0) ans.push_back(i);
    }
    std::cout << ans.size() << '\n';
    std::cout << ans[0];
    for (int i = 1; i < ans.size(); ++i) {
      std::cout << ' ' << ans[i];
    }
    std::cout << '\n';
  }
  return 0;
}
