#include <bits/stdc++.h>

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  long long n, m, k;
  std::cin >> n >> m >> k;
  std::queue<long long> que;
  for (int i = 0; i < m; ++i) {
    long long x;
    std::cin >> x;
    que.push(x - 1);
  }
  long long ans = 0, offset = 0;
  while (!que.empty()) {
    long long fi = que.front(), cnt = 1;
    que.pop();
    while (!que.empty() && (que.front() - offset) / k == (fi - offset) / k) {
      ++cnt;
      que.pop();
    }
    offset += cnt;
    ++ans;
  }
  std::cout << ans << '\n';
  return 0;
}

