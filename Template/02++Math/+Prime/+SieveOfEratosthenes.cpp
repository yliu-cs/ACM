const int maxn = "Edit";

bool is_prime[maxn];
std::vector<int> prime

void Sieve() {
  memset(is_prime, true, sizeof(is_prime));
  is_prime[0] = is_prime[1] = false;
  for (long long i = 2; i < maxn; ++i) {
    if (is_prime[i]) prime.emplace_back(i);
    for (auto &p : prime) {
      if (p * i >= maxn) break;
      is_prime[i * p] = false;
    }
  }
}

