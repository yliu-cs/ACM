// Author: Tony5t4rk Time: 2019-08-11 20:40:49 
#include <bits/stdc++.h>
const int maxn = 1e2 + 5;

int main() {
  int t;
  std::cin >> t;
  while (t--) {
    int n, m, k;
    std::cin >> n >> m >> k;
    std::vector<int> h(n);
    for (int &v : h) std::cin >> v;
    bool suc = true;
    for (int i = 0; i < n - 1; ++i) {
      if (h[i] < h[i + 1]) {
        if (h[i] + k < h[i + 1]) {
          if (h[i + 1] - h[i] - k > m) {
            suc = false;
            break;
          }
          else m -= h[i + 1] - h[i] - k;
        }
        else m += h[i] - std::max(0, h[i + 1] - k);
      }
      else m += h[i] - h[i + 1] + std::min(k, h[i + 1]);
    }
    if (suc) std::cout << "YES\n";
    else std::cout << "NO\n";
  }
  return 0;
}

