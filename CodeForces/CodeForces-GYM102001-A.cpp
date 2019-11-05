#include <bits/stdc++.h>

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0); std::cout.tie(0);

  std::string str; std::cin >> str;
  int max = 0, cnt0 = str[0] == '0', cnt1 = str[0] == '1'; char c;
  for (int i = 1, cur = 1; i < (int)str.length(); ++i) {
    if (str[i] == str[i - 1]) cur++;
    else cur = 1;
    if (cur > max) {
      max = cur;
      c = str[i];
    }
    cnt0 += str[i] == '0';
    cnt1 += str[i] == '1';
  }

  if (max == 1) {
    if (str[0] == '0') {
      std::cout << 1;
      for (int i = 1; i < (int)str.length(); ++i) std::cout << 0;
      std::cout << '\n';
    }
    else {
      std::cout << 0;
      for (int i = 1; i < (int)str.length(); ++i) std::cout << 1;
      std::cout << '\n';
    }
  }
  else if (max > (int)str.length() / 2) {
    if (c == '0') {
      for (int i = 0; i < (int)str.length(); ++i) std::cout << 1;
      std::cout << '\n';
    }
    else {
      for (int i = 0; i < (int)str.length(); ++i) std::cout << 0;
      std::cout << '\n';
    }
  }
  else if (cnt0 > (int)str.length() / 2) {
      for (int i = 0; i < (int)str.length(); ++i) std::cout << 1;
      std::cout << '\n';
  }
  else if (cnt1 > (int)str.length() / 2) {
    for (int i = 0; i < (int)str.length(); ++i) std::cout << 0;
    std::cout << '\n';
  }
  else if (max == (int)str.length() / 2) {
    if (c == '0') {
      for (int i = 0; i < (int)str.length() - 1; ++i) std::cout << 1;
      std::cout << 0;
      std::cout << '\n';
    }
    else {
      for (int i = 0; i < (int)str.length() - 1; ++i) std::cout << 0;
      std::cout << 1;
      std::cout << '\n';
    }
  }
  else {
    if (str[0] == '0') {
      std::cout << 1;
      for (int i = 0; i < (int)str.length() - 1; ++i) std::cout << 0;
      std::cout << '\n';
    }
    else {
      std::cout << 0;
      for (int i = 0; i < (int)str.length() - 1; ++i) std::cout << 1;
      std::cout << '\n';
    }
  }
  return 0;
}
