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

struct connect {
    int v;
    int dis;
};

vector<connect> Adj[maxn];
int n,dis[maxn],m;
bool vis[maxn] = {0};
int res = 0;
bool flag = 0;

void Prim (int x) {
    mem(dis, -1);
    dis[x] = 0;
    for (int i = 0;i < n;++i) {
        int u = -1,max = -1;
        for (int j = 1;j <= n;++j) {
            if (vis[j] == 0 && dis[j] > max) {
                u = j;
                max = dis[j];
            }
        }
        vis[u] = 1;
        res += max;
        for (int j = 0;j < Adj[u].size();++j) {
            int v = Adj[u][j].v;
            if (vis[v] == 0 && Adj[u][j].dis > dis[v]) {
                dis[v] = Adj[u][j].dis;
            }
        }
    }
    for (int i = 1;i <= n;++i) {
        if (vis[i] == 0) {
            flag = 1;
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for (int i = 0;i < m;++i) {
        int a,b,c;
        cin >> a >> b >> c;
        for (int j = 0;j < Adj[a].size();++j) {
            if (Adj[a][j].v == b) {
                if (Adj[a][j].dis < c) {
                    Adj[a][j].dis = c;
                    for (int k = 0;k < Adj[b].size();++k) {
                        if (Adj[b][k].v == a) {
                            Adj[b][k].dis = c;
                            goto emm;
                        }
                    }
                }
            }
        }
        connect add;
        add.v = b;
        add.dis = c;
        Adj[a].push_back(add);
        add.v = a;
        Adj[b].push_back(add);
    emm:;
    }
    Prim(1);
    if (flag) {
        cout << -1 << endl;
    }
    else {
        cout << res << endl;
    }
    return 0;
}
