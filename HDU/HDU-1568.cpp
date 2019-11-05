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
const int maxn = 1e3 + 5;
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

// 斐波那契数列通项公式取对数
int main(int argc, char *argv[]) {
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    int f[21];
    mem(f, 0);
    f[1] = 1;
    for (int i = 2; i < 21; ++i) {
        f[i] = f[i - 1] + f[i - 2];
    }
    int n;
    while (~scanf("%d", &n)) {
        if (n < 21) {
            printf("%d\n", f[n]);
            continue;
        }
        double ans = log10(1.0 / sqrt(5.0)) + n * log10((1.0 + sqrt(5.0)) / 2.0);
        ans -= ll(ans);
        ans = pow(10, ans);
        while (ans < 1000) {
            ans *= 10;
        }
        printf("%d\n", int(ans));
    }
#ifndef ONLINE_JUDGE
    fclose(stdin);
    fclose(stdout);
    system("gedit out.txt");
#endif
    return 0;
}
