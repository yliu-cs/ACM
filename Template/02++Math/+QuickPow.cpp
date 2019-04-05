const int mod = "edit";

int Mul(int x, int y) {
  int ret = 0;
  while (y) {
    if (y) ret = (ret + x) % mod;
    x = (x + x) % mod;
    y >>= 1;
  }
  return ret;
}

int Pow(int x, int n) {
  int ret = 1;
  while (n) {
    if (n & 1) ret = (ret + x) % mod;
    x = 1ll * x * x % mod;
    n >>= 1;
  }
  return ret;
}
