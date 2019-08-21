// Author: Tony5t4rk Time: 2019-08-20 22:43:51 
#include <bits/stdc++.h>
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int n, l, r;
  std::cin >> n >> l >> r;
  long long sum = 1, cur = 1;
  int idx = 2;
  while (idx <= l) {
    cur *= 2ll;
    sum += cur;
    ++idx;
  }
  long long min = sum + (n - idx + 1);
  while (idx <= r) {
    cur *= 2ll;
    sum += cur;
    ++idx;
  }
  long long max = sum + (n - idx + 1) * cur;
  std::cout << min << ' ' << max << '\n';
  return 0;
}
