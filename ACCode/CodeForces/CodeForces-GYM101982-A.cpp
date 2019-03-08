#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false); cin.tie(0);
  int k; cin >> k;
  int cnt1 = 0, cnt2 = 0;
  string s1, s2; cin >> s1 >> s2;
  for (int i = 0; i < s1.size(); ++i) {
    if (s1[i] == s2[i]) cnt1++;
    else cnt2++;
  }
  int ans = min(cnt1, k);
  ans += cnt2 - max(0, (k - cnt1));
  cout << ans << endl;
  return 0;
}

