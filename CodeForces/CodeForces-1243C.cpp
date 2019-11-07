#include <bits/stdc++.h>

const int N = 1e6 + 5;

bool isprime[N];
std::vector<int> prime;
int phi[N], mu[N];

void Sieve() {
  isprime[0] = isprime[1] = true;
  phi[1] = mu[1] = 1;
  for (long long i = 2; i < N; ++i) {
    if (!isprime[i]) {
      prime.emplace_back(i);
      phi[i] = i - 1;
      mu[i] = -1;
    }
    for (auto &p : prime) {
      if (i * p >= N) {
        break;
      }
      isprime[i * p] = true;
      if (i % p == 0) {
        phi[i * p] = phi[i] * p;
        mu[i * p] = 0;
        break;
      }
      phi[i * p] = phi[i] * phi[p];
      mu[i * p] = -mu[i];
    }
  }
}

long long n;
std::vector<long long> d;

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  Sieve();
  std::cin >> n;
  for (auto &p : prime) {
    if (p > n) {
      break;
    }
    if (n % p == 0) {
      d.push_back(p);
      while (n % p == 0) {
        n /= p;
      }
    }
  }
  if (n ! = 1) {
    d.push_back(n);
  }
  if (d.empty()) {
    std::cout << n << '\n';
  }
  else if ((int)d.size() == 1) {
    std::cout << d[0] << '\n';
  }
  else {
    std::cout << 1 << '\n';
  }
  return 0;
}

