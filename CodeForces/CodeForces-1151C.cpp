#include <bits/stdc++.h>
const int mod = 1e9 + 7;
const int inv = 5e8 + 4;

long long GetSum(long long x) {
  long long ret = 0, len = 1;
  bool cur = false;
  long long pos[] = {1, 2};
  while (x) {
    long long cnt = std::min(len, x);
    x -= cnt; cnt %= mod;
    long long front = pos[cur];
    pos[cur] = (pos[cur] + cnt * 2ll % mod) % mod;
    long long back = (pos[cur] - 2 + mod) % mod;
    ret = (ret + (front + back) * cnt % mod * inv % mod) % mod;
    len *= 2ll; cur = !cur;
  }
  return ret;
}

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr); std::cout.tie(nullptr);

  long long l, r; std::cin >> l >> r;
  std::cout << (GetSum(r) - GetSum(l - 1) + mod) % mod << '\n';
  return 0;
}

