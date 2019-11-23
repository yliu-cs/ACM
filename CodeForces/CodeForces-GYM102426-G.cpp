#include <bits/stdc++.h>

const int C = 11;

int k, n, cnt[C];
std::string opt;

void Free(int x) {
  for (int i = C - 1; i >= 0; --i) {
    if ((1 << i) <= x) {
      ++cnt[i];
      x -= (1 << i);
    }
  }
}

bool Allocate(int x) {
  int s = -1;
  for (int i = 0; i < C; ++i) {
    if ((1 << i) >= x) {
      s = i;
      break;
    }
  }
  for (int i = s; i < C; ++i) {
    if (cnt[i] != 0) {
      --cnt[i];
      Free((1 << i) - x);
      return true;
    }
  }
  return false;
}

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cin >> k;
  while (k--) {
    std::cin >> opt;
    if (opt == "free") {
      std::cin >> n;
      Free(n);
      for (int i = 0; i < C; ++i) {
        std::cout << cnt[i];
        if (i != C - 1) {
          std::cout << ' ';
        }
      }
      std::cout << '\n';
    }
    else if (opt == "allocate") {
      std::cin >> n;
      if (Allocate(n)) {
        for (int i = 0; i < C; ++i) {
          std::cout << cnt[i];
          if (i != C - 1) {
            std::cout << ' ';
          }
        }
        std::cout << '\n';
      }
      else {
        std::cout << "ERROR!" << '\n';
      }
    }
  }
  return 0;
}

