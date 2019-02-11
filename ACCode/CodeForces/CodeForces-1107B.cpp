#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(int argc, char *argv[]) {
    ll n; cin >> n;
    for (ll i = 0, k, x; i < n; ++i) {
        cin >> k >> x;
        cout << (k - 1) * 9 + x << endl;
    }
    return 0;
}

