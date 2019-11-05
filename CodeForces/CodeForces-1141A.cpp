#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false); cin.tie(0);
  long long n, m; cin >> n >> m;
  if (n > m) swap(n, m);
  else if (n == m) {
    cout << 0 << endl;
    return 0;
  }
  queue<pair<long long, int>> que;
  que.push(make_pair(n, 0));
  while (!que.empty()) {
    pair<long long, int> cur = que.front(); que.pop();
    if (cur.first == m) {
      cout << cur.second << endl;
      return 0;
    }
    if (cur.first * 2 <= m) que.push(make_pair(cur.first * 2, cur.second + 1));
    if (cur.first * 3 <= m) que.push(make_pair(cur.first * 3, cur.second + 1));
  }
  cout << -1 << endl;
  return 0;
}
