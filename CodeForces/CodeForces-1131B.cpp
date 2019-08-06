#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(int argc, char *argv[]) {
    int n; cin >> n;
    vector<pair<ll, ll>> p(n);
    for (auto &it : p) cin >> it.first >> it.second;
    ll ans = min(p[0].first, p[0].second) + 1;
    cerr << ans << endl;
    pair<ll, ll> cur = p[0];
    for (int i = 1; i < n; ++i) {
        if (p[i] == cur) continue;
        if (cur.first < cur.second) {
            if (p[i].first >= cur.second) {
                ans += min(p[i].first, p[i].second) - cur.second + 1;
            }
        }
        else if (cur.second < cur.first) {
            if (p[i].second >= cur.first) {
                ans += min(p[i].first, p[i].second) - cur.first + 1;
            }
        }
        else if (cur.first == cur.second) {
            ans += min(p[i].first, p[i].second) - cur.first;
        }
        cur = p[i];
        cerr << ans << endl;
    }
    cout << ans << endl;
    return 0;
}

