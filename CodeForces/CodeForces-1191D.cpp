#include <bits/stdc++.h>

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int n;
  std::cin >> n;
  std::vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    std::cin >> a[i];
  }
  std::map<int, int> cnt;
  for (int i = 0; i < n; ++i) {
    ++cnt[a[i]];
  }
  std::sort(a.begin(), a.end());
  std::vector<int> b(a.begin(), a.end());
  b.erase(std::unique(b.begin(), b.end()), b.end());
  int pre = 0;
  for (int i = 0; i < (int)b.size(); ++i) {
    if (b[i] == 0 && cnt[b[i]] > 1) {
      std::cout << "cslnb" << '\n';
      return 0;
    }
    if (i > 0 && cnt[b[i]] > 1 && b[i - 1] == b[i] - 1) {
      std::cout << "cslnb" << '\n';
      return 0;
    }
    if (cnt[b[i]] > 2) {
      std::cout << "cslnb" << '\n';
      return 0;
    }
    if (cnt[b[i]] >= 2) {
      ++pre;
    }
    if (pre > 1) {
      std::cout << "cslnb" << '\n';
      return 0;
    }
  }
  int lst = 0, ans = 0;
  for (int i = 0; i < n; ++i) {
    ans += a[i] - lst;
    ++lst;
  }
  if (ans & 1) {
    std::cout << "sjfnb" << '\n';
  }
  else {
    std::cout << "cslnb" << '\n';
  }
  return 0;
}

