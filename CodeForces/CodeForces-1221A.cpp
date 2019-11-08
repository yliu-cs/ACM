#include <bits/stdc++.h>

int t, n;
std::multiset<long long> set;
bool f;

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cin >> t;
  while (t--) {
    std::cin >> n;
    set.clear();
    for (int i = 1; i <= n; ++i) {
      long long x;
      std::cin >> x;
      if (x <= 2048) {
        set.insert(x);
      }
    }
    f = false;
    while ((int)set.size() > 1) {
      auto it1 = set.begin();
      set.erase(it1);
      auto it2 = set.begin();
      set.erase(it2);
      if ((*it1) == 2048) {
        f = true;
        break;
      }
      if ((*it1) > 2048) {
        break;
      }
      if ((*it1) == (*it2)) {
        set.insert((*it1) + (*it2));
      }
      else {
        set.insert((*it2));
      }
    }
    if (!set.empty() && (*set.begin()) == 2048) {
      f = true;
    }
    if (f) {
      std::cout << "YES" << '\n';
    }
    else {
      std::cout << "NO" << '\n';
    }
  }
  return 0;
}

