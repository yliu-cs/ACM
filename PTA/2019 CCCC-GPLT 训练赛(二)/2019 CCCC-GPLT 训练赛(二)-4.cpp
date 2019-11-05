#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false); cin.tie(0);
  int n; cin >> n; n <<= 1;
  vector<vector<char>> matrix(n, vector<char>(n));
  for (auto &i : matrix) for (auto &j : i) cin >> j;
  int k; cin >> k; int cnt = 0; int suc = n * n;
  for (int i = 0, x1, y1, x2, y2; i < k; ++i) {
    cin >> x1 >> y1 >> x2 >> y2;
    --x1; --y1; --x2; --y2;
    if (matrix[x1][y1] == matrix[x2][y2] && matrix[x1][y1] != '*') {
      matrix[x1][y1] = matrix[x2][y2] = '*';
      suc -= 2;
      if (suc == 0) {
        cout << "Congratulations!";
        break;
      }
      for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
          if (j != 0) cout << " ";
          cout << matrix[i][j];
        }
        cout << endl;
      }
    }
    else {
      cout << "Uh-oh" << endl;
      cnt++;
      if (cnt >= 3) {
        cout << "Game Over";
        break;
      }
    }
  }
  return 0;
}

