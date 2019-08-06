#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(int argc, char *argv[]) {
    int n; cin >> n;
    vector<pair<ll, ll> > array;
    for (int i = 0; i < n; ++i) {
        ll up, down; char c;
        cin >> up >> c >> down;
        ll gcd = __gcd(up, down);
        array.push_back(make_pair(up / gcd, down / gcd));
    }
    auto __lcm = [&](ll key1, ll key2) -> ll {
        return key1 * key2 / __gcd(key1, key2);
    };
    pair<ll, ll> ans = array[0];
    array.erase(array.begin());
    auto cal = [&](pair<ll, ll> key) {
        ll lcm = __lcm(ans.second, key.second);
        ans.first = ans.first * lcm / ans.second;
        key.first = key.first * lcm / key.second;
        ans.first += key.first;
        ans.second = lcm;
        ll gcd = __gcd(ans.first, ans.second);
        ans.first /= gcd;
        ans.second /= gcd;
    };
    for (auto &it : array) cal(it);
    if (ans.first % ans.second == 0) cout << ans.first / ans.second << endl;
    else if (ans.first > ans.second) cout << ans.first / ans.second << " " << ans.first % ans.second << "/" << ans.second << endl;
    else cout << ans.first << "/" << ans.second << endl;
    return 0;
}

