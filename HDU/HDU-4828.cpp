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
const int maxn = 1e6 + 5;
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

int main(int argc, char *argv[]) {
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
	// 逆元
    ll *inv = new ll[maxn];
    inv[1] = 1;
    for (int i = 2; i < maxn; ++i) {
        inv[i] = (mod - mod / i) * inv[mod % i] % mod;
    }
	// 卡特兰数列
    ll *Catalan = new ll[maxn];
    Catalan[1] = 1;
    for (int i = 2; i < maxn - 1; ++i) {
        Catalan[i] = Catalan[i - 1] * (4 * i - 2) % mod * inv[i + 1] % mod;
    }
    ll T;
    read(T);
    for (ll Case = 1, n; Case <= T; ++Case) {
        read(n);
        printf("Case #%lld:\n", Case);
        printf("%lld\n", Catalan[n]);
    }
#ifndef ONLINE_JUDGE
    fclose(stdin);
    fclose(stdout);
    system("gedit out.txt");
#endif
    return 0;
}
