#include <bits/stdc++.h>

const int MOD = 1e9 + 7;
const int N = 1e5 + 5;

int n;
char s[N];
long long dp[N];

int main() {
  std::cin >> (s + 1);
  n = std::strlen(s + 1);
  dp[0] = 1;
  for (int i = 1; i <= n; ++i) {
    dp[i] = dp[i - 1];
    if (s[i] == 'm' || s[i] == 'w') {
      std::cout << 0 << '\n';
      return 0;
    }
    if (i == 1) {
      continue;
    }
    if ((s[i] == 'u' && s[i - 1] == 'u') || (s[i] == 'n' && s[i - 1] == 'n')) {
      dp[i] = (dp[i] + dp[i - 2]) % MOD;
    }
  }
  std::cout << dp[n] << '\n';
  return 0;
}

