#include <bits/stdc++.h>

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int n, k;
  std::cin >> n >> k;
  long long l = 0, r = 1e5 + 5, record = 0;
  while (l <= r) {
    long long m = (l + r) / 2;
    if (m * m + m >= 2 * k) {
      record = m;
      r = m - 1;
    }
    else {
      l = m + 1;
    }
  }
  long long sum = (record * (record + 1)) / 2;
  long long cnt = record + sum - k;
  while (cnt < n) {
    ++record;
    sum = (record * (record + 1)) / 2;
    cnt = record + sum - k;
  }
  std::cout << sum - k << '\n';
  return 0;
}

