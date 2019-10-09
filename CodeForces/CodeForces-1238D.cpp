// Author: Tony5t4rk Time: 2019-10-09 23:40:53 
#include <bits/stdc++.h>
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int n;
  std::cin >> n;
  std::string str;
  std::cin >> str;
  long long ans = 1ll * n * (n + 1) / 2 - n;
  int idx[2] = {-1, -1};
  for (int i = 0; i < n; ++i) {
    int f = str[i] - 'A';
    if (idx[!f] != -1) {
      if (idx[!f] == i - 1) {
        if (idx[f] != -1) ans -= idx[!f] - idx[f];
        else ans -= idx[!f] + 1;
      }
      else --ans;
    }
    idx[f] = i;
  }
  std::cout << ans << '\n';
  return 0;
}
