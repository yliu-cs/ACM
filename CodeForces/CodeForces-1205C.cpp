// Author: Tony5t4rk Time: 2019-08-18 22:41:21 
#include <bits/stdc++.h>
int main() {
  int n;
  std::cin >> n;
  std::vector<std::vector<int> > ans(n + 1, std::vector<int>(n + 1, 0));
  ans[1][1] = 1;
  for (int x = 1; x <= n; x += 2) {
    for (int y = 1; y <= n; y += 2) {
      if ((x == 1 && y == 1) || (x == n && y == n)) continue;
      if (y == 1) {
        std::cout << "? " << x - 2 << ' ' << y << ' ' << x << ' ' << y << std::endl;
        int rpl;
        std::cin >> rpl;
        ans[x][y] = rpl == 1 ? ans[x - 2][y] : (ans[x - 2][y] ^ 1);
      }
      else {
        std::cout << "? " << x << ' ' << y - 2 << ' ' << x << ' ' << y << std::endl;
        int rpl;
        std::cin >> rpl;
        ans[x][y] = rpl == 1 ? ans[x][y - 2] : (ans[x][y - 2] ^ 1);
      }
    }
  }
  for (int x = 2; x <= n; x += 2) {
    for (int y = 2; y <= n; y += 2) {
      std::cout << "? " << x - 1 << ' ' << y - 1 << ' ' << x << ' ' << y << std::endl;
      int rpl;
      std::cin >> rpl;
      ans[x][y] = rpl == 1 ? ans[x - 1][y - 1] : (ans[x - 1][y - 1] ^ 1);
    }
  }
  for (int y = 4; y <= n; y += 2) {
    std::cout << "? " << 1 << ' ' << y - 2 << ' ' << 1 << ' ' << y << std::endl;
    int rpl;
    std::cin >> rpl;
    ans[1][y] = rpl == 1 ? ans[1][y - 2] : (ans[1][y - 2] ^ 1);
  }
  for (int x = 3; x <= n; x += 2) {
    for (int y = 2; y <= n; y += 2) {
      std::cout << "? " << x - 2 << ' ' << y << ' ' << x << ' ' << y << std::endl;
      int rpl;
      std::cin >> rpl;
      ans[x][y] = rpl == 1 ? ans[x - 2][y] : (ans[x - 2][y] ^ 1);
    }
  }
  for (int x = 2; x <= n; x += 2) {
    for (int y = 3; y <= n; y += 2) {
      std::cout << "? " << x - 1 << ' ' << y - 1 << ' ' << x << ' ' << y << std::endl;
      int rpl;
      std::cin >> rpl;
      ans[x][y] = rpl == 1 ? ans[x - 1][y - 1] : (ans[x - 1][y - 1] ^ 1);
    }
  }
  for (int x = 2; x <= n; x += 2) {
    std::cout << "? " << x << ' ' << 1 << ' ' << x << ' ' << 3 << std::endl;
    int rpl;
    std::cin >> rpl;
    ans[x][1] = rpl == 1 ? ans[x][3] : (ans[x][3] ^ 1);
  }
  int f = 0;
  for (int i = 1; i <= n; i += 2) {
    if (ans[i][i] == 1 && ans[i + 2][i + 2] == 0) {
      std::cout << "? " << i << ' ' << i + 1 << ' ' << i + 2 << ' ' << i +2 << std::endl;
      int rpl;
      std::cin >> rpl;
      if (rpl == 1) f = ans[i][i + 1];
      else {
        std::cout << "? " << i << ' ' << i << ' ' << i + 1 << ' ' << i + 2 << std::endl;
        std::cin >> rpl;
        if (rpl == 1) f = ans[i + 1][i + 2] ^ 1;
        else if (ans[i][i + 1] == ans[i + 1][i + 2]) f = ans[i][i + 1] ^ ans[i][i + 2] ^ 1;
        else if (ans[i][i + 2] == 0) f = ans[i + 1][i + 2];
        else f = ans[i][i + 1] ^ 1;
      }
      break;
    }
  }
  std::cout << '!' << std::endl;
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= n; ++j) {
      int num = (i - 1) * n + j;
      if (num % 2 == 0 && f == 1) ans[i][j] ^= 1;
      std::cout << ans[i][j];
    }
    std::cout << std::endl;
  }
  return 0;
}
