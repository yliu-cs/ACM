#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false); cin.tie(0);
  vector<string> v; string s;
  while (cin >> s) v.emplace_back(s);
  reverse(v.begin(), v.end());
  if (!v.empty()) cout << v[0];
  for (int i = 1; i < v.size(); ++i) cout << " " << v[i];
  return 0;
}

