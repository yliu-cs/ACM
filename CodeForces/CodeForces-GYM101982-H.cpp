#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 1e6 + 5;

bool is_prime[maxn];
vector<ll> prime;

void Sieve() {
  memset(is_prime, true, sizeof(is_prime));
  for (ll i = 2; i < maxn; ++i) {
    if (is_prime[i]) prime.emplace_back(i);
    for (auto &it : prime) {
      if (it * i >= maxn) break;
      is_prime[i * it] = false;
    }
  }
}

ll Find(ll k) {
  if (k < 4) return 0;
  for (auto &it : prime) {
    if (is_prime[k - it]) {
      int diff = abs(it - (k - it));
      if (diff & 1) continue;
      return Find(diff) + 1;
    }
  }
}

int main() {
  ios::sync_with_stdio(false); cin.tie(0);
  Sieve();
  ll x; cin >> x;
  cout << Find(x) << endl;
  return 0;
}

