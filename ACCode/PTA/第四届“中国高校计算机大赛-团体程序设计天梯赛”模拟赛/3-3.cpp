#include <bits/stdc++.h>

std::set<std::string> ans;
std::string str;

void Dfs(int pos, int cnt, std::string cur) {
  if (pos == (int)str.size()) {
    ans.insert(cur);
    return;
  }
  if (cnt < 3) Dfs(pos + 1, cnt + 1, cur);
  Dfs(pos + 1, cnt, cur + str[pos]);
}

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0); std::cout.tie(0);

  std::cin >> str;

  Dfs(0, 0, "");

  std::cout << (int)ans.size() << '\n';
  return 0;
}
