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
    double x,y,z,r;
}Inf[maxn];

struct connect {
    double v,dis;
};

vector<connect> Adj[maxn];
int n;
bool vis[maxn] = {0};
double res = 0,dis[maxn];

double Cal(Information A,Information B) {
    double distance = sqrt(pow((A.x - B.x), 2) + pow((A.y - B.y), 2) + pow((A.z - B.z), 2));
    if (A.r + B.r >= distance) {
        distance = 0.0;
    }
    else {
        distance -= A.r + B.r;
    }
    return distance;
}

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
        for (int i = 1;i <= n;++i) {
            cin >> Inf[i].x >> Inf[i].y >> Inf[i].z >> Inf[i].r;
        }
        for (int i = 1;i <= n;++i) {
            for (int j = 1;j <= n;++j) {
                connect add;
                add.v = j;
                add.dis = Cal(Inf[i], Inf[j]);
                Adj[i].push_back(add);
            }
        }
        cout << setiosflags(ios::fixed) << setprecision(3) << Prim() << endl;
        for (int i = 1;i <= n;++i) {
            Adj[i].clear();
        }
    }
    return 0;
}
