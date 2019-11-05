#include <bits/stdc++.h>
const int maxn = 2e3 + 5;

bool isprime[maxn];
std::vector<int> prime;

void Sieve() {
  memset(isprime, true, sizeof(isprime));
  for (int i = 2; i < maxn; ++i) {
    if (isprime[i]) prime.emplace_back(i);
    for (int &p : prime) {
      if (p * i >= maxn) break;
      isprime[i * p] = false;
    }
  }
}

int main() {
  Sieve();
  int n;
  std::cin >> n;
  std::vector<std::pair<int, int>> ans;
  for (int i = 1; i < n; ++i) ans.push_back({i, i + 1});
  ans.push_back({1, n});
  int cur = 1;
  while (!isprime[ans.size()]) {
    ans.push_back({cur, n - cur});
    ++cur;
  }
  std::cout << ans.size() << '\n';
  for (std::pair<int, int> &p : ans) std::cout << p.first << ' ' << p.second << '\n';
  return 0;
}