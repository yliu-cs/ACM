#include <bits/stdc++.h>

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr); std::cout.tie(nullptr);

  int n; std::cin >> n;
  std::vector<int> arr(n);
  for (int &v : arr) std::cin >> v;
  std::reverse(arr.begin(), arr.end());

  bool flag = true;
  int cnt = 0;
  for (int i = 1; i < n; ++i) {
    if ((arr[i - 1] == 2 && arr[i] == 3) || (arr[i] == 2 && arr[i - 1] == 3)) {
      flag = false;
      break;
    }
    if ((arr[i - 1] == 1 && arr[i] == 2) || (arr[i - 1] == 2 && arr[i] == 1)) cnt += 3;
    if ((arr[i - 1] == 1 && arr[i] == 3) || (arr[i - 1] == 3) && arr[i] == 1) cnt += 4;
  }

  if (!flag) std::cout << "Infinite" << '\n';
  else {
    for (int i = 2; i < n; ++i) {
      if (arr[i - 2] == 2 && arr[i - 1] == 1 && arr[i] == 3) cnt--;
    }
    std::cout << "Finite" << '\n' << cnt << '\n';
  }
  return 0;
}

