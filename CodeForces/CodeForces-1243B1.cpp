#include <bits/stdc++.h>

const int N = 1e4 + 5;

int k, n;
char s[N], t[N];
std::vector<int> idx;

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cin >> k;
  while (k--) {
    std::cin >> n >> (s + 1) >> (t + 1);
    idx.clear();
    for (int i = 1; i <= n; ++i) {
      if (s[i] != t[i]) {
        idx.emplace_back(i);
      }
    }
    if ((int)idx.size() > 2 || (int)idx.size() == 1) {
      std::cout << "No" << '\n';
      continue;
    }
    else if ((int)idx.size() == 1) {
      std::cout << "Yes" << '\n';
    }
    else if (s[idx[0]] == s[idx[1]] && t[idx[0]] == t[idx[1]]) {
      std::cout << "Yes" << '\n';
    }
    else {
      std::cout << "No" << '\n';
    }
  }
  return 0;
}

