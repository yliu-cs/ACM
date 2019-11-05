#include <bits/stdc++.h>

template <typename type>
class STTable {
  public:
    std::vector<std::vector<type>> max, min;

    STTable(const std::vector<type> &arr) {
      int n = (int)arr.size(), m = log2(n) + 1;
      max = min = std::vector<std::vector<type>>(n, std::vector<type>(m, 0));
      for (int i = 0; i < n; ++i) max[i][0] = min[i][0] = arr[i];
      for (int j = 1; j < m; ++j) {
        for (int i = 0; i + (1 << j) - 1 < n; ++i) {
          max[i][j] = std::max(max[i][j - 1], max[i + (1 << (j - 1))][j - 1]);
          min[i][j] = std::min(min[i][j - 1], min[i + (1 << (j - 1))][j - 1]);
        }
      }
    }

    type QueryMax(int l, int r) {
      int k = log2(r - l + 1);
      return std::max(max[l][k], max[r - (1 << k) + 1][k]);
    }

    type QueryMin(int l, int r) {
      int k = log2(r - l + 1);
      return std::min(min[l][k], min[r - (1 << k) + 1][k]);
    }
};

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr); std::cout.tie(nullptr);

  int n, m; std::cin >> n >> m;
  std::vector<int> arr(n);
  for (auto &v : arr) std::cin >> v;

  STTable<int> ST(arr);

  for (int i = 0, l, r; i < m; ++i) {
    std::cin >> l >> r;
    --l; --r;
    std::cout << ST.QueryMax(l, r) << '\n';
  }
  return 0;
}
