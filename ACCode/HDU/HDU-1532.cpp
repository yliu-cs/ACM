#include <bits/stdc++.h>
using namespace std;
#define mem(a,b) memset(a,b,sizeof(a))
#define pb push_back
#define mp make_pair
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> P;
const int INF = 0x3f3f3f3f;
const int maxn = 2e3;
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
int maze[maxn][maxn];

int dfs(int u, int FindFlow) {
    if (u == en) {
        return FindFlow;
    }
    if (vis[u]) {
        return 0;
    }
    vis[u] = 1;
    for (int i = 1; i <= n; ++i) {
        if (maze[u][i]) {
            int LastLineFlow = dfs(i, FindFlow < maze[u][i] ? FindFlow : maze[u][i]);
            if (LastLineFlow == 0) {
                continue;
            }
            maze[u][i] -= LastLineFlow;
            maze[i][u] += LastLineFlow;
            return LastLineFlow;
        }
    }
    return 0;
}

int main(){
    //fre();
    while (~scanf("%d%d", &m, &n)) {
        mem(vis, 0);
        mem(maze, 0);
        st = 1, en = n;
        while (m--) {
            scanf("%d%d%d", &x, &y, &c);
            maze[x][y] += c;
        }
        ans = 0;
        while (flow = dfs(st, INF)) {
            ans += flow;
            mem(vis, 0);
        }
        printf("%d\n", ans);
    }
    return 0;
}
