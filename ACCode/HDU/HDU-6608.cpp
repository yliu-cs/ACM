#include <bits/stdc++.h>
#define random(a, b) (((double)rand()/RAND_MAX)*(b-a)+a)
typedef long long ll;

ll Quick_Mul(ll a, ll b, ll n) {
  ll res = 0;
  while(b) {
    if(b & 1) res = (res + a) % n;
    a = (a + a) % n;
    b >>= 1;
  }
  return res;
}

ll QuickPow(ll a, ll b, ll n) {
  ll ans = 1;
  while(b) {
    if(b & 1) ans = Quick_Mul(ans, a, n);
    a = Quick_Mul(a, a, n);
    b >>= 1;
  }
  return ans;
}

bool Miller_Rabin(ll n) {
  if(n <= 2) {
    if(n == 2) return true;
    return false;
  }
  if(n % 2 == 0) return false;
  ll u = n - 1;
  while(u % 2 == 0) u /= 2;
  int S = 100;
  srand((ll)time(0));
  for (int i = 1; i <= S; i ++){
    ll a = rand() % (n - 2)+ 2;
    ll x = QuickPow(a, u, n);
    while(u < n) {
      ll y = QuickPow(x, 2, n);
      if(y == 1 && x != 1 && x != n - 1)
        return false;
      x = y;
      u = u * 2;
    }
    if(x != 1) return false;
  }
  return true;
}

ll GetPrime(ll x) {
  ll ret = x - 2;
  while (!Miller_Rabin(ret)) ret -= 2;
  return ret;
}

int main() {
  int t;
  scanf("%d", &t);
  for (int cas = 1; cas <= t; ++cas) {
    ll n;
    scanf("%lld", &n);
    ll p = GetPrime(n), ans = 1;
    if (n > p + 2) {
      for (ll i = p + 1; i <= n - 2; ++i) ans = Quick_Mul(ans, QuickPow(i, n - 2, n), n);
    }
    printf("%lld\n", ans);
  }
  return 0;
}