// Author: Tony5t4rk Time: 2019-09-29 21:26:45 
#include <bits/stdc++.h>
const int maxn = 1e5 + 5;
const int mod = 1e9 + 7;
bool isprime[maxn];
std::vector<long long> prime;
void Sieve() {
  memset(isprime, true, sizeof(isprime));
  for (long long i = 2; i < maxn; ++i) {
    if (isprime[i]) prime.push_back(i);
    for (auto &p : prime) {
      if (p * i >= maxn) break;
      isprime[p * i] = false;
    }
  }
}
std::vector<long long> DivPrimeFactor(long long x) {
  std::vector<long long> ret;
  for (int i = 0; prime[i] <= x / prime[i]; ++i) {
    if (x % prime[i] == 0) {
      ret.push_back(prime[i]);;
      while (x % prime[i] == 0) x /= prime[i];
    }
  }
  if (x != 1) ret.push_back(x);
  return ret;
}
long long Mul(long long x, long long y) {
  long long ret = 0;
  while (y) {
    if (y & 1) ret = (ret + x) % mod;
    x = (x + x) % mod;
    y >>= 1;
  }
  return ret;
}
long long Pow(long long x, long long n) {
  long long ret = 1;
  while (n) {
    if (n & 1) ret = Mul(ret, x) % mod;
    x = Mul(x, x) % mod;
    n >>= 1;
  }
  return ret;
}
long long x, n;
int main() {
  Sieve();
  std::cin >> x >> n;
  std::vector<long long> factor = DivPrimeFactor(x);
  long long ans = 1;
  for (auto &fac : factor) {
    int last = std::floor(log2(n) / log2(fac));
    long long mul = 1, suf = 0;
    for (int i = 1; i <= last; ++i) mul = mul * fac;
    for (int i = last; i >= 1; --i) {
      long long cnt = n / mul;
      long long tmp = Pow(mul, cnt - suf);
      ans = Mul(ans, tmp) % mod;
      suf = cnt;
      mul /= fac;
    }
  }
  std::cout << ans << '\n';
  return 0;
}
