#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false); cin.tie(0);
  struct f {
    string na;
    long long bir;
    string num;
  };
  int n; cin >> n;
  vector<f> p(n);
  for (auto &it : p) cin >> it.na >> it.bir >> it.num;
  sort(p.begin(), p.end(), [&](f k1, f k2) {return k1.bir < k2.bir;});
  for (auto &it : p) cout << it.na << " " << it.bir << " " << it.num << endl;
  return 0;
}

