#include <bits/stdc++.h>
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.setf(std::ios::fixed);
  std::cout.precision(15);
  std::vector<int> bag(4);
  for (auto &v : bag) std::cin >> v;
  std::sort(bag.begin(), bag.end());
  if (bag[0] + bag[3] == bag[1] + bag[2]) std::cout << "YES\n";
  else if (bag[0] + bag[1] + bag[2] == bag[3]) std::cout << "YES\n";
  else std::cout << "NO\n";
  return 0;
}
