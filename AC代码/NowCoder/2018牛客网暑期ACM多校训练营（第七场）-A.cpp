#include <bits/stdc++.h>
using namespace std;
#define mem(a,b) memset(a,b,sizeof(a))
#define pb push_back
#define mp make_pair
#define lowbit(x) (x&(-x))
#define XDebug(x) cout << #x << "=" << x << endl;
#define ArrayDebug(x,i) cout << #x << "[" << i << "]=" << x[i] << endl;
#define print(x) out(x);putchar('\n');
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
template <class T>
inline bool read(T &ret) {
    char c;
    int sgn;
    if (c = getchar(), c == EOF) {
        return 0;
    }
    while (c != '-' && (c < '0' || c > '9')) {
        c = getchar();
    }
    sgn = (c == '-') ? -1 : 1;
    ret = (c == '-') ? 0 : (c - '0');
    while (c = getchar(), c >= '0' && c <= '9') {
        ret = ret * 10 + (c - '0');
    }
    ret *= sgn;
    return 1;
}
template <class T>
inline void out(T x) {
    if (x < 0) {
        putchar('-');
        x = -x;
    }
    if (x > 9) {
        out(x / 10);
    }
    putchar(x % 10 + '0');
}
 
int main(int argc, char *argv[]) {
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    int n;
    while (read(n)) {
        vector<bool> vis(n, 0);
        vector<int> ans(n, -1);
        for (int i = n - 1; i >= 0; --i) {
            if (vis[i]) {
                continue;
            }
            bitset<20> sys = i;
            int len = log2(i) + 1;
            for (int j = 0; j < len; ++j) {
                sys[j] = sys[j] == 1 ? 0 : 1;
            }
            int temp = int(sys.to_ulong());
            if (temp < n && temp >= 0 && !vis[temp]) {
                ans[i] = temp;
                ans[temp] = i;
                vis[i] = vis[temp] = 1;
            }
        }
        for (int i = 0; i < n; ++i) {
            out(ans[i]);
            if (i != n - 1) {
                putchar(' ');
            }
        }
        putchar('\n');
    }
#ifndef ONLINE_JUDGE
    fclose(stdin);
    fclose(stdout);
    system("gedit out.txt");
#endif
    return 0;
}
