#include <bits/stdc++.h>

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr); std::cout.tie(nullptr);

  int n; std::cin >> n;
  std::string str; std::cin >> str;
  std::reverse(str.begin(), str.end());

  std::vector<int> pos;
  for (int i = 0; i < n; ++i) {
    if (str[i] == '8' && i >= 10) pos.push_back(i);
  }

  if (pos.empty() || (int)pos.size() <= (n - 11) / 2) {
    std::cout << "NO\n";
    return 0;
  }
  std::cout << "YES\n";
  return 0;
}

