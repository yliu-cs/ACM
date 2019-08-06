#include <bits/stdc++.h>


int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr); std::cout.tie(nullptr);

  std::string str, art;
  std::vector<std::pair<std::string, int>> vec;
  while (getline(std::cin, str)) {
    if (str == "\\begin{thebibliography}{99}") {
      vec.push_back({str, (int)vec.size()});
      break;
    }
    art += str;
  }

  int tot = 0; bool flag = false;
  std::string name;
  std::map<std::string, int> order;
  for (auto &c : art) {
    if (c == '{') {
      flag = true;
      name.clear();
      continue;
    }
    if (c == '}') {
      order[name] = ++tot;
      flag = false;
    }
    if (flag) name += c;
  }

  bool suc = true;
  while (getline(std::cin, str)) {
    if (str == "\\end{thebibliography}") {
      vec.push_back({str, (int)vec.size()});
      break;
    }
    std::string name; flag = false;
    for (auto &c : str) {
      if (c == '{') {
        flag = true;
        continue;
      }
      if (c == '}') {
        if (order[name] != (int)vec.size()) suc = false;
        vec.push_back({str, order[name]});
        flag = false;
      }
      if (flag) name += c;
    }
  }

  if (suc) {
    std::cout << "Correct" << '\n';
    return 0;
  }

  std::cout << "Incorrect" << '\n';
  std::sort(vec.begin(), vec.end(), [&](std::pair<std::string, int> k1, std::pair<std::string, int> k2) {
    return k1.second < k2.second;
  });
  for (auto &s : vec) std::cout << s.first << '\n';
  return 0;
}

