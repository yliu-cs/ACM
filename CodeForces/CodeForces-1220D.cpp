#include <bits/stdc++.h>

const int N = 2e5 + 5;
const int C = 70;

int n;
long long b[N];
std::set<int> set[C];
int ptr;

int main() {
  std::cin >> n;
  for (int i = 1; i <= n; ++i) {
    std::cin >> b[i];
    int cnt = 0;
    long long x = b[i];
    while (x % 2 == 0) {
      ++cnt;
      x /= 2;
    }
    set[cnt].emplace(i);
  }
  ptr = 0;
  for (int i = 1; i < C; ++i) {
    if ((int)set[i].size() > (int)set[ptr].size()) {
      ptr = i;
    }
  }
  std::cout << (n - (int)set[ptr].size()) << '\n';
  for (int i = 1; i <= n; ++i) {
    if (set[ptr].find(i) == set[ptr].end()) {
      std::cout << b[i] << ' ';
    }
  }
  return 0;
}

