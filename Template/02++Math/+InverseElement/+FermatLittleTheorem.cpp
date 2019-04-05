const int mod = "Edit";

// 快速幂、费马小定理求逆元
long long Inv(long long x) {
  return Pow(x, mod - 2);
}

