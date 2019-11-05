#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(int argc, char *argv[]) {
    string s; cin >> s;
    if (s[0] == '-') s.erase(s.begin());
    ll ans = 0;
    for (auto &it : s) ans += (it - '0') * (it - '0');
    cout << "sum=" << ans << endl;
    return 0;
}

