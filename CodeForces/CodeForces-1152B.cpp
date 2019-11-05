#include <bits/stdc++.h>

int odd_cnt;
int ans[25];

void Odd(int &x) {
  int len = log2(x) + 1;
  for (int i = len - 1; i >= 0; --i) {
    if (x & (1 << i)) continue;
    else {
      int tmp = ((1 << (i + 1)) - 1);
      x = x ^ tmp;
      ans[odd_cnt] = i + 1;
      return;
    }
  }
}

std::set<int> set;

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr); std::cout.tie(nullptr);

  for (int i = 0; i <= 30; ++i) set.insert((1 << i) - 1);

  int x; std::cin >> x;

  int cnt = 0; odd_cnt = 0;
  while (set.find(x) == set.end()) {
    ++cnt; ++odd_cnt;
    Odd(x);
    if (set.find(x) != set.end()) break;
    ++cnt;
    x += 1;
    if (set.find(x) != set.end()) break;
  }

  std::cout << cnt << '\n';
  for (int i = 1; i <= odd_cnt; ++i) std::cout << ans[i] << ' ';
  std::cout << '\n';
  return 0;
}

