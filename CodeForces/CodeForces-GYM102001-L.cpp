#include <bits/stdc++.h>
const long long inf = 1ll << 61;

std::vector<bool> vis;

long long Num(std::string str) {
  long long ans = 0, k = 0;
  for (long long i = str.length() - 1; i >= 0; --i) {
    if (vis[i] == false) continue;
    if (str[i] == '1') ans += 1ll << k;
    k++;
  }
  return ans;
}

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0); std::cout.tie(0);

  long long k; std::cin >> k;
  std::string str; std::cin >> str;
  std::vector<int> one_pos, zero_pos;
  for (int i = 1; i < (int)str.length(); ++i) {
    if (str[i] == '1') one_pos.emplace_back(i);
    else zero_pos.emplace_back(i);
  }

  vis.assign(str.size(), true);
  long long bit = Num(str), cnt = 0;
  while (bit > k) {
    long long v1 = inf, v2 = inf;
    if (!one_pos.empty()) {
      vis[one_pos[0]] = false;
      v1 = Num(str);
      vis[one_pos[0]] = true;
    }
    if (!zero_pos.empty()) {
      vis[zero_pos.back()] = false;
      v2 = Num(str);
      vis[zero_pos.back()] = true;
    }
    if (v1 < v2) {
      vis[one_pos[0]] = false;
      one_pos.erase(one_pos.begin());
      bit = v1;
    }
    else {
      vis[zero_pos.back()] = false;
      zero_pos.pop_back();
      bit = v2;
    }
    cnt++;
  }

  std::cout << cnt << '\n';
  return 0;
}
