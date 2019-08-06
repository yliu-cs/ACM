#include <bits/stdc++.h>
#include <bits/extc++.h>

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr); std::cout.tie(nullptr);

  int n, m; std::cin >> n >> m;
  long long ans = 0;
  std::vector<int> boy(n);
  std::set<int> boy_set;
  int max = 0;
  for (int &v : boy) {
    std::cin >> v;
    max = std::max(max, v);
    boy_set.insert(v);
    ans += 1ll * v * m;
  }
  std::vector<int> girl(m);
  std::vector<int> girl_vec;
  bool ok = false;
  for (int &v : girl) {
    std::cin >> v;
    if (v == max) ok = true;
    if (boy_set.find(v) != boy_set.end()) continue;
    girl_vec.emplace_back(v);
  }

  std::sort(boy.begin(), boy.end(), [&](int k1, int k2) { return k1 > k2; });
  std::sort(girl.begin(), girl.end(), [&](int k1, int k2) { return k1 > k2; });
  std::sort(girl_vec.begin(), girl_vec.end(), [&](int k1, int k2) { return k1 > k2; });

  if (girl.back() < boy[0]) {
    std::cout << -1 << '\n';
    return 0;
  }

  if (girl_vec.empty()) {
    std::cout << ans << '\n';
    return 0;
  }

  if (ok) {
    for (auto &v : girl_vec) ans += v - max;
    std::cout << ans << '\n';
    return 0;
  }

  int sz = (int)girl_vec.size();
  int girl_max = girl_vec[0], girl_se = girl_vec[1];
  ans += girl_max + girl_se - boy[0] - boy[1];
  for (int i = 2; i < sz; ++i) ans += girl_vec[i] - max;
  std::cout << ans << '\n';

  return 0;
}

