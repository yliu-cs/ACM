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
const int mod = 2e9 + 7;
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
 
int t;
int n, m;
ll ans;
ll topdif, leftdif;
char garden[maxn][maxn];
 
int main(int argc, char *argv[]) {
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    read(t);
    for (int Case = 1; Case <= t; ++Case) {
        read(n); read(m);
        for (int i = 1; i <= n; ++i) {
            for (int j  = 1; j <= m; ++j) {
                cin >> garden[i][j];
            }
        }  
        topdif = n / 2;
        leftdif = m / 2;
        for (int i = 1; i <= n / 2; ++i) {
            for (int j = 1; j <= m; ++j) {
                if (garden[i][j] != garden[n - i + 1][j] && i < topdif) {
                    topdif = topdif < i ? topdif : i;
                    leftdif = leftdif < j ? leftdif : j;
                }
            }
        }
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= m / 2; ++j) {
                if (garden[i][j] != garden[i][m - j + 1]) {
                    leftdif = leftdif < j ? leftdif : j;
                    topdif = topdif < i ? topdif : i;
                }
            }
        }
        ans = (topdif - 1) * (leftdif - 1);
        cout << ans << endl;
    }
#ifndef ONLINE_JUDGE
    fclose(stdin);
    fclose(stdout);
    system("gedit out.txt");
#endif
    return 0;
}
