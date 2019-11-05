#include <bits/stdc++.h>
#include <bits/extc++.h>

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr); std::cout.tie(nullptr);

  int n; std::cin >> n;
  
  if (n < 25) {
    std::cout << -1 << '\n';
    return 0;
  }

  bool flag = false;
  int k;

  for (int i = 5; i * i <= n; ++i) {
    if (n % i == 0) {
      k = i;
      flag = true;
      break;
    }
  }

  if (!flag) {
    std::cout << -1 << '\n';
    return 0;
  }

  int r = k, c = n / k;
  std::vector<char> ch = {'a', 'e', 'i', 'o', 'u'};

  for (int i = 0, ik = 0; i < r; ++i, ++ik) {
    int idx = ik;
    for (int j = 0; j < c; ++j) {
      std::cout << ch[(idx++) % 5];
    }
  }

  return 0;
}

