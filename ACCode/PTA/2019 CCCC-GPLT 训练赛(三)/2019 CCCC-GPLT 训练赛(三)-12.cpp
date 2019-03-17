#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false); cin.tie(0);
  int n, m; cin >> n >> m;
  map<string, int> num;
  map<int, string> name;
  vector<vector<int>> son(n + 1);
  map<int, int> fa;
  map<int, int> dep;
  int last = 0;
  string s, na; getline(cin, na);
  getline(cin, na);
  num[na] = 1; name[1] = na; son[0].emplace_back(1); fa[1] = 0; dep[1] = 1;
  for (int i = 2; i <= n; ++i) {
    getline(cin, s); na.clear();
    int cnt = 0;
    for (auto &it : s) {
      if (it == ' ') cnt++;
      else na += it;
    }
    int level = cnt / 2 + 1;
    if (cnt == last) {
      num[na] = i;
      name[i] = na;
      son[dep[level - 1]].emplace_back(i);
      fa[i] = dep[level - 1];
      dep[level] = i;
    }
    else {
      num[na] = i;
      name[i] = na;
      son[dep[level - 1]].emplace_back(i);
      fa[i] = dep[level - 1];
      dep[level] = i;
      last = cnt;
    }
  }
  for (int i = 0; i < m; ++i) {
    string X, Y; cin >> X;
    cin >> s; cin >> s;
    if (s == "the") {
      cin >> s; cin >> s;
      cin >> Y;
      if (fa[num[Y]] == num[X]) cout << "True" << endl;
      else cout << "False" << endl;
    }
    else if (s == "an") {
      cin >> s; cin >> s;
      cin >> Y;
      if (X == Y) {
        cout << "False" << endl;
        continue;
      }
      int cur = fa[num[Y]]; bool flag = false;
      while (cur != 0) {
        if (name[cur] == X) {
          flag = true;
          break;
        }
        cur = fa[cur];
      }
      if (flag) cout << "True" << endl;
      else cout << "False" << endl;
    }
    else {
      cin >> s;
      if (s == "child") {
        cin >> s;
        cin >> Y;
        bool flag = false;
        for (auto &it : son[num[Y]]) {
          if (name[it] == X) {
            flag = true;
            break;
          }
        }
        if (flag) cout << "True" << endl;
        else cout << "False" << endl;
      }
      else if (s == "sibling") {
        cin >> s;
        cin >> Y;
        bool flag = false;
        for (auto &it : son[fa[num[X]]]) {
          if (it == num[X]) continue;
          if (name[it] == Y) {
            flag = true;
            break;
          }
        }
        if (flag) cout << "True" << endl;
        else cout << "False" << endl;
      }
      else {
        cin >> s;
        cin >> Y;
        if (X == Y) {
          cout << "False" << endl;
          continue;
        }
        int cur = fa[num[X]]; bool flag = false;
        while (cur != 0) {
          if (name[cur] == Y) {
            flag = true;
            break;
          }
          cur = fa[cur];
        }
        if (flag) cout << "True" << endl;
        else cout << "False" << endl;
      }
    }
  }
  return 0;
}

