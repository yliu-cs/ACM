const int mod = "Edit";

void Gauss(std::vector<std::vector<long long>> &matrix) {
  int n = (int)matrix.size();
  for (int i = 0; i < n; ++i) {
    long long inv = Inv(matrix[i][i]);
    for (int j = i; j <= n; ++j) {
      matrix[i][j] = matrix[i][j] * inv % mod;
    }
    for (int j = 0; j < n; ++j) {
      if (j != i) {
        long long tmp = matrix[j][i];
        for (int k = i; k <= n; ++k) {
          matrix[j][k] = (matrix[j][k] - matrix[i][k] * tmp % mod + mod) % mod;
        }
      }
    }
  }
}
