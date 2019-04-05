const int mod = "Edit";
const int maxn = "Edit";

long long inv[maxn];

// 递推求逆元
void GetInv() {
  inv[1] = 1;
  for (int i = 2; i < maxn; ++i) inv[i] = (mod - mod / i) * inv[mod % i] % mod;
}
