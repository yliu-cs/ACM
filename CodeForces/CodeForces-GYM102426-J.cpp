#include <bits/stdc++.h>

const int N = 1e5 + 5;

int n;
bool flag[N];
long long ans;

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cin >> n;
  for (int i = n; i >= 1; --i) {
    if (flag[i]) {
      continue;
    }
    if (i & 1) {
      ans += i;
    }
    else {
      ans += i;
      flag[i / 2] = true;
    }
  }
  std::cout << ans << '\n';
  return 0;
}

