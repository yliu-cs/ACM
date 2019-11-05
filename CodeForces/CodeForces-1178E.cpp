#include <bits/stdc++.h>
 
int main() {
  std::string str;
  std::cin >> str;
  int l = 0, r = (int)str.size() - 1;
  std::queue<char> ansl;
  std::stack<char> ansr;
  while (l < r) {
    if (r - l <= 2) {
      ansl.push(str[r]);
      break;
    }
    if (str[r] == str[l] || str[r - 1] == str[l]) {
      ansl.push(str[l]);
      ansr.push(str[l]);
    }
    else if (str[r] == str[l + 1] || str[r - 1] == str[l + 1]) {
      ansl.push(str[l + 1]);
      ansr.push(str[l + 1]);
    }
    l += 2;
    r -= 2;
  }
  while (!ansl.empty()) {
    std::cout << ansl.front();
    ansl.pop();
  }
  while (!ansr.empty()) {
    std::cout << ansr.top();
    ansr.pop();
  }
  return 0;
}