#include <bits/stdc++.h>
#include <bits/extc++.h>

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr); std::cout.tie(nullptr);

  int n; std::cin >> n;
  std::vector<int> cnt(26, 0);
  for (int i = 0; i < n; ++i) {
    std::string str; std::cin >> str;
    ++cnt[str[0] - 'a'];
  }

  long long ans = 0;
  for (int i = 0; i < 26; ++i) {
    if (cnt[i] & 1) {
      cnt[i] = cnt[i] / 2 + 1;
      ans += (cnt[i] - 1) * cnt[i] / 2;
      --cnt[i];
      ans += (cnt[i] - 1) * cnt[i] / 2;
    }
    else {
      cnt[i] /= 2;
      ans += (cnt[i] - 1) * cnt[i];
    }
  }
  std::cout << ans << '\n';

  return 0;
}

