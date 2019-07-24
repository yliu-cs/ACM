#include <bits/stdc++.h>
const int maxn = 1e6 + 5;

int n;
char str[maxn];
long long pref[maxn], last[maxn];
long long ans;

int main() {
  std::cin >> str;
  n = std::strlen(str);
  for (int i = 1; i < n; ++i) {
    pref[i] = pref[i - 1];
    if (str[i - 1] == str[i] && str[i] == 'v') ++pref[i];
  }
  for (int i = n - 2; i >= 0; --i) {
    last[i] = last[i + 1];
    if (str[i + 1] == str[i] && str[i] == 'v') ++last[i];
  }
  for (int i = 0; i < n; ++i) {
    if (str[i] == 'o') ans += pref[i] * last[i];
  }
  std::cout << ans << '\n';
  return 0;
}