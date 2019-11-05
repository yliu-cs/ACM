#include <bits/stdc++.h>

const int N = 1e3 + 5;

int n;
long long mat[N][N];
long long a[N];

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cin >> n;
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= n; ++j) {
      std::cin >> mat[i][j];
    }
  }
  a[1] = std::sqrt(mat[1][2] * mat[1][3] / mat[2][3]);
  for (int i = 2; i <= n; ++i) {
    a[i] = mat[1][i] / a[1];
  }
  for (int i = 1; i <= n; ++i) {
    std::cout << a[i] << ' ';
  }
  return 0;
}

