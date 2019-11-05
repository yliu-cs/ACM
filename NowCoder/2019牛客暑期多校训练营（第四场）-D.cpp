#include <bits/stdc++.h>
typedef long long ll;

int t;
ll n;
std::vector<int> site[2];
std::vector<ll> ans;

void Div() {
  for (int i = 62; i >= 0; --i) {
    ll tmp = 1ll << i;
    if (n >= tmp) {
      site[i % 2].push_back(i);
      n -= tmp;
    }
  }
}

int main() {
  scanf("%d", &t);
  for (int cas = 1; cas <= t; ++cas) {
    scanf("%lld", &n);
    site[0].clear(); site[1].clear();
    Div();
    ans.clear();
    if (site[0].empty()) {
      for (int i = 0; i < (int)site[1].size() - 2; ++i) ans.push_back((1ll << site[1][i]) + (1ll << site[1][i + 1]) + (1ll << site[1][i + 2]));
    }
    else if (site[1].empty()) {
      for (int i = 0; i < (int)site[0].size() - 2; ++i) ans.push_back((1ll << site[0][i]) + (1ll << site[0][i + 1]) + (1ll << site[0][i + 2]));
    }
    else {
      for (int i = 0; i < std::min((int)site[0].size(), (int)site[1].size()); ++i) ans.push_back((1ll << site[0][i]) + (1ll << site[1][i]));
      if ((int)site[0].size() > (int)site[1].size()) {
        for (int i = (int)site[1].size(); i < (int)site[0].size(); ++i) ans.push_back((1ll << site[0][i]) + (1ll << site[1][0]));
      }
      else if ((int)site[1].size() > (int)site[0].size()) {
        for (int i = (int)site[0].size(); i < (int)site[1].size(); ++i) ans.push_back((1ll << site[1][i]) + (1ll << site[0][0]));
      }
    }
    printf("%d", (int)ans.size());
    for (ll &v: ans) printf(" %lld", v);
    if (t != cas) printf("\n");
  }
  return 0;
}