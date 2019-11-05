#include <bits/stdc++.h>
const int inf = 0x3f3f3f3f;

int GetDis(char k1, char k2) {
  int n1 = (int)(k1 - 'A'), n2 = (int)(k2 - 'A');
  return std::min(std::max(n1, n2) - std::min(n1, n2), std::min(n1, n2) + 26 - std::max(n1, n2));
}

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr); std::cout.tie(nullptr);

  int n; std::cin >> n;
  std::string str; std::cin >> str;

  int ans = inf;
  for (int i = 0; i < n - 3; ++i) {
    ans = std::min(ans, GetDis(str[i], 'A') + GetDis(str[i + 1], 'C') + GetDis(str[i + 2], 'T') + GetDis(str[i + 3], 'G'));
  }

  std::cout << ans << '\n';
  return 0;
}

