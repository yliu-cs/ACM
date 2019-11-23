#include <bits/stdc++.h>

const int N = 1e3 + 5;
const int M = 1e3 + 5;
const int H = 1e2 + 5;

int n, m, v;
int h[N][M];
int fil[H];
int ans;

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cin >> n >> m >> v;
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= m; ++j) {
      std::cin >> h[i][j];
      for (int k = h[i][j]; k > 0; --k) {
        ++fil[k];
      }
    }
  }
  for (int i = 100; i >= 0; --i) {
    if (v <= 0) {
      ans = i;
      break;
    }
    v -= fil[i];
  }
  std::cout << ans << '\n';
  return 0;
}

