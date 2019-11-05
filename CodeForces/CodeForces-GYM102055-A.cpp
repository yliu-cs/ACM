#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    int t; cin >> t;
    for (int Case = 1; Case <= t; ++Case) {
        int n, m; cin >> n >> m;
        vector<pair<ll, ll>> arr(n);
        for (auto &it : arr) cin >> it.first;
        for (auto &it : arr) cin >> it.second;
        sort(arr.begin(), arr.end(), [&](pair<ll, ll> k1, pair<ll, ll> k2) {return k1.first < k2.first;});
        ll sum = 0, ans = 0;
        for (auto &it : arr) {
            if (sum + it.second <= m) {
                sum += it.second;
                ans++;
            }
            else break;
        }
        cout << "Case " << Case << ": " << ans << endl;
    }
    return 0;
}
