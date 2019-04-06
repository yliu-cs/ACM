#include <bits/stdc++.h>
const int mod = 1e9 + 7;

long long Pow(long long x, long long n) {
  long long ret = 1;
  while (n) {
    if (n & 1) ret = (ret * x) % mod;
    x = 1ll * x * x % mod;
    n >>= 1;
  }
  return ret;
}

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr); std::cout.tie(nullptr);

  int n; std::cin >> n;

  std::string last = "", str;
  long long ans = 0, k = 1, qq;
  std::set<long long> set;
  for (int i = 0; i < n; ++i) {
    std::cin >> qq >> str;
    if (str == last) {
      if (set.find(qq) == set.end()) set.insert(qq);
      long long len = (int)str.length();
      ans = (ans + Pow(len, k++)) % mod;
    }
    else {
      k = 1;
      last = str;
    }
  }

  std::cout << (int)set.size() << ' ' << ans << '\n';
  return 0;
}
