#include <bits/stdc++.h>

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int n;
  std::cin >> n;
  std::vector<int> s(n);
  for (int i = 0; i < n; ++i) {
    std::cin >> s[i];
  }
  std::map<std::pair<int, int>, int> digit, f;
  for (int i = 0; (1 << i) <= n; ++i) {
    int x = (1 << i);
    for (int j = 0; j < n; ++j) {
      if (j + x - 1 >= n) {
        break;
      }
      if (x == 1) {
        digit[{j, j}] = s[j] % 10;
        f[{j, j}] = 0;
      }
      else {
        int half = x / 2;
        int l1 = j, r1 = l1 + half - 1, l2 = r1 + 1, r2 = l2 + half - 1;
        int sum = digit[{l1, r1}] + digit[{l2, r2}];
        digit[{l1, r2}] = sum % 10;
        f[{l1, r2}] = f[{l1, r1}] + f[{l2, r2}] + (sum >= 10);
      }
    }
  }
  int q;
  std::cin >> q;
  while (q--) {
    int l, r;
    std::cin >> l >> r;
    --l;
    --r;
    std::cout << f[{l, r}] << '\n';
  }
  return 0;
}

