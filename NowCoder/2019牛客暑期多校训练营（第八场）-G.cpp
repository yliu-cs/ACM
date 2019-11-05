#include <bits/stdc++.h>
 
int main() {
  std::ios::sync_with_stdio(false);
  std::cout.tie(0);
  std::cin.tie(0);
  std::string str;
  std::cin >> str;
  int len = str.length();
  std::vector<int> l(len), r(len);
  for (int i = 0; i < len; ++i) {
    l[i] = i - 1;
    r[i] = i + 1;
  }
  bool flag = true;
  int ans = len, low = 0;
  while (flag && ans > 2) {
    flag = false;
    for (int i = low; i < len;) {
      if (r[i] < len && r[r[i]] < len && str[i] == str[r[i]] && str[r[i]] == str[r[r[i]]]) {
        flag = true;
        ans -= 3;
        int ll = l[i], rr = r[r[r[i]]];
        while (rr < len && r[rr] < len && r[r[rr]] < len && str[rr] == str[r[rr]] && str[r[rr]] == str[r[r[rr]]]) {
          ans -= 3;
          rr = r[r[r[rr]]];
        }
        bool f = true;
        while (f && ans > 2) {
          f = false;
          if (ll >= 0 && rr < len && r[rr] < len && str[ll] == str[rr] && str[rr] == str[r[rr]]) {
            ans -= 3;
            f = true;
            ll = l[ll];
            rr = r[r[rr]];
          }
          if (rr < len && ll >= 0 && l[ll] >= 0 && str[rr] == str[ll] && str[ll] == str[l[ll]]) {
            ans -= 3;
            f = true;
            ll = l[l[ll]];
            rr = r[rr];
          }
        }
        if (ll >= 0) r[ll] = rr;
        else low = rr;
        if (rr < len) l[rr] = ll;
        i = rr;
        continue;
      }
      i = r[i];
    }
  }
  std::cout << (len - ans) / 3 << '\n';
  return 0;
}
