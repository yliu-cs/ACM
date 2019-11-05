#include <bits/stdc++.h>

std::vector<int> arr, buf;
std::vector<int> d = {-1, 0, 1, 2, 0, 2, 1, 0};

int Calc(int s) {
  int ret = 0;
  for (int i = s; i <= 7; ++i) {
    if (buf[d[i]]) --buf[d[i]];
    else return ret;
    ++ret;
  }
  int cir = std::min(buf[0] / 3, std::min(buf[1] / 2, buf[2] / 2));
  buf[0] -= cir * 3; buf[1] -= cir * 2; buf[2] -= cir * 2;
  ret += 7 * cir;
  for (int i = 1; i <= 7; ++i) {
    if (buf[d[i]]) --buf[d[i]];
    else return ret;
    ++ret;
  }
}

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr); std::cout.tie(nullptr);

  arr.assign(3, 0);
  for (auto &v : arr) std::cin >> v;

  int ans = 0;
  for (int i = 1; i <= 7; ++i) {
    buf = arr;
    ans = std::max(ans, Calc(i));
  }

  std::cout << ans << '\n';
  return 0;
}

