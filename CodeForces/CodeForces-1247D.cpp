// Author: Tony5t4rk Time: 2019-10-28 12:55:16 
#include <bits/stdc++.h>
const int N = 1e5 + 5;
bool isprime[N];
std::vector<int> prime;
int n, k;
long long ans;
std::vector<std::pair<int, int>> vec, patch;
std::map<std::vector<std::pair<int, int>>, int> map;
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cin >> n >> k;
  memset(isprime, true, sizeof(isprime));
  for (long long i = 2; i < N; ++i) {
    if (isprime[i]) prime.push_back(i);
    for (auto &p : prime) {
      if (i * p >= N) break;
      isprime[i * p] = false;
      if (i % p == 0) break;
    }
  }
  for (int i = 0, x; i < n; ++i) {
    std::cin >> x;
    vec.clear(); patch.clear();
    for (auto &p : prime) {
      if (p > x) break;
      if (x % p) continue;
      int cnt = 0;
      while (x % p == 0) {
        x /= p;
        ++cnt;
      }
      if (cnt % k) {
        cnt %= k;
        vec.push_back({p, cnt});
        patch.push_back({p, k - cnt});
      }
    }
    if (x != 1) {
      vec.push_back({x, 1});
      patch.push_back({x, k - 1});
    }
    ans += map[patch];
    ++map[vec];
  }
  std::cout << ans << '\n';
  return 0;
}
