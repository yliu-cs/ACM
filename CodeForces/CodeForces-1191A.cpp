#include <bits/stdc++.h>

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::vector<int> idx = {4, 1, 3, 2};
  int x;
  std::cin >> x;
  std::vector<int> record;
  for (int i = 0; i <= 2; ++i) {
    int y = x + i;
    record.push_back(y);
  }
  std::sort(record.begin(), record.end(),
    [&](int k1, int k2) {
       return idx[k1 % 4] < idx[k2 % 4];
    }
  );
  std::cout << record[0] - x << ' ' << (char)(idx[record[0] % 4] - 1 + 'A');
  return 0;
}

