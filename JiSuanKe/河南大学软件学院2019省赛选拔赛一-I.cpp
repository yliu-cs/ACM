#include <bits/stdc++.h>

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr); std::cout.tie(nullptr);

  std::deque<int> deque;
  int n; std::cin >> n;
  std::vector<int> arr(n);
  for (auto &v : arr) std::cin >> v;
  std::sort(arr.begin(), arr.end());

  bool flag = true;
  for (auto v : arr) {
    if (flag) deque.push_back(v);
    else deque.push_front(v);
    flag = !flag;
  }

  std::vector<int> check;
  while (!deque.empty()) {
    check.push_back(deque.front());
    deque.pop_front();
  }
  
  int ans = abs(check[0] - check.back());
  for (int i = 1; i < (int)check.size(); ++i) ans = std::max(ans, abs(check[i] - check[i - 1]));
  std::cout << ans << '\n';
  return 0;
}
