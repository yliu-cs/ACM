#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <algorithm>
#include <iomanip>
#include <cctype>
#include <cmath>
#include <stack>
#include <queue>
#include <vector>
#include <cstdlib>
#include <sstream>
#include <set>

using namespace std;
#define mem(a,b) memset(a,b,sizeof(a))
typedef long long ll;
const int INF = 0x3f3f3f3f;
const int maxn = 600;
const double eps = 1e-5;

struct coordinate {
    double x;
    double y;
}eg[maxn];

struct connect {
    double v;
    double dis;
};

int T, s, p;
double dis[maxn];
double edge[maxn];
bool vis[maxn];
vector<connect> Adj[maxn];

bool cmp(int a, int b) {
    return a > b;
}

void Get_Information() {
    cin >> s >> p;
    for (int i = 1; i <= p; ++i) {
        cin >> eg[i].x >> eg[i].y;
    }
}

double Cal_dis(coordinate a, coordinate b) {
    double dx = abs(a.x - b.x);
    double dy = abs(a.y - b.y);
    double temp = sqrt(pow(dx, 2.0) + pow(dy, 2.0));
    return temp;
}

void Deal_data() {
    for (int i = 1; i <= p; ++i) {
        for (int j = 1; j <= p; ++j) {
            if (i < j) {
                double distance = Cal_dis(eg[i], eg[j]);
                connect add;
                add.v = j;
                add.dis = distance;
                Adj[i].push_back(add);
                add.v = i;
                Adj[j].push_back(add);
            }
        }
    }
}

void Prim() {
    for (int i = 0; i < maxn; ++i) {
        dis[i] = INF;
        edge[i] = 0;
    }
    mem(vis, 0);
    dis[1] = 0;
    for (int i = 1; i <= p; ++i) {
        int u = -1;
        double min = INF;
        for (int j = 1; j <= p; ++j) {
            if (!vis[j] && dis[j] < min) {
                u = j;
                min = dis[j];
            }
        }
        vis[u] = 1;
        edge[i - 1] = min;
        for (int j = 0; j < Adj[u].size(); ++j) {
            int v = Adj[u][j].v;
            if (vis[v] == 0 && Adj[u][j].dis < dis[v]) {
                dis[v] = Adj[u][j].dis;
            }
        }
    }
    sort(edge, edge + p);
    cout << setiosflags(ios::fixed) << setprecision(2) << edge[p - s] << endl;
}

void Adj_clear() {
    for (int i = 0; i <= p; ++i) {
        Adj[i].clear();
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> T;
    while (T--) {
        Get_Information();
        Deal_data();
        Prim();
        Adj_clear();
    }
    return 0;
}
