#include <bits/stdc++.h>

const int INF = 1e8 + 5;

int t, c, m, x;

bool Check(int k) {
  if (c < k || m < k) {
    return false;
  }
  return c - k + m - k + x >= k;
}

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cin >> t;
  while (t--) {
    std::cin >> c >> m >> x;
    int bl = 0, br = INF, ans;
    while (bl <= br) {
      int bm = (bl + br) / 2;
      if (Check(bm)) {
        ans = bm;
        bl = bm + 1;
      }
      else {
        br = bm - 1;
      }
    }
    std::cout << ans << '\n';
  }
  return 0;
}

