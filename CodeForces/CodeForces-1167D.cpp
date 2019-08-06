#include <bits/stdc++.h>
#include <bits/extc++.h>

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr); std::cout.tie(nullptr);

  int n; std::cin >> n;
  std::string str; std::cin >> str;
  std::vector<int> vis;
 
  auto Check = [&](int x) -> bool {
    vis.assign(n, 0);
    int cnt = 0;
    for (int i = 0; i < n; ++i) {
      if (str[i] == '(' && cnt < x) {
        ++cnt;
        vis[i] = 1;
      }
      else if (str[i] == ')' && cnt > 0) {
        --cnt;
        vis[i] = 1;
      }
    }
    cnt = 0;
    for (int i = 0; i < n; ++i) {
      if (vis[i]) continue;
      if (str[i] == '(') {
        ++cnt;
        if (cnt > x) return false;
      }
      else --cnt;
    }
    return true;
  };

  std::vector<int> ans;
  int l = 0, r = 2e5 + 5;
  while (l <= r) {
    int m = (l + r) / 2;
    if (Check(m)) {
      ans = vis;
      r = m - 1;
    }
    else l = m + 1;
  }

  for (int &v : ans) std::cout << v;
  std::cout << '\n';

  return 0;
}

