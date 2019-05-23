#include <bits/stdc++.h>
#include <bits/extc++.h>

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr); std::cout.tie(nullptr);

  long long n; std::cin >> n;
  std::vector<long long> w(n);
  for (long long &v : w) std::cin >> v;
  std::sort(w.begin(), w.end(), [&](long long k1, long long k2) { return k1 > k2; });
  long long p, s; std::cin >> p >> s;

  long long u = s / p;
  long long l = 1, r = w[0], ans = w[0];
  while (l <= r) {
    long long m = (l + r) / 2;
    long long cnt = 0;
    for (long long &v : w) {
      if (v > m) cnt += v - m;
      else break;
    }
    if (cnt <= u) {
      ans = m;
      r = m - 1;
    }
    else l = m + 1;
  }

  std::cout << ans << '\n';
  return 0;
}

