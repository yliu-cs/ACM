#include <bits/stdc++.h>
const int inf = 1e9 + 5;

struct SparseTable {
  std::vector<int> arr;
  std::vector<std::vector<int>> min;

  SparseTable(const std::vector<int> &ori) {
    arr.assign(ori.begin(), ori.end());
    int n = arr.size(), m = log2(n) + 1;
    min = std::vector<std::vector<int>>(n, std::vector<int>(m, 0));
    for (int i = 0; i < n; ++i) min[i][0] = i;
    for (int j = 1; j < m; ++j) {
      for (int i = 0; i + (1 << j) - 1 < n; ++i) {
        if (arr[min[i][j - 1]] < arr[min[i + (1 << (j - 1))][j - 1]]) min[i][j] = min[i][j - 1];
        else min[i][j] = min[i + (1 << (j - 1))][j - 1];
      }
    }
  }

  int Query(int l, int r) {
    int k = log2(r - l + 1);
    if (arr[min[l][k]] < arr[min[r - (1 << k) + 1][k]]) return min[l][k];
    return min[r - (1 << k) + 1][k];
  }
};

int main() {
  int n;
  while (std::cin >> n) {
    std::vector<int> a(n), b(n);
    for (int &v : a) std::cin >> v;
    for (int &v : b) std::cin >> v;
    SparseTable ST_a(a), ST_b(b);
    int ans = 0;
    for (int i = 1; i < n; ++i) {
      if (ST_a.Query(0, i) != ST_b.Query(0, i)) break;
      ++ans;
    }
    std::function<int(int, int)> Find = [&](int l, int r) {
      if (r - l < 1) return r;
      int idx_a = ST_a.Query(l, r), idx_b = ST_b.Query(l, r);
      if (idx_a == idx_b) {
        int fl = Find(l, idx_a - 1), fr = Find(idx_a + 1, r);
        if (fl == idx_a - 1) return fr;
        return fl;
      }
      return Find(0, std::max(idx_a, idx_b) - 1);
    };
    ans = Find(0, ans);
    printf("%d\n", ans + 1);
  }
  return 0;
}