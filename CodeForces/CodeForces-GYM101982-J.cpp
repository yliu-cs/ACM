#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll inf = 0x3f3f3f3f;

int main() {
  ios::sync_with_stdio(false); cin.tie(0);
  ll n, s; cin >> n >> s;
  vector<ll> arr(n);
  ll Max = -inf;
  for (auto &it : arr) {
    cin >> it;
    Max = max(Max, it);
  }
  cout << (Max * s + 999) / 1000 << endl;
  return 0;
}

