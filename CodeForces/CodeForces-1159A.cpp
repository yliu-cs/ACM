#include <bits/stdc++.h>
#include <bits/extc++.h>
const int inf = 1e2 + 5;

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr); std::cout.tie(nullptr);

  int n; std::cin >> n;
  std::string str; std::cin >> str;
  int l = 0, r = inf;
  int ans = inf;
  while (l <= r) {
    int m = (l + r) / 2;
    int cnt = m;
    bool flag = true;
    for (char &c : str) {
      if (c == '-') --cnt;
      else ++cnt;
      if (cnt < 0) flag = false;
    }
    if (!flag) l = m + 1;
    else {
      ans = cnt;
      r = m - 1;
    }
  }
  std::cout << ans << '\n';

  return 0;
}

