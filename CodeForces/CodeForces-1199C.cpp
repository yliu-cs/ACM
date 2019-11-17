#include <bits/stdc++.h>

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int n, k;
  std::cin >> n >> k;
  std::vector<int> a(n);
  std::map<int, int> map;
  for (int i = 0; i < n; ++i) {
    std::cin >> a[i];
    ++map[a[i]];
  }
  std::sort(a.begin(), a.end());
  a.erase(std::unique(a.begin(), a.end()), a.end());
  std::vector<long long> suf((int)a.size(), 0);
  for (int i = (int)a.size() - 1; i >= 0; --i) {
    if (i == (int)a.size() - 1) {
      suf[i] = map[a[i]];
    }
    else {
      suf[i] = suf[i + 1] + map[a[i]];
    }
  }
  std::vector<long long> pre((int)a.size() + 1, 0);
  for (int i = 0; i < (int)a.size(); ++i) {
    if (i == 0) {
      pre[i] = map[a[i]];
    }
    else {
      pre[i] = pre[i - 1] + map[a[i]];
    }
  }
  long long num = 1ll << std::min(20ll, (long long)(k * 8ll / n)), ans = 1e18 + 5;
  for (int l = 0; l < (int)a.size(); ++l) {
    int r = std::min((long long)a.size() - 1, (long long)(l + num - 1));
    long long buf = 0;
    if (l - 1 >= 0) {
      buf += pre[l - 1];
    }
    if (r + 1 < (int)a.size()) {
      buf += suf[r + 1];
    }
    ans = std::min(ans, buf);
  }
  std::cout << ans << '\n';
  return 0;
}

