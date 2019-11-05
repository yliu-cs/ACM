#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e7 + 5;

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
  long long n; cin >> n;
  cout << n << "=";
  if (n == 1) {
    cout << 1;
    return 0;
  }
  bool flag = false;
  for (auto &it : prime) {
    if (n % it != 0) continue;
    int cnt = 0;
    while (n % it == 0) {
      n /= it;
      cnt++;
    }
    if (flag) cout << "*";
    else flag = true;
    cout << it;
    if (cnt > 1) cout << "^" << cnt;
    if (n == 1) break;
  }
  return 0;
}
