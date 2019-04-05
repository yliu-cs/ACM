const int mod = "Edit";
const int maxn = "Edit";

// fac:阶乘，facinv:阶乘逆元
long long fac[maxn], facinv[maxn];

void GetFacInv() {
  fac[0] = 0; fac[1] = 1;
  for (int i = 2; i < maxn; ++i) fac[i] = (fac[i - 1] * i) % mod;
  facinv[maxn - 1] = Pow(fac[maxn - 1], mod - 2);
  for (int i = maxn - 2; i >= 0; --i) facinv[i] = (facinv[i + 1] * (i + 1)) % mod;
}
