
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
const int maxn = 10;
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

int T;
int n, m;
int StartX, StartY;
int EndX, EndY;
int ans;
int plat[maxn][maxn];
int step[maxn][maxn];
int Time[maxn][maxn];

void dfs(int x, int y, int cnt, int time) {
    // 时间耗完返回；当前步数已经大于记录结果，剪枝
    if (time == 0 || cnt >= ans) {
        return;
    }
    // 记录结果
    if (x == EndX && y == EndY) {
        ans = min(ans, cnt);
        return;
    }
    // 重置
    if (plat[x][y] == 4) {
        time = 6;
    }
    // 若利用过更少的步数到达此点或者有过到达过此点时拥有的时间更长，剪枝
    if (step[x][y] <= cnt && time <= Time[x][y]) {
        return;
    }
    // 记录到达此点的步数和拥有时间
    step[x][y] = cnt;
    Time[x][y] = time;
    for (int i = -1; i <= 1; ++i) {
        for (int j = -1; j <= 1; ++j) {
            if (abs(i) == abs(j)) {
                continue;
            }
            int nx = x + i, ny = y + j;
            if (nx >= 0 && nx < n && ny >= 0 && ny < m && plat[nx][ny] != 0) {
                dfs(nx, ny, cnt + 1, time - 1);
            }
        }
    }
}

int main(int argc, char *argv[]) {
#ifndef ONLINE_JUDGE
   freopen("in.txt", "r", stdin);
   freopen("out.txt", "w", stdout);
#endif
    read(T);
    for (int Case = 1; Case <= T; ++Case) {
        read(n); read(m);
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                step[i][j] = INF;
                Time[i][j] = 0;
                read(plat[i][j]);
                if (plat[i][j] == 2) {
                    StartX = i;
                    StartY = j;
                }
                else if (plat[i][j] == 3) {
                    EndX = i;
                    EndY = j;
                }
            }
        }
        ans = INF;
        step[StartX][StartY] = 0;
        dfs(StartX, StartY, 0, 6);
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
