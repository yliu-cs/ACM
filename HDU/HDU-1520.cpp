
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
const int maxn = 6e3 + 5;
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

int n;
int u, v;
int Root;
int HappyVal[maxn];
int f[maxn];
int dp[maxn][2];
vector<int> Adj[maxn];

/*
 * dp[u][0/1]表示u子树内的最佳答案,由叶子节点向根节点递推
 * dp[u][0]代表选择u节点,dp[u][1]代表不选择u节点
 * 初始化dp[u][0]=0,dp[u][1]=HappyVal[u]
 * 状态转移方程:
 * 1.当u不选的时候:u的子节点可以选或者不选,所以dp[u][0] += max(dp[v][0], dp[v][1])
 * 2.当u选的时候:u的子节点必定不能选,所以dp[u][1] += dp[v][0]
 */

void dfs(int root) {
    dp[root][1] = HappyVal[root];
    for (int i = 0; i < int(Adj[root].size()); ++i) {
        dfs(Adj[root][i]);
    }
    for (int i = 0; i < int(Adj[root].size()); ++i) {
        dp[root][0] += max(dp[Adj[root][i]][1], dp[Adj[root][i]][0]);
        dp[root][1] += dp[Adj[root][i]][0];
    }
}

int main(int argc, char *argv[]) {
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    while (read(n)) {
        for (int i = 1; i <= n; ++i) {
            Adj[i].clear();
            read(HappyVal[i]);
            f[i] = -1;
            dp[i][0] = dp[i][1] = 0;
        }
        while (read(v) && read(u) && (v + u)) {
            Adj[u].pb(v);
            f[v] = u;
        }
        // 找树根
        Root = 1;
        while (f[Root] != -1) {
            Root = f[Root];
        }
        dfs(Root);
        print(max(dp[Root][0], dp[Root][1]));
    }
#ifndef ONLINE_JUDGE
    fclose(stdin);
    fclose(stdout);
    system("gedit out.txt");
#endif
    return 0;
}
