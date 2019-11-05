#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(int argc, char *argv[]) {
    int n, k; cin >> n >> k;
    vector<pair<int, char> > a(n);
    for (int i = 0; i < n; ++i) cin >> a[i].first;
    for (int i = 0; i < n; ++i) cin >> a[i].second;
    vector<pair<int, int> > seg;
    for (int l = 0, r = 0; l < n; l = r) {
        while (r < n && a[r].second == a[l].second) r++;
        seg.push_back(make_pair(l, r));
    }
    ll ans = 0;
    for (auto it : seg) {
        sort(a.begin() + it.first, a.begin() + it.second);
        reverse(a.begin() + it.first, a.begin() + it.second);
        for (int i = it.first; i < min(it.second, it.first + k); ++i) ans += a[i].first;
    }
    cout << ans << endl;
    return 0;
}

