const int mod = "Edit";

// 矩阵
struct matrix {long long mat[2][2];

// 重载矩阵乘法
matrix operator * (matrix &k1, matrix &k2) const {
  matrix ret;
  memset(ret.mat, 0, sizeof(ret.mat));
  for (int i = 0; i < 2; ++i) {
    for (int j = 0; j < 2; ++j) {
      for (int k = 0; k < 2; ++k) {
          ret.mat[i][j] = (ret.mat[i][j] + k1.mat[i][k] * k2.mat[k][j] % mod) % mod;
      }
    }
  }
  return ret;
}

// 重载矩阵快速幂
matrix operator ^ (matrix base, long long k) {
  matrix ret;
  memset(ret.mat, 0, sizeof(ret.mat));
  ret.mat[0][0] = ret.mat[1][1] = 1;
  while (k) {
    if (k & 1) ret = ret * base;
    base = base * base;
    k >>= 1;
  }
  return ret;
}

// 斐波那契数列中第X项
long long Fib(long long x) {
  matrix base;
  base.mat[0][0] = base.mat[1][0] = base.mat[0][1] = 1;
  base.mat[1][1] = 0;
  return (base ^ x).mat[0][1];
}
