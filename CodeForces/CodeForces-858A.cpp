#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>
#include <iomanip>
#include <cctype>
#include <cmath>

using namespace std;
#define mem(a,b) memset(a,b,sizeof(a))
typedef long long ll;

ll gcd(ll x,ll y) {
    return y ? gcd(y,x % y) : x;
}

ll Mul(ll x) {
    ll res = 1;
    for (int i = 0;i < x;++i) {
        res *= 10;
    }
    return res;
}

int main() {
    ios::sync_with_stdio(0);
    ll n,k;
    cin >> n >> k;
    cout << n * Mul(k) / gcd(n, Mul(k));
    return 0;
}