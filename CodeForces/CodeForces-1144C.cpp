#include <bits/stdc++.h>

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0); std::cout.tie(0);

  int n; std::cin >> n;
  std::vector<int> arr(n);
  for (auto &it : arr) std::cin >> it;

  sort(arr.begin(), arr.end());

  std::set<int> vis1, vis2;
  std::vector<int> inc, dec;
  for (auto &it : arr) {
    if (vis1.find(it) == vis1.end()) {
      inc.emplace_back(it);
      vis1.insert(it);
    }
    else {
      if (vis2.find(it) == vis2.end()) {
        dec.emplace_back(it);
        vis2.insert(it);
      }
      else {
        std::cout << "NO" << '\n';
        return 0;
      }
    }
  }
  reverse(dec.begin(), dec.end());

  std::cout << "YES" << '\n';
  std::cout << (int)inc.size() << '\n';
  for (auto &it : inc) std::cout << it << " ";
  std::cout << '\n';
  std::cout << (int)dec.size() << '\n';
  for (auto &it : dec) std::cout << it << " ";
  std::cout << '\n';
  return 0;
}
