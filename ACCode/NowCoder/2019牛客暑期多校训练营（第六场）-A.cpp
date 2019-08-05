#include <bits/stdc++.h>
 
int main() {
  int t;
  std::cin >> t;
  for (int cas = 1; cas <= t; ++cas) {
    std::string s, t;
    std::cin >> s >> t;
    int cnt[3] = {0, 0, 0};
    std::map<int, int> clas;
    std::map<char, int> map;
    map['d'] = 0;
    map['w'] = 1;
    map['h'] = 2;
    for (int i = 0; i < 26; ++i) clas[i] = map[t[i]];
    int len = (int)s.length();
    for (int i = 0; i < len; ++i) ++cnt[clas[s[i] - 'a']];
    std::cout << "Case #" << cas << ": ";
    if (cnt[2] * 4 >= len) std::cout << "Harmful" << '\n';
    else if (cnt[2] * 10 <= len) std::cout << "Recyclable" << '\n';
    else if (cnt[1] * 2 <= cnt[0]) std::cout << "Dry" << '\n';
    else std::cout << "Wet" << '\n';
  }
  return 0;
}