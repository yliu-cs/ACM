#include <bits/stdc++.h>

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int t;
  std::cin >> t;
  while (t--) {
    int n;
    std::cin >> n;
    std::string s;
    std::cin >> s;
    std::vector<int> d(n);
    for (int i = 0; i < n; ++i) {
      d[i] = (int)(s[i] - '0');
    }
    bool suc;
    for (int m = 0; m < 10; ++m) {
      suc = true;
      std::vector<int> col(n, 0);
      for (int i = 0; i < n; ++i) {
        if (d[i] < m) {
          col[i] = 1;
        }
        else if (d[i] > m) {
          col[i] = 2;
        }
      }
      bool f = false;
      int idx = -1;
      for (int i = 0; i < n; ++i) {
        if (col[i] == 2) {
          f = true;
        }
        if (d[i] == m) {
          if (!f) {
            col[i] = 2;
          }
          else {
            idx = i;
            break;
          }
        }
      }
      if (idx != -1) {
        for (int i = idx; i < n; ++i) {
          if (col[i] == 1) {
            suc = false;
            break;
          }
        }
        if (suc) {
          for (int i = idx; i < n; ++i) {
            if (d[i] == m) {
              col[i] = 1;
            }
          }
        }
      }
      if (suc) {
        int la = -1;
        for (int i = 0; i < n; ++i) {
          if (col[i] == 1) {
            if (d[i] < la) {
              suc = false;
              break;
            }
            else {
              la = d[i];
            }
          }
        }
        la = -1;
        for (int i = 0; i < n; ++i) {
          if (col[i] == 2) {
            if (d[i] < la) {
              suc = false;
              break;
            }
            else {
              la = d[i];
            }
          }
        }
      }
      if (suc) {
        for (auto &v : col) {
          std::cout << v;
        }
        std::cout << '\n';
        break;
      }
    }
    if (!suc) {
      std::cout << '-' << '\n';
    }
  }
  return 0;
}

