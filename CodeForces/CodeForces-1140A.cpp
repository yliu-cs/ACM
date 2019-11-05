#include <bits/stdc++.h>

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0); std::cout.tie(0);

  int n; std::cin >> n;
  std::vector<int> a(n);
  for (auto &it : a) {
    std::cin >> it;
    --it;
  }

  int flag = 0, cnt = 0;
  for (int i = 0; i < n; ++i) {
    flag = std::max(flag, a[i]);
    if (flag <= i) cnt++;
  }
  
  std::cout << cnt << '\n';
  return 0;
}
