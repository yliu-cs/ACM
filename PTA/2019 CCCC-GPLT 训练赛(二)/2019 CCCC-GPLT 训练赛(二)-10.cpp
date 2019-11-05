#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false); cin.tie(0);
  int n; cin >> n;
  map<int, int> mark;
  for (int i = 0, k, x; i < n; ++i) {
    cin >> k;
    if (k == 1) {
      cin >> x;
      continue;
    }
    for (int j = 0, u; j < k; ++j) {
      cin >> u;
      ++mark[u];
    }
  }
  set<int> vis;
  int m; cin >> m;
  bool flag = false;
  for (int i = 0, x; i < m; ++i) {
    cin >> x;
    if (vis.find(x) != vis.end()) continue;
    vis.insert(x);
    if (mark[x] == 0) {
      if (flag) cout << " ";
      else flag = true;
      if (x < 10) cout << "0000";
      else if (x < 100) cout << "000";
      else if (x < 1000) cout << "00";
      else if (x < 10000) cout << "0";
      cout << x;
    }
  }
  if (!flag) cout << "No one is handsome";
  return 0;
}

