#include <bits/stdc++.h>
#include <bits/extc++.h>

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr); std::cout.tie(nullptr);

  std::vector<int> ele = {4, 8, 15, 16, 23, 42};
  std::set<int> set;
  for (int &v : ele) set.insert(v);
  std::vector<int> ans(6);
  std::vector<bool> vis(6, false);
  int x, v;

  std::cout << "? 1 1" << std::endl;
  std::cin >> x;
  v = sqrt(x);
  ans[0] = v;
  set.erase(v);
  for (int i = 0; i < 6; ++i) {
    if (ele[i] == v) vis[i] = true;
  }

  std::cout << "? 2 2" << std::endl;
  std::cin >> x;
  v = sqrt(x);
  ans[1] = v;
  set.erase(v);
  for (int i = 0; i < 6; ++i) {
    if (ele[i] == v) vis[i] = true;
  }

  std::cout << "? 3 4" << std::endl;
  std::cin >> x;
  int a = -1, b = -1;
  for (int i = 0; i < 6; ++i) {
    if (vis[i]) continue;
    for (int j = i + 1; j < 6; ++j) {
      if (vis[j]) continue;
      if (ele[i] * ele[j] == x) {
        a = ele[i];
        b = ele[j];
      }
    }
  }

  std::cout << "? 4 5" << std::endl;
  std::cin >> x;
  for (int i = 0; i < 6; ++i) {
    if (vis[i]) continue;
    for (int j = i + 1; j < 6; ++j) {
      if (vis[j]) continue;
      if (ele[i] * ele[j] == x) {
        if (ele[i] == a) {
          ans[3] = a;
          ans[2] = b;
          ans[4] = ele[j];
          set.erase(a);
          set.erase(b);
          set.erase(ele[j]);
        }
        else if (ele[i] == b) {
          ans[3] = b;
          ans[2] = a;
          ans[4] = ele[j];
          set.erase(a);
          set.erase(b);
          set.erase(ele[j]);
        }
        else if (ele[j] == a) {
          ans[3] = a;
          ans[2] = b;
          ans[4] = ele[i];
          set.erase(a);
          set.erase(b);
          set.erase(ele[i]);
        }
        else if (ele[j] == b) {
          ans[3] = b;
          ans[2] = a;
          ans[4] = ele[i];
          set.erase(a);
          set.erase(b);
          set.erase(ele[i]);
        }
      }
    }
  }

  std::cout << '!';
  for (int i = 0; i < 5; ++i) std::cout << ' ' << ans[i];
  std::cout << ' ' << *set.begin();
  return 0;
}

