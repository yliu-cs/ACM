#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false); cin.tie(0);
  int n; cin >> n;
  vector<int> a(n * 2, 0);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
    a[n + i] = a[i];
  }
  int ans = 0, cnt = 0;
  for (int i = 0; i < 2 * n; ++i) {
    if (a[i] == 1) cnt++;
    else cnt = 0;
    ans = max(ans, cnt);
  }
  cout << ans << endl;
  return 0;
}
