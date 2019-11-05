#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false); cin.tie(0);
  int n; cin >> n;
  vector<vector<int>> matrix(n, vector<int>(n, 0));
  for (auto &i : matrix) for (auto &j : i) cin >> j;
  auto Check = [&](int x, int y) -> bool {
    for (int i = 0; i < n; ++i)
      if (matrix[x][i] > matrix[x][y]) return false;
    for (int i = 0; i < n; ++i)
      if (matrix[i][y] < matrix[x][y]) return false;
    return true;
  };
  bool flag = false;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      if (Check(i, j)) {
        cout << i << " " << j << endl;
        flag = true;
        break;
      }
    }
    if (flag) break;
  }
  if (!flag) cout << "NONE" << endl;
  return 0;
}

