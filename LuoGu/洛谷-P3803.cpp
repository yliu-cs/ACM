#include <bits/stdc++.h>

const int N = 4e6 + 5;

int n, m, l;
std::complex<double> a[N], b[N];
int r[N];

void FFT(std::complex<double> a[], int sgn) {
  for (int i = 0; i < n; ++i) {
    if (i < r[i]) {
      std::swap(a[i], a[r[i]]);
    }
  }
  for (int i = 1; i < n; i <<= 1) {
    std::complex<double> w(std::cos(M_PI / i), sgn * std::sin(M_PI / i));
    for (int p = i << 1, j = 0; j < n; j += p) {
      std::complex<double> e(1, 0);
      for (int k = 0; k < i; ++k, e *= w) {
        std::complex<double> x = a[j + k], y = e * a[i + j + k];
        a[j + k] = x + y;
        a[j + k + i] = x - y;
      }
    }
  }
} 

void Cal() {
  m = n + m;
  for (n = 1; n <= m; n <<= 1) {
    ++l;
  }
  for (int i = 0; i < n; ++i) {
    r[i] = (r[i >> 1] >> 1) | ((i & 1) << (l - 1));
  }
  FFT(a, 1);
  FFT(b, 1);
  for (int i = 0; i <= n; ++i) {
    a[i] = a[i] * b[i];
  }
  FFT(a, -1);
}

int main() {
  scanf("%d%d", &n, &m);
  for (int i = 0, x; i <= n; ++i) {
    scanf("%d", &x);
    a[i] = x;
  }
  for (int i = 0, x; i <= m; ++i) {
    scanf("%d", &x);
    b[i] = x;
  }
  Cal();
  for (int i = 0; i <= m; ++i) {
    printf("%d ", (int)(a[i].real() / n + 0.5));
  }
  return 0;
}

