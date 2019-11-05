#include <bits/stdc++.h>
const int mod = 1e6 + 3;

long long Pow(long long x, long long n) {
  long long ret = 1;
  while (n) {
    if (n & 1) ret = (ret * x) % mod;
    x = x * x % mod;
    n >>= 1;
  }
  return ret;
}

long long Inv(long long x) {
  return Pow(x, mod - 2);
}

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

long long F(long long x, std::vector<long long> &coef) {
  long long ret = 0;
  for (int i = (int)coef.size() - 1; ~i; --i) {
    ret = (ret * x + coef[i]) % mod;
  }
  return ret;
}

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr); std::cout.tie(nullptr);

  std::vector<std::vector<long long>> matrix(11, std::vector<long long>(12, 0));
  for (int i = 0; i <= 10; ++i) {
    for (int j = 0; j <= 10; ++j) {
      matrix[i][j] = Pow(i, j);
    }
  }

  for (int i = 0; i <= 10; ++i) {
    std::cout << "? " << i << '\n';
    std::cout.flush();
    std::cin >> matrix[i][11];
  }

  Gauss(matrix);
  std::vector<long long> coef(11, 0);
  for (int i = 0; i <= 10; ++i) {
    coef[i] = matrix[i][11];
  }

  for (int i = 0; i < mod; ++i) {
    if (F(i, coef) == 0) {
      std::cout << "! " << i << '\n';
      return 0;
    }
  }
  std::cout << "! " << -1 << '\n';

  return 0;
}

