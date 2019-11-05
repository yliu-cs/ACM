#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false); cin.tie(0);
  long long h, n; cin >> h >> n;
  vector<long long> d(n);
  long long cur = h, sum = 0, book = 0;
  for (int i = 0; i < n; ++i) {
    cin >> d[i];
    cur += d[i];
    sum += d[i];
    if (cur <= 0) {
      book = i + 1;
      break;
    }
  }
  if (book) {
    cout << book << endl;
    return 0;
  }
  else if (sum >= 0) {
    cout << -1 << endl;
    return 0;
  }
  long long ans = 1e18 + 5;
  for (int i = 0; i < n; ++i) {
    cur += d[i];
    long long cnt = (cur / (-sum)) * n;
    if (cur + (cnt / n) * sum <= 0) ans = min(ans, n + cnt + i + 1);
    else if (cur + ((cnt / n) + 1) * sum <= 0) ans = min(ans, n + cnt + n + i + 1);
  }
  cout << ans << endl;
  return 0;
}
