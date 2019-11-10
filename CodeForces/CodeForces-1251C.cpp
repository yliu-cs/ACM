#include <bits/stdc++.h>

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  auto Get = [&](char x) {
    return (int)(x - '0');
  };
  int t;
  std::cin >> t;
  while (t--) {
    std::string s;
    std::cin >> s;
    std::queue<int> que[2];
    for (auto &c : s) {
      int x = Get(c);
      que[x & 1].push(x);
    }
    while (!que[0].empty() && !que[1].empty()) {
      if (que[0].front() < que[1].front()) {
        std::cout << que[0].front();
        que[0].pop();
      }
      else {
        std::cout << que[1].front();
        que[1].pop();      
      }
    }
    while (!que[0].empty()) {
      std::cout << que[0].front();
      que[0].pop();
    }
    while (!que[1].empty()) {
      std::cout << que[1].front();
      que[1].pop();
    }
    std::cout << '\n';
  }
  return 0;
}

