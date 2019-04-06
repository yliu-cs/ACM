const int maxn = "Edit";
const double pi = acos(-1.0);

// 复数
struct complex {
  double x, y;
  complex operator + (const complex &b) const {return complex {x + b.x, y + b.y};}
  complex operator - (const complex &b) const {return complex {x - b.x, y - b.y};}
  complex operator * (const complex &b) const {return complex {x * b.x - y * b.y, x * b.y + y * b.x};}
  complex operator / (const complex &b) const {
    double tmp = b.x * b.x + b.y * b.y;
    return complex {(x * b.x + y * b.y) / tmp, (y * b.x - x * b.y) / tmp};
  }
};

// 多项式系数数量
int n, m;
int l;
int limit;
int r[maxn << 2];

// 快速傅里叶变换(FFT)
void FFT(complex f[], int op) {
  for (int i = 0; i < limit; ++i) {
    if (i < r[i]) std::swap(f[i], f[r[i]]);
  }
  for (int j = 1; j < limit; j <<= 1) {
    complex tmp = complex {cos(pi / j), op * sin(pi / j)};
    for (int k = 0; k < limit; k += (j << 1)) {
      complex Buffer = complex {1.0, 0.0};
      for (int l = 0; l < j; ++l) {
        complex tx = f[k + l], ty = Buffer * f[k + j + l];
        f[k + l] = tx + ty;
        f[k + j + l] = tx - ty;
        Buffer = Buffer * tmp;
      }
    }
  }
}

complex a[maxn], b[maxn];

// 多项式卷积计算
void Cal() {
  limit = 1; l = 0;
  while (limit <= n + m) {
    limit <<= 1;
    l++;
  }
  for (int i = 0; i < limit; ++i) r[i] = (r[i >> 1] >> 1) | ((i & 1) << (l - 1));
  FFT(a, 1);
  FFT(b, 1);
  for (int i = 0; i <= limit; ++i) a[i] = a[i] * b[i];
  FFT(a, -1);
}

