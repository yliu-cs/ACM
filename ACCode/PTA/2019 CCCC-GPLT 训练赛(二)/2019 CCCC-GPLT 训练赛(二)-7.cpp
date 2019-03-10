#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e4 + 5;

bool is_prime[maxn];
vector<int> prime;

void Sieve() {
  memset(is_prime, true, sizeof(is_prime));
  for (int i = 2; i < maxn; ++i) {
    if (is_prime[i]) prime.emplace_back(i);
    for (auto &it : prime) {
      if (1ll * i * it >= maxn) break;
      is_prime[i * it] = false;
    }
  }
}

int main() {
  ios::sync_with_stdio(false); cin.tie(0);
  Sieve();
  int n, k; cin >> n >> k;
  int pos = lower_bound(prime.begin(), prime.end(), n) - prime.begin();
  if (prime[pos] > n || pos == prime.size()) pos--;
  long long ans = 0;
  bool flag = false;
  for (int i = pos, j = 0; i >= 0 && j < k; --i, ++j) {
    ans += prime[i];
    if (flag) cout << "+";
    else flag = true;
    cout << prime[i];
  }
  cout << "=" << ans << endl;
  return 0;
}

