#include <bits/stdc++.h>
typedef long long ll;
const int maxn = 1e2 + 5;

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr); std::cout.tie(nullptr);

  std::vector<ll> arr(maxn);
  arr[1] = 1; arr[2] = 2;
  for (int i = 3; i < maxn; ++i) arr[i] = arr[i - 1] + arr[i - 1] / 2;

  ll x; std::cin >> x;
  int pos = std::upper_bound(arr.begin(), arr.end(), x) - arr.begin();
  std::cout << pos << '\n';
  return 0;
}

