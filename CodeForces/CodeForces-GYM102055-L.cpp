#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e3 + 5;
typedef long long ll;

bool is_prime[maxn];
vector<int> prime;

bool IsPrime(ll key) {
    for (ll i = 2; i * i <= key; ++i) {
        if (key % i == 0) return false;
    }
    return true;
}

void Sieve() {
    memset(is_prime, true, sizeof(is_prime));
    for (ll i = 2; i < maxn; ++i) {
        if (is_prime[i]) {
            prime.push_back(i);
            for (ll j = i * i; j < maxn; j += i) is_prime[j] = false;
        }
    }
}

void Solve(ll x) {
    for (auto &p : prime) {
        if (IsPrime(x - p)) {
            cout << p << " " << x - p << endl;
            break;
        }
    }
}

int main() {
    Sieve();
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
        Solve(n);
    }
    return 0;
}
