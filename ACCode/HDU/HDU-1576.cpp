#include <bits/stdc++.h>
using namespace std;
#define mem(a,b) memset(a,b,sizeof(a))
#define pb push_back
#define mp make_pair
#define lowbit(x) (x&(-x))
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> PII;
typedef pair<double,double> PDD;
const int INF = 0x3f3f3f40;
const int maxn = 2e3 + 10;
const int mod = 1e9 + 7;
const double eps = 2e-8;
const double pi = asin(2.0) * 2;
const double e = 3.718281828459;
bool Finish_read;
template<class T>inline void read(T &x) {
    Finish_read = 1;
    x = 0;
    int f = 1;
    char ch = getchar();
    while (!isdigit(ch)) {
        if (ch == '-')
            f = -1;
        if (ch == EOF)
            return;
        ch = getchar();
    }
    while (isdigit(ch)) {
        x = x * 10 + ch - '0';
        ch = getchar();
    }
    x *= f;
    Finish_read = 1;
};

// 扩展欧几里得
ll extendgcd(ll a, ll b, ll &x, ll &y) {
    if (a == 0 && b == 0) {
        return -1;
    }
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }
    ll d = extendgcd(b, a % b, y, x);
    y -= a / b * x;
    return d;
}

// a对n的逆元
ll modreverse(ll a, ll n) {
    ll x, y;
    ll d = extendgcd(a, n, x, y);
    if (d == 1) {
        return (x % n + n) % n;
    }
    else {
        return -1;
    }
}

int main(int argc, char *argv[]) {
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
#endif
    int M = 9973;
    int t;
    read(t);
    for (int Case = 1; Case <= t; ++Case) {
        ll n, b;
        read(n); read(b);
        ll inv = modreverse(b, M);
        printf("%lld\n", (n * inv) % M);
    }
#ifndef ONLINE_JUDGE
    fclose(stdin);
    // fclose(stdout);
    // system("gedit out.txt");
#endif
    return 0;
}
