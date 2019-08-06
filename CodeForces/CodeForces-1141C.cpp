#include <bits/stdc++.h>
using namespace std;
const long long inf = 0x3f3f3f3f;

int main() {
  ios::sync_with_stdio(false); cin.tie(0);
  long long n; cin >> n;
  vector<long long> q(n - 1, 0);
  for (auto &it : q) cin >> it;
  vector<long long> p(n, 0);
  set<long long> vis; vis.insert(0);
  long long _max = 0, _min = 0;
  for (int i = 1; i < n; ++i) {
    p[i] = p[i - 1] + q[i - 1];
    _max = max(_max, p[i]);
    _min = min(_min, p[i]);
    if (vis.find(p[i]) == vis.end()) vis.insert(p[i]);
    else {
      cout << -1 << endl;
      return 0;
    }
  }
  long long diff = abs(1 - _min);
  if (_max + diff > n) {
    cout << -1 << endl;
    return 0;
  }
  for (auto &it : p) cout << it + diff << " ";
  cout << endl;
  return 0;
}
