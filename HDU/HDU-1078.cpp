
/*-----------------------------------------------------------*/
/*                     Blog        :henuly.top               */
/*-----------------------------------------------------------*/
#include <bits/stdc++.h>
using namespace std;
#define mem(a,b) memset(a,b,sizeof(a))
#define pb push_back
#define mp make_pair
#define lowbit(x) (x&(-x))
#define XDebug(x) cout<<#x<<"="<<x<<endl;
#define ArrayDebug(x,i) cout<<#x<<"["<<i<<"]="<<x[i]<<endl;
#define print(x) out(x);putchar('\n')
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> PII;
typedef pair<double,double> PDD;
typedef pair<ll,ll> PLL;
const int INF = 0x3f3f3f3f;
const int maxn = 1e2 + 5;
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

int n, k;
int plat[maxn][maxn];
// dp[i][j]记录(i,j)点下的最优解
int dp[maxn][maxn];

int dfs(int x, int y) {
    // 若(x, y)点已搜索过，则dp[x][y]已更新，直接返回此点最优解
    if (dp[x][y]) {
        return dp[x][y];
    }
    dp[x][y] = plat[x][y];
    for (int l = 0; l <= k; ++l) {
        for (int i = -1; i <= 1; ++i) {
            for (int j = -1; j <= 1; ++j) {
                if (abs(i) == abs(j)) {
                    continue;
                }
                int nx = x + (l * i), ny = y + (l * j);
                if (nx >= 0 && nx < n && ny >= 0 && ny < n && plat[x][y] < plat[nx][ny]) {
                    dp[x][y] = max(dp[x][y], plat[x][y] + dfs(nx, ny));
                }
            }
        }
    }
    return dp[x][y];
}

int main(int argc, char *argv[]) {
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    while (read(n) && read(k)) {
        if (n == -1 && k == -1) {
            break;
        }
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                read(plat[i][j]);
            }
        }
        mem(dp, 0);
        // 输出(0,0)点出发的最优解
        print(dfs(0, 0));
    }
#ifndef ONLINE_JUDGE
    fclose(stdin);
    fclose(stdout);
    system("gedit out.txt");
#endif
    return 0;
}
