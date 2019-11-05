#include <bits/stdc++.h>
#include <bits/extc++.h>

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr); std::cout.tie(nullptr);

  int t; std::cin >> t;
  for (int cas = 1; cas <= t; ++cas) {
    int n; std::cin >> n;
    std::string str; std::cin >> str;

    std::reverse(str.begin(), str.end());

    bool flag = false;
    for (int i = 10; i < (int)str.size(); ++i) {
      if (str[i] == '8') flag = true;
    }

    if (flag) std::cout << "YES" << '\n';
    else std::cout << "NO" << '\n';
  }
  return 0;
}

