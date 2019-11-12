#include <bits/stdc++.h>

const int INF = 1e9 + 5;

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int n;
  std::cin >> n;
  std::string str;
  std::cin >> str;
  std::vector<int> val(n);
  int min = INF;
  for (int i = 0; i < n; ++i) {
    if (i == 0) {
      val[i] = 0;
    }
    else {
      val[i] = val[i - 1];
    }
    if (str[i] == '(') {
      ++val[i];
    }
    else {
      --val[i];
    }
    min = std::min(min, val[i]);
  }
  if (min >= -1 && val.back() == 0) {
    std::cout << "Yes" << '\n';
  }
  else {
    std::cout << "No" << '\n';
  }
  return 0;
}

