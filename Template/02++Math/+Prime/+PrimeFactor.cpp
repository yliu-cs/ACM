const int maxn = "Edit"

bool is_prime[maxn];
vector<int> prime_fac[maxn];

void GetPrimeFac() {
  memset(is_prime, true, sizeof(is_prime));
  for (long long i = 2; i < maxn; ++i) {
    if (is_prime[i]) {
      prime_fac[i].push_back(i);
      for (long long j = i + i; j < maxn; ++j) {
        is_prime[j] = false;
        prime_fac[j].push_back(i);
      }
    }
  }
  is_prime[1] = false;
}

