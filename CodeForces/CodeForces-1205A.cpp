// Author: Tony5t4rk Time: 2019-08-18 22:04:25 
#include <bits/stdc++.h>
int main() {
  int n;
  std::cin >> n;
  if (n % 2 == 0) {
    std::cout << "NO" << '\n';
    return 0;
  }
  std::vector<int> ans[2];
  int cur = 0, num = 1;
  for (int i = 0; i < n; ++i) {
    ans[cur].push_back(num++);
    ans[cur ^ 1].push_back(num++);
    cur ^= 1;
  }
  std::cout << "YES" << '\n';
  for (int &v : ans[0]) std::cout << v << ' ';
  for (int &v : ans[1]) std::cout << v << ' ';
  std::cout << '\n';
  return 0;
}
