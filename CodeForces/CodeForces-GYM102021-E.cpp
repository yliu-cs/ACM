#include <bits/stdc++.h>
const int maxn = 1e7 + 5;

bool is_prime[maxn];
std::vector<int> prime;

void Sieve() {
  memset(is_prime, true, sizeof(is_prime));
  for (long long i = 2; i < maxn; ++i) {
    if (is_prime[i]) prime.emplace_back(i);
    for (auto &p : prime) {
      if (p * i >= maxn) break;
      is_prime[i * p] = false;
    }
  }
  is_prime[0] = is_prime[1] = false;
}

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr); std::cout.tie(nullptr);

  Sieve();

  int t; std::cin >> t;
  for (int cas = 1; cas <= t; ++cas) {
    std::string a, b; std::cin >> a >> b;

    long long n = 0, m = 0;
    for (auto &s : a) if (isdigit(s)) n = n * 10 + (s - '0');
    for (auto &s : b) if (isdigit(s)) m = m * 10 + (s - '0');

    long long gcd = std::__gcd(n, m);
    n /= gcd; m /= gcd;

    if (n == m) std::cout << 2 << ' ' << 2 << '\n';
    else if (is_prime[n] && is_prime[m]) std::cout << n << ' ' << m << '\n';
    else std::cout << "impossible\n";
  }
  return 0;
}
