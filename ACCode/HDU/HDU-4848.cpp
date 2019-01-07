
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
const int maxn = 40;
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
int ans;
int cost[maxn][maxn];
int require[maxn];
bool vis[maxn];

// 求任意两点见所需的最短时间
void Floyd() {
    for (int k = 0; k < n; ++k) {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                cost[i][j] = min(cost[i][j], cost[i][k] + cost[k][j]);
            }
        }
    }
}

void dfs(int now, int cnt, int res, int sum) {
    // 若未达到时间要求限制或已经不是最佳结果，剪枝
    if (res > require[now] || sum > ans) {
        return;
    }
    // 记录最佳结果
    if (cnt == n) {
        ans = min(sum, ans);
        return;
    }
    // 若即使由当前点直接到达任意未访问点都无法满足时间要求，剪枝
    for (int i = 1; i < n; ++i) {
        if (!vis[i] && res + cost[now][i] > require[i]) {
            return;
        }
    }
    for (int i = 1; i < n; ++i) {
        if (!vis[i] && res + cost[now][i] <= require[i]) {
            vis[i] = 1;
            dfs(i, cnt + 1, res + cost[now][i], sum + cost[now][i] * (n - cnt));
            vis[i] = 0;
        }
    }
}

int main(int argc, char *argv[]) {
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    while (read(n)) {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                read(cost[i][j]);
            }
        }
        for (int i = 1; i < n; ++i) {
            read(require[i]);
        }
        Floyd();
        mem(vis, 0);
        vis[0] = 1;
        ans = INF;
        dfs(0, 1, 0, 0);
        ans = ans == INF ? -1 : ans;
        print(ans);
    }
#ifndef ONLINE_JUDGE
    fclose(stdin);
    fclose(stdout);
    system("gedit out.txt");
#endif
    return 0;
}
