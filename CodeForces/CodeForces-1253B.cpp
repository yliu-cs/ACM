#include <bits/stdc++.h>

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int n;
  std::cin >> n;
  std::vector<int> ans;
  long long pre = 0;
  std::set<int> set;
  for (int i = 0; i < n; ++i) {
    int x;
    std::cin >> x;
    if (x > 0) {
      if (set.find(x) != set.end()) {
        std::cout << -1 << '\n';
        return 0;
      }
      set.insert(x);
    }
    else {
      if (set.find(-x) == set.end()) {
        std::cout << -1 << '\n';
        return 0;
      }
    }
    pre += x;
    if (pre == 0) {
      ans.push_back(i + 1);
      set.clear();
    }
    else if (pre < 0) {
      std::cout << -1 << '\n';
      return 0;
    }
  }
  if (pre != 0) {
    std::cout << -1 << '\n';
    return 0;
  }
  std::cout << ans.size() << '\n';
  for (int i = 0; i < (int)ans.size(); ++i) {
    if (i == 0) {
      std::cout << ans[i] << ' ';
    }
    else {
      std::cout << ans[i] - ans[i - 1] << ' ';
    }
  }
  return 0;
}

