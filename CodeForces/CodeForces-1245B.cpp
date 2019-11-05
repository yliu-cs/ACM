#include <bits/stdc++.h>

const int N = 1e2 + 5;
const int C = 26;

int t, n, a, b, c;
char s[N];
std::vector<int> idx[C];
char ans[N];
int sum, tmp;

int Get(char x) {
  return (int)(x - 'A');
}

int main() {
  std::cin >> t;
  while (t--) {
    std::cin >> n;
    std::cin >> a >> b >> c;
    std::cin >> s;
    for (int i = 0; i < C; ++i) {
      idx[i].clear();
    }
    for (int i = 0; i < n; ++i) {
      ans[i] = '-';
    }
    for (int i = 0; i < n; ++i) {
      int x = Get(s[i]);
      idx[x].emplace_back(i);
    }
    sum = 0;
    tmp = std::min(a, (int)idx[Get('S')].size());
    sum += tmp;
    a -= tmp;
    for (int i = 0; i < tmp; ++i) {
      ans[idx[Get('S')].back()] = 'R';
      idx[Get('S')].pop_back();
    }
    tmp = std::min(b, (int)idx[Get('R')].size());
    sum += tmp;
    for (int i = 0; i < tmp; ++i) {
      ans[idx[Get('R')].back()] = 'P';
      idx[Get('R')].pop_back();
    }
    b -= tmp;
    tmp = std::min(c, (int)idx[Get('P')].size());
    sum += tmp;
    for (int i = 0; i < tmp; ++i) {
      ans[idx[Get('P')].back()] = 'S';
      idx[Get('P')].pop_back();
    }
    c -= tmp;
    if (sum >= (n + 1) / 2) {
      std::cout << "YES" << '\n';
      for (int i = 0; i < n; ++i) {
        if (ans[i] != '-') {
          std::cout << ans[i];
        }
        else {
          if (a) {
            std::cout << 'R';
            --a;
          }
          else if (b) {
            std::cout << 'P';
            --b;
          }
          else {
            std::cout << 'S';
            --c;
          }
        }
      }
      std::cout << '\n';
    }
    else {
      std::cout << "NO" << '\n';
    }
  }
  return 0;
}

