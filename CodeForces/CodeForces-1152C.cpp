#include <bits/stdc++.h>
typedef long long ll;

std::vector<ll> vec;

void Div(ll x) {
  for (ll i = 1; i * i <= x; ++i) {
    if (i * i == x) vec.push_back(i);
    else if (x % i == 0) {
      vec.push_back(i);
      vec.push_back(x / i);
    }
  }
}

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr); std::cout.tie(nullptr);

  ll a, b; std::cin >> a >> b;
  if (a > b) std::swap(a, b);

  ll diff = b - a;
  if (diff == 0) {
    std::cout << 0 << '\n';
    return 0;
  }

  Div(diff);
  std::sort(vec.begin(), vec.end());

  ll k = 0;
  if (a <= vec.back()) {
    int pos = std::lower_bound(vec.begin(), vec.end(), a) - vec.begin();
    k = vec[pos] - a;
    std::cout << k << '\n';
    return 0;
  }

  ll cnt = 2;
  while (true) {
    ll tmp = diff * cnt++;
    if (tmp < a) continue;
    k = tmp - a;
    break;
  }

  std::cout << k << '\n';
  return 0;
}

