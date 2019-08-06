#include <bits/stdc++.h>

int n;
std::vector<int> h;
std::vector<int> v;

bool Check(int x) {
  for (int i = 0; i < n; ++i) {
    if (h[i] + x < v[i]) return false;
    if (h[i] + x > v[i]) return true;
  }
  return true;
}

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr); std::cout.tie(nullptr);

  std::cin >> n;
  h.assign(n, 0); v.assign(n, 0);
  for (auto &it : h) std::cin >> it;
  for (auto &it : v) std::cin >> it;

  int l = 0, r = 1e3 + 5, ans;
  while (l <= r) {
    int m = (l + r) >> 1;
    if (Check(m)) {
      ans = m;
      r = m - 1;
    }
    else l = m + 1;
  }

  std::cout << ans << '\n';
  return 0;
}
