#include <bits/stdc++.h>

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr); std::cout.tie(nullptr);

  std::string str; std::cin >> str;

  std::vector<long long> pref((int)str.size());
  pref[0] = str[0] == 'Q';
  for (int i = 1; i < (int)str.size(); ++i) pref[i] = pref[i - 1] + (str[i] == 'Q');

  long long ans = 0;
  for (int i = 2; i < (int)str.size() - 2; ++i) {
    if (str[i] == 'A') ans += pref[i - 2] * (pref[(int)str.size() - 1] - pref[i + 1]);
  }

  std::cout << ans << '\n';
  return 0;
}

