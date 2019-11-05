#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
  priority_queue<int, vector<int>, greater<int> > que;
  map<int, string> mp;
  int n; cin >> n;
  for (int i = 0; i < n; ++i) {
    string op; cin >> op;
    if (op == "PUT") {
      string name; int v;
      cin >> name >> v;
      mp[v] = name;
      que.push(v);
    }
    else {
      if (que.empty()) cout << "EMPTY QUEUE!" << endl;
      else {
        cout << mp[que.top()] << endl;
        que.pop();
      }
    }
  }
  return 0;
}

