// Author: Tony5t4rk Time: 2019-10-16 22:44:24 
#include <bits/stdc++.h>
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int n;
  std::cin >> n;
  std::vector<int> a(n), b(n);
  for (auto &v : a) std::cin >> v;
  for (auto &v : b) std::cin >> v;
  std::queue<int> que;
  std::set<int> out, ans;
  for (int i = 0; i < n; ++i) {
    if (out.find(a[i]) == out.end()) que.push(a[i]);
    if (que.front() == b[i]) {
      que.pop();
      while (!que.empty() && out.find(que.front()) != out.end()) que.pop();
    }
    else if (!que.empty()) ans.insert(b[i]);
    out.insert(b[i]);
  }
  std::cout << ans.size() << '\n';
  return 0;
}
