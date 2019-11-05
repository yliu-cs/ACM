#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false); cin.tie(0);
  queue<char> a; stack<char> b;
  string s; cin >> s;
  map<char, int> pos;
  for (auto &it : s) {
    a.push(it);
    pos[it] = 1;
  }
  cin >> s;
  vector<pair<int, int>> ans;
  for (auto &it : s) {
    cerr << "it: " << it << endl;
    cerr << "pos: " << pos[it] << endl;
    if (pos[it] == 1) {
      while (a.front() != it) {
        b.push(a.front());
        pos[a.front()] = 3;
        a.pop();
        ans.emplace_back(make_pair(1, 3));
      }
      pos[it] = 2;
      a.pop();
      ans.emplace_back(make_pair(1, 2));
    }
    else if (pos[it] == 3) {
      if (b.top() == it) {
        b.pop();
        pos[it] = 2;
        ans.emplace_back(make_pair(3, 2));
      }
      else {
        cout << "Are you kidding me?" << endl;
        return 0;
      }
    }
  }
  for (auto &it : ans) cout << it.first << "->" << it.second << endl;
  return 0;
}

