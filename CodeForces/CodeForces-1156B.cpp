#include <bits/stdc++.h>

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr); std::cout.tie(nullptr);

  int t; std::cin >> t;
  for (int cas = 1; cas <= t; ++cas) {
    std::string str; std::cin >> str;

    std::vector<int> odd, even;
    for (char &c : str) {
      int v = c - 'a';
      if (v & 1) odd.push_back(v);
      else even.push_back(v);
    }

    std::sort(odd.begin(), odd.end());
    std::sort(even.begin(), even.end());
    std::reverse(odd.begin(), odd.end());
    std::reverse(even.begin(), even.end());

    std::vector<int> ans;
    if (odd.empty()) {
      for (int &v : even) ans.push_back(v);
    }
    else if (even.empty()) {
      for (int &v : odd) ans.push_back(v);
    }
    else if (abs(odd.back() - even[0]) != 1) {
      for (int &v : odd) ans.push_back(v);
      for (int &v : even) ans.push_back(v);
    }
    else {
      for (int &v : even) ans.push_back(v);
      for (int &v : odd) ans.push_back(v);
    }

    bool flag = true;
    for (int i = 1; i < (int)ans.size(); ++i) {
      if (abs(ans[i] - ans[i - 1]) == 1) {
        flag = false;
        break;
      }
    }

    if (flag) {
      for (int &v : ans) std::cout << (char)(v + 'a');
      std::cout << '\n';
    }
    else std::cout << "No answer" << '\n';
  }
  return 0;
}

