#include <bits/stdc++.h>

int main() {
  std::string str;
  getline(std::cin, str);
  std::string cur;
  for (char c : str) {
    if (c == ' ') {
      if (cur == "henan") cur[0] = 'H';
      std::cout << cur << ' ';
      cur.clear();
    }
    else cur += c;
  }
  if (!cur.empty()) {
    if (cur == "henan") cur[0] = 'H';
    std::cout << cur;
  }
  return 0;
}
