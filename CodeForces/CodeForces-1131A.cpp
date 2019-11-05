#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(int argc, char *argv[]) {
    ll w1, h1, w2, h2; cin >> w1 >> h1 >> w2 >> h2;
    ll ans = 0;
    ans += 2 * ((h1 + h2) + 2) + 2 * (max(w1, w2) + 2);
    ans -= 4;
    cout << ans << endl;
    return 0;
}

