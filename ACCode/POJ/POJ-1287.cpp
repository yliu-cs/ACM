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

using namespace std;
#define mem(a,b) memset(a,b,sizeof(a))
typedef long long ll;
const int INF = 0x3f3f3f3f;
const int maxn = 110;

struct connect {
    int v;
    int dis;
};

vector<connect> Adj[maxn];
int n,E,dis[maxn];
bool vis[maxn] = {0};
int res = 0;

int Prim() {
    mem(dis, INF);
    mem(vis, 0);
    dis[1] = 0;
    res = 0;
    for (int i = 1;i <= n;++i) {
        int u = -1,min = INF;
        for (int j = 1;j <= n;++j) {
            if (vis[j] == 0 && dis[j] < min) {
                u = j;
                min = dis[j];
            }
        }
        vis[u] = 1;
        res += min;
        for (int j = 0;j < Adj[u].size();++j) {
            int v = Adj[u][j].v;
            if (vis[v] == 0 && Adj[u][j].dis < dis[v]) {
                dis[v] = Adj[u][j].dis;
            }
        }
    }
    return res;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie();
    while (cin >> n,n) {
        cin >> E;
        int Num = E;
        while (Num--) {
            int a,b,cost;
            cin >> a >> b >> cost;
            connect tianjia1,tianjia2;
            tianjia1.v = b;
            tianjia1.dis = cost;
            tianjia2.v = a;
            tianjia2.dis = cost;
            Adj[a].push_back(tianjia1);
            Adj[b].push_back(tianjia2);
        }
        cout << Prim() << endl;
        for (int i = 1;i <= n;++i) {
            Adj[i].clear();
        }
    }
    return 0;
}
