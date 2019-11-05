#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false); cin.tie(0);
  int n; cin >> n;
  vector<char> l(n), r(n);
  vector<int> _l, _r;
  vector<vector<int>> c(26);
  int cnt = 0;
  for (int i = 0; i < n; ++i) {
    cin >> l[i];
    if (l[i] == '?') _l.emplace_back(i + 1);
    else {
      c[l[i] - 'a'].emplace_back(i + 1);
      cnt++;
    }
  }
  vector<pair<int, int>> ans;
  vector<int> last;
  for (int i = 0; i < n; ++i) {
    cin >> r[i];
    if (r[i] == '?') _r.emplace_back(i + 1);
    else {
      if (!c[r[i] - 'a'].empty()) {
        ans.emplace_back(make_pair(c[r[i] - 'a'].back(), i + 1));
        c[r[i] - 'a'].pop_back();
        cnt--;
      }
      else last.emplace_back(i + 1);
    }
  }
  while (!_l.empty() && !last.empty()) {
    ans.emplace_back(make_pair(_l.back(), last.back()));
    _l.pop_back(); last.pop_back();
  }
  while (cnt > 0 && !_r.empty()) {
    for (int i = 0; i < 26; ++i) {
      while (!c[i].empty()) {
        ans.emplace_back(make_pair(c[i].back(), _r.back()));
        c[i].pop_back(); _r.pop_back();
        cnt--;
        if (cnt <= 0 || _r.empty()) break;
      }
      if (cnt <= 0 || _r.empty()) break;
    }
  }
  while (!_l.empty() && !_r.empty()) {
    ans.emplace_back(make_pair(_l.back(), _r.back()));
    _l.pop_back(); _r.pop_back();
  }
  cout << ans.size() << endl;
  for (auto &it : ans) cout << it.first << " " << it.second << endl;
  return 0;
}
