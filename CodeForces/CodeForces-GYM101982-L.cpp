#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false); cin.tie(0);
  int n; cin >> n;
  vector<int> diff(n + 1, 0);
  for (int i = 0, l, r; i < n; ++i) {
    cin >> l >> r;
    diff[l]++;
    if (r != n) diff[r + 1]--;
  }
  vector<int> cnt(n + 1, 0);
  cnt[0] = diff[0];
  int ans = -1;
  for (int i = 1; i <= n; ++i) {
    cnt[i] = cnt[i - 1] + diff[i];
    if (cnt[i] == i) ans = i;
  }
  cout << ans << endl;
  return 0;
}

