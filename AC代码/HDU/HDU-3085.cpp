
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
const int maxn = 8e2 + 5;
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

struct Pos {
    int x, y;
    Pos(int _x = 0, int _y = 0): x(_x), y(_y) {}
};

int T;
int n, m;
int step;
int ans;
int GhostsCnt;
int direction[4][2] = {
    {1, 0},
    {-1, 0},
    {0, 1},
    {0, -1}
};
char plat[maxn][maxn];
Pos Erriyue, GirlFriend, Ghosts[2];
queue<Pos> que[2];

bool judge(Pos x) {
    // 是否是墙壁
    if (plat[x.x][x.y] == 'X') {
        return 0;
    }
    // 是否在地图内
    if (x.x < 0 || x.x >= n || x.y < 0 || x.y >= m) {
        return 0;
    }
    // 曼哈顿距离
    for (int i = 0; i < 2; ++i) {
        if ((abs(Ghosts[i].x - x.x) + abs(Ghosts[i].y - x.y)) <= 2 * step) {
            return 0;
        }
    }
    return 1;
}

bool bfs(int Who, char Mark, char Meet) {
    queue<Pos> keep = que[Who];
    int pace = Who ? 1 : 3;
    for (int i = 0; i < pace; ++i) {
        while (!keep.empty()) {
            Pos temp = keep.front();
            keep.pop();
            que[Who].pop();
            // 鬼先走，判断曼哈顿距离
            if (!judge(temp)) {
                continue;
            }
            for (int j = 0; j < 4; ++j) {
                Pos tmp = temp;
                tmp.x += direction[j][0];
                tmp.y += direction[j][1];
                // 已走过或不可走
                if (!judge(tmp) || plat[tmp.x][tmp.y] == Mark) {
                    continue;
                }
                // 另外一个人走过此点
                if (plat[tmp.x][tmp.y] == Meet) {
                    return 1;
                }
                plat[tmp.x][tmp.y] = Mark;
                que[Who].push(tmp);
            }
        }
        keep = que[Who];
    }
    return 0;
}

int main(int argc, char *argv[]) {
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    read(T);
    for (int Case = 1; Case <= T; ++Case) {
        mem(plat, 'X');
        read(n); read(m);
        GhostsCnt = 0;
        for (int i = 0; i < n; ++i) {
            scanf("%s", plat[i]);
            for (int j = 0; j < m; ++j) {
                if (plat[i][j] == 'M') {
                    Erriyue.x = i;
                    Erriyue.y = j;
                }
                else if (plat[i][j] == 'G') {
                    GirlFriend.x = i;
                    GirlFriend.y = j;
                }
                else if (plat[i][j] == 'Z') {
                    Ghosts[GhostsCnt].x = i;
                    Ghosts[GhostsCnt++].y = j;
                }
            }
        }
        while (!que[0].empty()) {
            que[0].pop();
        }
        while (!que[1].empty()) {
            que[1].pop();
        }
        que[0].push(Erriyue);
        que[1].push(GirlFriend);
        step = 0;
        ans = -1;
        while (!que[0].empty() && !que[1].empty()) {
            step++;
            if (bfs(0, 'M', 'G') || bfs(1, 'G', 'M')) {
                ans = step;
                break;
            }
        }
        print(ans);
    }
#ifndef ONLINE_JUDGE
    fclose(stdin);
    fclose(stdout);
    system("gedit out.txt");
#endif
    return 0;
}
