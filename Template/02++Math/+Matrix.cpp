const int maxn = "Edit";
const int mod = "Edit";

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

