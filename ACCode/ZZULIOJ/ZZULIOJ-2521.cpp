#include <bits/stdc++.h>

int main() {
  std::string str;
  bool first = true;
  while (std::cin >> str) {
    if (first) first = false;
    else std::cout << ' ';
    if (str == "henan") str[0] = 'H';
    std::cout << str;
  }
  return 0;
}

