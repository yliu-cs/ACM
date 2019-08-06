#include <bits/stdc++.h>

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0); std::cout.tie(0);

  int n; std::cin >> n;
  std::vector<long long> arr(n);
  std::map<long long, long long> cnt;
  for (auto &it : arr) {
    std::cin >> it;
    ++cnt[it];
  }

  std::vector<std::pair<long long, long long>> vec(cnt.begin(), cnt.end());
  sort(vec.begin(), vec.end(), [&](std::pair<long long, long long> k1, std::pair<long long, long long> k2) {
    return k1.second > k2.second;
  });

  long long max = vec[0].first;

  std::vector<std::pair<int, int>> seg;
  int l = 0, r;
  while (l < n) {
    r = l;
    if (arr[l] == max) {
      while (arr[r] == max && r < n) ++r;
      seg.push_back({l, r - 1});
      l = r;
    }
    else ++l;
  }

  if (seg.empty()) {
    std::cout << 0 << '\n';
    return 0;
  }

  auto Check = [&](long long x, long long y) -> bool {
    if (x >= 0 && y >= 0) {
      if (y > x) return true;
      else return false;
    }
    else if (x <= 0 && y <= 0) {
      if (y < x) return false;
      else return true;
    }
  };

  struct ac {int op, i, j;};
  std::vector<ac> ans;
  for (int i = seg[0].first - 1; i >= 0; --i) {
    if (Check(arr[i], max)) ans.push_back((ac){1, i, i + 1});
    else ans.push_back((ac){2, i, i + 1});
  }

  for (int i = 1; i < (int)seg.size(); ++i) {
    for (int j = seg[i - 1].second + 1; j < seg[i].first; ++j) {
      if (Check(arr[j], max)) ans.push_back((ac){1, j, j - 1});
      else ans.push_back((ac){2, j, j - 1});
    }
  }

  for (int i = seg.back().second + 1; i < n; ++i) {
    if (Check(arr[i], max)) ans.push_back((ac){1, i, i - 1});
    else ans.push_back((ac){2, i, i - 1});
  }

  std::cout << (int)ans.size() << '\n';
  for (auto &it : ans) std::cout << it.op << " " << it.i + 1 << " " << it.j + 1 << '\n';
  return 0;
}