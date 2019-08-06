#include <bits/stdc++.h>
using namespace std;
const int inf = 0x3f3f3f3f;

int main() {
  ios::sync_with_stdio(false); cin.tie(0);
  int n; cin >> n;
  vector<int> arr(n + 1);
  for (int i = 1; i <= n; ++i) cin >> arr[i];
  vector<long long> prefix(n + 1, 0);
  for (int i = 1; i <= n; ++i) prefix[i] = prefix[i - 1] + arr[i];
  long long ans = -inf;
  for (int i = 1; i <= n; ++i)
    for (int j = i + 1; j <= n; ++j)
      ans = max(ans, prefix[j] - prefix[i - 1]);
  cout << max(1ll * 0, ans) << endl;
  return 0;
}

