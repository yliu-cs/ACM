#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false); cin.tie(0);
  int n; cin >> n;
  map<string, string> mp;
  mp["a"] = "as"; mp["i"] = mp["y"] = "ios";
  mp["l"] = "les"; mp["n"] = "anes"; mp["ne"] = "anes";
  mp["o"] = "os"; mp["r"] = "res"; mp["t"] = "tas";
  mp["u"] = "us"; mp["v"] = "ves"; mp["w"] = "was";
  for (int i = 0; i < n; ++i) {
    string s; cin >> s;
    string temp;
    temp += s[s.size() - 2];
    temp += s[s.size() - 1];
    if (mp.find(temp) != mp.end()) {
      cout << s.substr(0, s.size() - 2) + mp[temp] << endl;
      continue;
    }
    temp = s[s.size() - 1];
    if (mp.find(temp) != mp.end()) {
      cout << s.substr(0, s.size() - 1) + mp[temp] << endl;
      continue;
    }
    s += "us";
    cout << s << endl;
  }
  return 0;
}

