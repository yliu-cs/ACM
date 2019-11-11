#include <bits/stdc++.h>

const int INF = 1e9 + 5;

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int t;
  std::cin >> t;
  while (t--) {
    int n;
    long long s;
    std::cin >> n >> s;
    std::vector<std::pair<int, int>> emp(n);
    for (auto &pr : emp) {
      std::cin >> pr.first >> pr.second;
    }
    auto Check = [&] (int x) -> bool {
      std::vector<int> buf;
      int cnt = 0;
      long long sum = 0;
      for (auto &pr : emp) {
        if (pr.second < x) {
          sum += pr.first;
        }
        else if (pr.first >= x) {
          sum += pr.first;
          ++cnt;
        }
        else {
          buf.push_back(pr.first);
        }
      }
      std::sort(buf.begin(), buf.end());
      int need = std::max(0, (n + 1) / 2 - cnt);
      if (need > (int)buf.size()) {
        return false;
      }
      for (int i = 0; i < (int)buf.size(); ++i) {
        if (i < (int)buf.size() - need) {
          sum += buf[i];
        }
        else {
          sum += x;
        }
      }
      return sum <= s;
    };
    int l = 1, r = INF, ans = l;
    while (l <= r) {
      int m = (l + r) / 2;
      if (Check(m)) {
        ans = m;
        l = m + 1;
      }
      else {
        r = m - 1;
      }
    }
    std::cout << ans << '\n';
  }
  return 0;
}

