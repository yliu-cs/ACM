#include <bits/stdc++.h>
const int maxn = 2;
const int mod = 998244353;

struct matrix {
  long long mat[maxn][maxn];
  matrix() { memset(mat, 0, sizeof(mat)); }
  void Unit() { for (int i = 0; i < maxn; ++i) mat[i][i] = 1; }
};

matrix operator * (matrix k1, matrix k2) {
  matrix ret;
  for (int i = 0; i < maxn; ++i) {
    for (int j = 0; j < maxn; ++j) {
      for (int k = 0; k < maxn; ++k) {
        ret.mat[i][j] = (ret.mat[i][j] + k1.mat[i][k] * k2.mat[k][j]) % mod;
      }
    }
  }
  return ret;
}

matrix Pow(matrix x, long long n) {
  matrix ret;
  ret.Unit();
  while (n) {
    if (n & 1) ret = ret * x;
    x = x * x;
    n >>= 1;
  }
  return ret;
}

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr); std::cout.tie(nullptr);

  long long n, k; std::cin >> n >> k;

  matrix m;
  m.mat[0][1] = 1;
  m.mat[1][0] = (n - 1 + mod) % mod;
  m.mat[1][1] = (n - 2 + mod) % mod;
  m = Pow(m, k);

  std::cout << m.mat[0][0] << '\n';
  return 0;
}

