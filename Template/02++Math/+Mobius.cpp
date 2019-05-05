#include <bits/stdc++.h>

const int maxn = "Edit";

bool is_prime[maxn];
std::vector<int> prime;
int mu[maxn];

void Sieve() {
  memset(is_prime, true, sizeof(is_prime));
  mu[1] = 1; is_prime[0] = is_prime[1] = false;
  for (int i = 2; i < maxn; ++i) {
    if (is_prime[i]) {
      prime.emplace_back(i);
      mu[i] = -1;
    }
    for (auto &p : prime) {
      if (p * i >= maxn) break;
      is_prime[i * p] = false;
      if (i % p == 0) {
        mu[i * p] = 0;
        break;
      }
      mu[i * p] = -mu[i];
    }
  }
}
