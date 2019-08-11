// Author: Tony5t4rk Time: 2019-08-11 20:35:13 
#include <bits/stdc++.h>

int main() {
  int n;
  std::cin >> n;
  std::string str;
  std::cin >> str;
  std::vector<int> ans(10, 0);
  for (char &c : str) {
    if (c == 'L') {
      for (int i = 0; i < 10; ++i) {
        if (ans[i] == 0) {
          ans[i] = 1;
          break;
        }
      }
    }
    else if (c == 'R') {
      for (int i = 9; i >= 0; --i) {
        if (ans[i] == 0) {
          ans[i] = 1;
          break;
        }
      }
    }
    else {
      ans[c - '0'] = 0;
    }
  }
  for (int &v : ans) std::cout << v;
  std::cout << '\n';
  return 0;
}

