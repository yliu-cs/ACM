#include <bits/stdc++.h>

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0); std::cout.tie(0);

  long long n; std::cin >> n;
  std::string str; std::cin >> str;

  long long ans = 0;
  for (long long i = 0; i < n; ++i) {
    if ((str[i] - '0') % 2 == 0) ans += i + 1;
  }
  
  std::cout << ans << '\n';
  return 0;
}
