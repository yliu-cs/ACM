#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false); cin.tie(0);
  int n; cin >> n;
  map<int, int> mp;
  for (int i = 0, k; i < n; ++i) {
    cin >> k;
    for (int j = 0, id; j < k; ++j) {
      cin >> id;
      ++mp[id];
    }
  }
  vector<pair<int, int>> arr(mp.begin(), mp.end());
  sort(arr.begin(), arr.end(), [&](pair<int, int> k1, pair<int, int> k2) {
      if (k1.second == k2.second) return k1.first > k2.first;
      return k1.second > k2.second;
  });
  cout << arr[0].first << " " << arr[0].second;
  return 0;
}

