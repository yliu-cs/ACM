const int mod = "edit";

long long Mul(long long x, long long y) {
  long long ret = 0;
  while (y) {
    if (y) ret = (ret + x) % mod;
    x = (x + x) % mod;
    y >>= 1;
  }
  return ret;
}

long long Pow(long long x, long long n) {
  long long ret = 1;
  while (n) {
    if (n & 1) ret = (ret * x) % mod;
    x = x * x % mod;
    n >>= 1;
  }
  return ret;
}
