const int maxn = "Edit";

bool is_prime[maxn];
int phi[maxn];
std::vector<int> prime;

// 同时求得欧拉函数和素数表
void Sieve() {
  memset(is_prime, true, sizeof(is_prime));
  phi[1] = 1; is_prime[0] = is_prime[1] = false;
  for (long long i = 2; i < maxn; ++i) {
    if (is_prime[i]) {
      phi[i] = i - 1;
      prime.emplace_back(i);
    }
    for (auto &p : prime) {
      if (p * i >= maxn) break;
      is_prime[i * p] = false;
      if (i % p == 0) {
        phi[i * p] = phi[i] * p;
        break;
      }
      phi[i * p] = phi[i] * phi[p];
    }
  }
}
