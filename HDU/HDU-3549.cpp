#include <bits/stdc++.h>
using namespace std;
#define mem(a,b) memset(a,b,sizeof(a))
#define pb push_back
#define mp make_pair
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> P;
const int INF = 0x3f3f3f3f;
const int maxn = 20;
const int mod = 1e9+7;
const double eps = 1e-8;
const double pi = asin(1.0)*2;
const double e = 2.718281828459;
void fre() {
    freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
}

int t;
int n, m;
int x, y, c;
int st, en;
int flow;
int ans;
bool vis[maxn];
// 残留网
int maze[maxn][maxn];

// Ford-Fulkerson求最大流
int dfs(int u, int low) {
    if (u == en) {
        return low;
    }
    if (vis[u]) {
        return 0;
    }
    vis[u] = 1;
    for (int i = 1; i <= n; ++i) {
        if (maze[u][i]) {
            int Flow = dfs(i, low < maze[u][i] ? low : maze[u][i]);
            if (Flow == 0) {
                continue;
            }
            maze[u][i] -= Flow;
            maze[i][u] += Flow;
            return Flow;
        }
    }
    return 0;
}

int main(){
    //fre();
    scanf("%d", &t);
    for (int Case = 1; Case <= t; ++Case) {
        mem(vis, 0);
        mem(maze, 0);
        scanf("%d%d", &n, &m);
        st = 1, en = n;
        while (m--) {
            scanf("%d%d%d", &x, &y, &c);
            // 有重边所以写为+=
            maze[x][y] += c;
        }
        ans = 0;
        while (flow = dfs(st, INF)) {
            ans += flow;
            mem(vis, 0);
        }
        printf("Case %d: %d\n", Case, ans);
    }
    return 0;
}
