// Author: Tony5t4rk Time: 2019-09-29 21:08:50 
#include <bits/stdc++.h>
const int maxn = 1e3 + 5;
const int mod = 1e9 + 7;
int h, w;
int r[maxn], c[maxn];
int gird[maxn][maxn];
long long Pow(long long a, long long n) {
  long long ret = 1;
  while (n) {
    if (n & 1) ret = (ret * a) % mod;
    a = (a * a) % mod;
    n >>= 1;
  }
  return ret;
}
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.setf(std::ios::fixed);
  std::cout.precision(15);
  std::cin >> h >> w;
  memset(gird, 0, sizeof(gird));
  for (int i = 1; i <= h; ++i) {
    std::cin >> r[i];
    for (int j = 1; j <= r[i]; ++j) {
      if (gird[i][j] == -1) {
        std::cout << 0 << '\n';
        return 0;
      }
      gird[i][j] = 1;
    }
    if (gird[i][r[i] + 1] == 1) {
      std::cout << 0 << '\n';
      return 0;
    }
    gird[i][r[i] + 1] = -1;
  }
  for (int j = 1; j <= w; ++j) {
    std::cin >> c[j];
    for (int i = 1; i <= c[j]; ++i) {
      if (gird[i][j] == -1) {
        std::cout << 0 << '\n';
        return 0;
      }
      gird[i][j] = 1;
    }
    if (gird[c[j] + 1][j] == 1) {
      std::cout << 0 << '\n';
      return 0;
    }
    gird[c[j] + 1][j] = -1;
  }
  long long cnt = 0;
  for (int i = 1; i <= h; ++i) {
    for (int j = 1; j <= w; ++j) {
      if (gird[i][j] == 0) ++cnt;
    }
  }
  std::cout << Pow(2, cnt) % mod << '\n';
  return 0;
}
