const int mod = "Edit";

long long fac[maxn], facinv[maxn];

void GetFacInv() {
  fac[0] = 0; fac[1] = 1;
  for (int i = 2; i < maxn; ++i) fac[i] = (fac[i - 1] * i) % mod;
  facinv[maxn - 1] = Pow(fac[maxn - 1], mod - 2);
  for (int i = maxn - 2; i >= 0; --i) facinv[i] = (facinv[i + 1] * (i + 1)) % mod;
}

long long Lucas(long long n, long long m) {
  long long ret = 1;
  while (n && m) {
    long long a = n % mod, b = m % mod;
    if (a < b) return 0;
    ret = ret * fac[a] % mod * facinv[b] % mod * facinv[a - b] % mod;
    n /= mod, m /= mod;
  }
  return ret;
}

