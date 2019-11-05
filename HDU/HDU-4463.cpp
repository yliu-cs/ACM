#include <bits/stdc++.h>
using namespace std;
#define mem(a,b) memset(a,b,sizeof(a))
#define pb push_back
#define mp make_pair
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> P;
const int INF = 0x3f3f3f3f;
const int maxn = 110;
const int mod = 1e9+7;
const double eps = 1e-8;
const double pi = asin(1.0)*2;
const double e = 2.718281828459;
void fre() {
    freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
}

/*
 * 给出一些点的坐标
 * 求最小生成树
 * 其中指定两个点必须直接相连
 * 
 * 在计算点与点之间边的权值时将两个指定点之间边的权值设置为0
 * 这样就可以把两个点看为一个点
 * 这时再用Prim算法从其中一个点开始求最小生成树
 * 把所有最小生成树中的权值求和
 * 再加上两个指定点之间的距离即为答案
 */

struct locate {
    double x, y;
};

int n;
int p, q;
double NADis;
double ans;
locate co[maxn];
double dis[maxn];
bool vis[maxn];
double maze[maxn][maxn];

// Prim求最小生成树
void Prim() {
    for (int i = 0; i < maxn; ++i) {
        dis[i] = INF;
    }
    mem(vis, 0);
    dis[p] = 0;
    ans = 0;
    for (int i = 1; i <= n; ++i) {
        int u = -1;
        double min = INF;
        for (int j = 1; j <= n; ++j) {
            if (!vis[j] && dis[j] < min) {
                u = j;
                min = dis[j];
            }
        }
        vis[u] = 1;
        ans += min;
        for (int j = 1; j <= n; ++j) {
            if (maze[u][j] != INF) {
                if (!vis[j] && maze[u][j] < dis[j]) {
                    dis[j] = maze[u][j];
                }
            }
        }
    }
}

int main() {
    //fre();
    while (scanf("%d", &n)) {
        if (!n) {
            break;
        }
        scanf("%d%d", &p, &q);
        for (int i = 1; i <= n; ++i) {
            scanf("%lf%lf", &co[i].x, &co[i].y);
        }
        if (p > q) {
            int temp = q;
            q = p;
            p = temp;
        }
        for (int i = 0; i < maxn; ++i) {
            for (int j = 0; j < maxn; ++j) {
                maze[i][j] = INF;
            }
        }
        for (int i = 1; i <= n; ++i) {
            for (int j = i + 1; j <= n; ++j) {
                maze[i][j] = maze[j][i] = sqrt((co[i].x - co[j].x) * (co[i].x - co[j].x) + (co[i].y - co[j].y) * (co[i].y - co[j].y));
            }
        }
        maze[p][q] = maze[q][p] = 0;
        Prim();
        NADis = sqrt((co[p].x - co[q].x) * (co[p].x - co[q].x) + (co[p].y - co[q].y) * (co[p].y - co[q].y));
        printf("%.2lf\n", ans + NADis);
    }
    return 0;
}
