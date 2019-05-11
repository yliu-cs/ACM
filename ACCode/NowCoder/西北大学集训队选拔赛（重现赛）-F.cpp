#include <bits/stdc++.h>
#include <bits/extc++.h>

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr); std::cout.tie(nullptr);

  int n; std::cin >> n;
  std::string str, id; std::cin >> str >> id;

  if (str == id) {
    std::cout << "no" << '\n';
    return 0;
  }

  std::map<char, int> str_cnt, id_cnt;
  for (char &c : str) ++str_cnt[c];
  for (char &c : id) ++id_cnt[c];

  if ((int)str_cnt.size() != (int)id_cnt.size()) {
    std::cout << "no" << '\n';
    return 0;
  }
  for (auto &v : str_cnt) {
    if (v.second != id_cnt[v.first]) {
      std::cout << "no" << '\n';
      return 0;
    }
  }
  std::cout << "yes" << '\n';
  return 0;
}

