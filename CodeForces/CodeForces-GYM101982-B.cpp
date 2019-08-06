#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 1e7 + 5;

bool is_prime[maxn];
vector<int> prime;
int mu[maxn];
ll prefix[maxn];

void Sieve() {
  memset(is_prime, true, sizeof(is_prime));
  mu[1] = 1;
  for (int i = 2; i < maxn; ++i) {
    if (is_prime[i]) {
      prime.push_back(i);
      mu[i] = -1;
    }
    for (auto &it : prime) {
      if (it * i >= maxn) break;
      is_prime[i * it] = false;
      if (i % it == 0) {
        mu[i * it] = 0;
        break;
      }
      mu[i * it] = -mu[i];
    }
  }
  for (int i = 1; i < maxn; ++i) prefix[i] = prefix[i - 1] + mu[i];
}

ll Get(int n, int m) {
  if (n > m) swap(n, m);
  ll ans = 0;
  for (int l = 1, r; l <= n; l = r + 1) {
    r = min(n / (n / l), m / (m / l));
    ans += (prefix[r] - prefix[l - 1]) * (n / l) * (m / l);
  }
  return ans;
}

int main() {
  ios::sync_with_stdio(false); cin.tie(0);
  Sieve();
  int a, b, c, d; cin >> a >> b >> c >> d;
  ll ans = Get(b, d);
  ans -= Get(b, c - 1); ans -= Get(a - 1, d);
  ans += Get(a - 1, c - 1);
  cout << ans << endl;
  return 0;
}

