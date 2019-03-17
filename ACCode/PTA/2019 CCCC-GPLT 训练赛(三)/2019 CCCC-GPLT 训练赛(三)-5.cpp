#include <bits/stdc++.h>
using namespace std;

int main() {
  int n; cin >> n;
  map<int, pair<long long, int>> mp;
  for (int i = 0; i < n; ++i) {
    long long id; int v1, v2;
    cin >> id >> v1 >> v2;
    mp[v1] = make_pair(id, v2);
  }
  int m; cin >> m;
  for (int i = 0, x; i < m; ++i) {
    cin >> x;
    cout << mp[x].first << " " << mp[x].second << endl;
  }
  return 0;
}

