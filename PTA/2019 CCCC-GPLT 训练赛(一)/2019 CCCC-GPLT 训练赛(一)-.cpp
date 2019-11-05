#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    ll n; cin >> n;
    map<ll, int> cnt;
    for (ll i = 0, x; i < n; ++i) {
        cin >> x; cnt[x]++;
        cin >> x; cnt[x]++;
    }
    vector<pair<ll, int>> ans;
    for (auto &it : cnt) ans.push_back(make_pair(it.first, it.second));
    sort(ans.begin(), ans.end(), [&](pair<ll, int> k1, pair<ll, int> k2) {
        if (k1.second == k2.second) return k1.first < k2.first;
        return k1.second > k2.second;
    });
    int ans_cnt = 0;
    for (auto &it : ans)
        if (it.second == ans[0].second) ans_cnt++;
        else break;
    cout << setfill('0') << setw(11) << ans[0].first;
    cout << " ";
    cout << ans[0].second;
    if (ans_cnt > 1) cout << " " << ans_cnt << endl;
    else cout << endl;
    return 0;
}

