#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e8 + 5;
typedef long long ll;

bool isPrime[maxn];
vector<int> prime;

bool _isPrime(ll key) {
    for (ll i = 2; i * i <= key; ++i) {
        if (key % i == 0) return false;
    }
    return true;
}

void _sieve() {
    memset(isPrime, true, sizeof(isPrime));
    for (ll i = 2; i < maxn; ++i) {
        if (isPrime[i]) {
            prime.push_back(i);
            for (ll j = i * i; j < maxn; j += i) isPrime[j] = false;
        }
    }
}

void _solve(ll x) {
    for (auto &p : prime) {
        if (_isPrime(x - p)) {
            cout << p << " " << x - p << endl;
            break;
        }
    }
}

int main() {
    _sieve();
    int t; cin >> t;
    for (int Case = 1; Case <= t; ++Case) {
        ll n; cin >> n;
        cout << "Case " << Case << ": ";
        if (n < 12) {
            cout << "IMPOSSIBLE" << endl;
            continue;
        }
        if (n & 1) {
            cout << 2 << " " << 3 << " " << 2 << " " << 2 << " ";
            n -= 9;
        }
        else {
            cout << 2 << " " << 2 << " " << 2 << " " << 2 << " ";
            n -= 8;
        }
        _solve(n);
    }
    return 0;
}
