#include <stdio.h>
#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>
#include <iomanip>
#include <cctype>
#include <cmath>
#include <stack>
#include <queue>
#include <vector>

using namespace std;
#define mem(a,b) memset(a,b,sizeof(a))
typedef long long ll;
const int INF = 0x3f3f3f3f;
const int maxn = 1e5+5;

struct Information {
    int x,y;
}Inf[maxn];

struct connect {
    int v;
    double dis;
};

vector<connect> Adj[maxn];
int n;
bool vis[maxn] = {0};
double res = 0,dis[maxn];

// 距离计算
double Cal(Information A,Information B) {
    double distance = sqrt(pow((A.x - B.x), 2) + pow((A.y - B.y), 2));
    return distance;
}

// Prim求最小生成树
double Prim() {
    for (int i = 0;i < maxn;++i) {
        dis[i] = INF;
    }
    mem(vis, 0);
    dis[1] = 0;
    res = 0;
    for (int i = 1;i <= n;++i) {
        int u = -1;
        double min = INF;
        for (int j = 1;j <= n;++j) {
            if (vis[j] == 0 && dis[j] < min) {
                u = j;
                min = dis[j];
            }
            if (vis[j] == 0 && dis[j] < min) {
                u = j;
                min = dis[j];
            }
        }
        if (u == -1) {
            return -1;
        }
        vis[u] = 1;
        res += min;
        for (int j = 0;j < Adj[u].size();++j) {
            int v = Adj[u][j].v;
            if (vis[v] == 0 && Adj[u][j].dis < dis[v] && Adj[u][j].dis >= 10 && Adj[u][j].dis <= 1000) {
                dis[v] = Adj[u][j].dis;
            }
        }
    }
    for (int i = 1;i <= n;++i){
        if (vis[i] == 0) {
            return -1;
        }
    }
    return res;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie();
    int t;
    cin >> t;
    while (t--) {
        cin >> n;
        for (int i = 1;i <= n;++i) {
            cin >> Inf[i].x >> Inf[i].y;
        }
        for (int i = 1;i <= n;++i) {
            for (int j = 1;j <= n;++j) {
                connect add;
                add.v = j;
                add.dis = Cal(Inf[i], Inf[j]);
                Adj[i].push_back(add);
            }
        }
        if (Prim() == -1) {
            cout << "oh!" << endl;
        }
        else {
            cout << setiosflags(ios::fixed) << setprecision(1) << 100 * Prim() << endl;
        }
		// 清空邻接表
        for (int i = 1;i <= n;++i) {
            Adj[i].clear();
        }
    }
    return 0;
}
