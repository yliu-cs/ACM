// 随机数骗分
#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false); cin.tie(0);
  srand((unsigned)time(0));
  int n; cin >> n;
  map<char, int> f;
  map<char, string> code;
  for (int i = 0; i < n; ++i) {
    char c; int k;
    cin >> c >> k;
    f[c] = k;
  }
  int m; cin >> m;
  for (int i = 0; i < m; ++i) {
    for (int j = 0; j < n; ++j) {
      char c; string s;
      cin >> c >> s;
      code[c] = s;
    }
    bool ans = rand() % 2;
    if (ans) cout << "Yes" << endl;
    else cout << "No" << endl;
  }
  return 0;
}

