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
typedef pair<ll,ll> PLL;
const int INF = 0x3f3f3f3f;
const int maxn = 4e6 + 5;
const int mod = 1e9 + 7;
const double eps = 1e-8;
const double pi = asin(1.0) * 2;
const double e = 2.718281828459;
bool Finish_read;
template<class T>inline void read(T &x) {
    Finish_read = 0;
    x = 0;
    int f = 1;
    char ch = getchar();
    while (!isdigit(ch)) {
        if (ch == '-') {
            f = -1;
        }
        if (ch == EOF) {
            return;
        }
        ch = getchar();
    }
    while (isdigit(ch)) {
        x = x * 10 + ch - '0';
        ch = getchar();
    }
    x *= f;
    Finish_read = 1;
};

// 快速乘
ll QuickMul(ll a, ll b, ll p) {
    ll res = 0;
    while (b) {
        if (b & 1) {
            res = (res + a) % p;
        }
        a = (a + a) % p;
        b >>= 1;
    }
    return res;
}

// 快速幂
ll QuickPow(ll a, ll b, ll p) {
    ll res = 1;
    while (b) {
        if (b & 1) {
            res = QuickMul(res, a, p) % p;
        }
        a = QuickMul(a, a, p) % p;
        b >>= 1;
    }
    return res;
}

int main(int argc, char *argv[]) {
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    ll n, p;
    while (~scanf("%lld %lld", &n, &p)) {
        if (n == 1) {
            if (p > 1) {
                printf("1\n");
            }
            else {
                printf("0\n");
            }
        }
        else {
            ll ans = QuickPow(2, n, p) - 2;
            while (ans < 0) {
                ans += p;
            }
            printf("%lld\n", ans);
        }
    }
#ifndef ONLINE_JUDGE
    fclose(stdin);
    fclose(stdout);
    system("gedit out.txt");
#endif
    return 0;
}
