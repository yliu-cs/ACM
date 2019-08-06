
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

int T;
int N, M, K;
bool finish;
int num[maxn << 1];
int plat[maxn][maxn];

bool check(int x, int y, int color) {
    if (x > 0 && plat[x - 1][y] == color) {
        return 0;
    }
    if (y > 0 && plat[x][y - 1] == color) {
        return 0;
    }
    return 1;
}

void dfs(int x, int y) {
    // 若剩下的点的二分之一小于任一颜色的数量（一定有两个相邻的方格被染成同一种颜色），剪枝
    for (int i = 1; i <= K; ++i) {
        int cnt = (N - x - 1) * M + (M - y);
        if ((cnt + 1) / 2 < num[i]) {
            return;
        }
    }
    for (int i = 1; i <= K; ++i) {
        if (num[i]) {
            if (check(x, y, i)) {
                plat[x][y] = i;
                if (x == N - 1 && y == M - 1) {
                    finish = 1;
                    return;
                }
                num[i]--;
                dfs(y == M - 1 ? x + 1 : x, y == M - 1 ? 0 : y + 1);
                if (finish) {
                    return;
                }
                num[i]++;
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
        read(N); read(M); read(K);
        for (int i = 1; i <= K; ++i) {
            read(num[i]);
        }
        mem(plat, 0);
        finish = 0;
        dfs(0, 0);
        printf("Case #%d:\n", Case);
        if (finish) {
            printf("YES\n");
            for (int i = 0; i < N; ++i) {
                for (int j = 0; j < M; ++j) {
                    printf("%d", plat[i][j]);
                    // 此题行末无空格！！！
                    if (j != M - 1) {
                        printf(" ");
                    }
                }
                printf("\n");
            }
        }
        else {
            printf("NO\n");
        }
    }
#ifndef ONLINE_JUDGE
    fclose(stdin);
    fclose(stdout);
    system("gedit out.txt");
#endif
    return 0;
}
