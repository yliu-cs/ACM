#include <bits/stdc++.h>

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr); std::cout.tie(nullptr);

  long long n, k; std::cin >> n >> k;

  long long ans = 0, last = 0;
  for (long long i = 0, x; i < n; ++i) {
    std::cin >> x;
    if (last == 0) {
      ans += x / k;
      last = x % k;
    }
    else {
      if (x >= (k - last)) {
        x -= k - last;
        ++ans;
        ans += x / k;
        last = x % k;
      }
      else {
        last = 0;
        ++ans;
      }
    }
  }
  if (last) ++ans;

  std::cout << ans << '\n';
  return 0;
}

