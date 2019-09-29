#include <bits/stdc++.h>
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.setf(std::ios::fixed);
  std::cout.precision(15);
  int n;
  std::cin >> n;
  std::vector<std::pair<long long, long long>> stu(n);
  for (auto &v : stu) std::cin >> v.first;
  for (auto &v : stu) std::cin >> v.second;
  std::map<long long, std::multiset<long long>> map;
  for (auto &v : stu) map[v.first].insert(v.second);
  std::vector<long long> a;
  std::vector<std::pair<long long, long long>> vec;
  long long ans = 0;
  for (auto &pr : map) {
    if (pr.second.size() > 1) {
      a.push_back(pr.first);
      for (auto &v : pr.second) ans += v;
    }
    else vec.push_back({pr.first, *pr.second.begin()});
  }
  auto Check = [](long long k1, long long k2) {
    while (k1 || k2) {
      if (!(k1 & 1) && (k2 & 1)) return false;
      k1 >>= 1;
      k2 >>= 1;
    }
    return true;
  };
  for (auto &pr : vec) {
    for (auto &v : a) {
      if (Check(v, pr.first)) {
        ans += pr.second;
        break;
      }
    }
  }
  std::cout << ans << '\n';
  return 0;
}
