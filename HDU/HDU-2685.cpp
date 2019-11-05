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

// 辗转相处求最大公约数
ll gcd(ll x,ll y) {
    return y ? gcd(y,x % y) : x;
}

// 快速幂计算
ll Quick(ll a,ll b,ll c) {
    ll ans = 1;
    a = a % c;
    while (b != 0) {
        if (b & 1) {
            ans = (ans * a) % c;
        }
        b >>= 1;
        a = (a * a) % c;
    }
    return ans;
}

/*
 * 设a>b,gcd(a,b)=1
 * 那么gcd(a^m-b^m)=a^gcd(m,n)-b^gcd(m,n)
 */
int main() {
    ios::sync_with_stdio(0);
    int t;
    cin >> t;
    while (t--) {
        ll a,m,n,k;
        cin >> a >> m >> n >> k;
        ll S;
        S = Quick(a, gcd(m, n), k);
        if (S > 0) {
            S--;
        }
        else if (S == 0) {
            S = k - 1;
        }
        cout << S << endl;
    }
    return 0;
}
