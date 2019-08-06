#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    ll t; cin >> t;
    for (ll Case = 1; Case <= t; ++Case) {
        ll n; cin >> n;
        pair<ll, ll> ans;
        vector<pair<ll, ll>> p(n);
        map<ll, ll> cnt_x, cnt_y;
        ll best_x = 0, best_y = 0;
        for (auto &it : p) {
            cin >> it.first >> it.second;
            best_x = max(best_x, ++cnt_x[it.first]);
            best_y = max(best_y, ++cnt_y[it.second]);
        }

        if (cnt_x.size() == 1 || cnt_y.size() == 1) {
            cout << "Case " << Case << ": " << n << " " << 1 << endl;
            continue;
        }
        if (best_x == 1 && best_y == 1) {
            cout << "Case " << Case << ": " << 2 << " " << n * (n - 1) / 2 << endl;
            continue;
        }

        ll cnt_x_1 = 0, cnt_x_2 = 0, cnt_y_1 = 0, cnt_y_2 = 0;
        for (auto &it : cnt_x) {
            if (it.second == best_x) cnt_x_1++;
            else if (it.second == best_x - 1) cnt_x_2++;
        }
        for (auto &it : cnt_y) {
            if (it.second == best_y) cnt_y_1++;
            else if (it.second == best_y - 1) cnt_y_2++;
        }

        ll best = best_x + best_y;
        ll cnt_1 = cnt_x_1 * cnt_y_1, cnt_2 = cnt_x_1 * cnt_y_2 + cnt_x_2 * cnt_y_1;
        for (auto &it : p) {
            int cnt = cnt_x[it.first] + cnt_y[it.second];
            if (cnt == best) {
                cnt_1--;
                cnt_2++;
            }
            else if (cnt == best - 1) cnt_2--;
        }

        if (cnt_1 > 0) cout << "Case " << Case << ": " << best << " " << cnt_1 << endl;
        else cout << "Case " << Case << ": " << best - 1 << " " << cnt_2 << endl;
    }
    return 0;
}

