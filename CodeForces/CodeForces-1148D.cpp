// Author: Tony5t4rk Time: 2019-10-22 16:53:13 
#include <bits/stdc++.h>
struct pair {
  int x, y, id;
};
bool operator < (const pair &k1, const pair &k2) {
  return k1.y < k2.y;
}
bool operator > (const pair &k1, const pair &k2) {
  return k1.y > k2.y;
}
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int n;
  std::cin >> n;
  std::priority_queue<pair, std::vector<pair>, std::less<pair>> de;
  std::priority_queue<pair, std::vector<pair>, std::greater<pair>> in;
  for (int i = 0, x, y; i < n; ++i) {
    std::cin >> x >> y;
    if (x < y) de.push((pair){x, y, i + 1});
    else in.push((pair){x, y, i + 1});
  }
  std::vector<pair> ans;
  while (!de.empty()) {
    if (ans.empty()) {
      ans.push_back(de.top());
      de.pop();
      continue;
    }
    if (de.top().x < ans.back().y) ans.push_back(de.top());
    de.pop();
  }
  std::vector<pair> buf;
  while (!in.empty()) {
    if (buf.empty()) {
      buf.push_back(in.top());
      in.pop();
      continue;
    }
    if (in.top().x > buf.back().y) buf.push_back(in.top());
    in.pop();
  }
  if (buf.size() > ans.size()) ans = buf;
  std::cout << ans.size() << '\n';
  for (auto &v : ans) std::cout << v.id << ' ';
  std::cout << '\n';
  return 0;
}
