#include <bits/stdc++.h>

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int t;
  std::cin >> t;
  while (t--) {
    long long n;
    std::cin >> n;
    std::vector<int> vec;
    std::function<void(int)> Dfs = [&](int x) {
      if (x == 0) {
        return;
      }
      int ret = 0;
      for (int i = std::sqrt(2 * x) + 1; i > 0; --i) {
        if (i * (i - 1) / 2 <= x) {
          ret = i;
          break;
        }
      }
      Dfs(x - ret * (ret - 1) / 2);
      vec.push_back(ret);
    };
    Dfs(n);
    std::cout << "1";
    int pre = 0;
    for (auto &v : vec) {
      for (int i = 0; i < v - pre; ++i) {
        std::cout << "3";
      }
      std::cout << "7";
      pre = v;
    }
    std::cout << '\n';
  }
  return 0;
}

