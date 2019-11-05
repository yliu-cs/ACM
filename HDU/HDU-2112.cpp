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
const int maxn = 1e5+5;

struct connect {
    int v;
    int time;
};

string sta[150];
int dis[maxn],N,book = 0;
bool vis[maxn];
vector<connect> Adj[maxn];

// 迪杰斯特拉最短路
void Dijkstra(int s) {
    mem(dis, INF);
    mem(vis, 0);
    dis[s] = 0;
    for (int i = 0;i < N;++i) {
        int u = -1,min = INF;
        for (int j = 1;j <= N;++j) {
            if (vis[j] == 0 && dis[j] < min) {
                u = j;
                min = dis[j];
            }
        }
        if (u == -1) {
            return;
        }
        vis[u] = 1;
        for (int j = 0;j < Adj[u].size();++j) {
            int v = Adj[u][j].v;
            if (vis[v] == 0 && dis[u] + Adj[u][j].time < dis[v]) {
                dis[v] = dis[u] + Adj[u][j].time;
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    while (cin >> N) {
        if (N == -1) {
            break;
        }
        book = 0;
        int k = N;
        string st,en;
        cin >> st >> en;
        while (k--) {
            string a,b;
            int num,num1 = -1,num2 = -1;
            cin >> a >> b >> num;
			// 为名称和编号建立映射
            for (int i = 1;i <= book;++i) {
                if (a.compare(sta[i]) == 0) {
                    num1 = i;
                }
                if (b.compare(sta[i]) == 0) {
                    num2 = i;
                }
            }
            if (num1 != -1 && num2 != -1) {
                connect add;
                add.v = num2;
                add.time = num;
                Adj[num1].push_back(add);
                add.v = num1;
                Adj[num2].push_back(add);
            }
            else if (num1 != -1 && num2 == -1) {
                connect add;
                add.v = ++book;
                add.time = num;
                Adj[num1].push_back(add);
                add.v = num1;
                Adj[book].push_back(add);
                sta[book] = b;
            }
            else if (num1 == -1 && num2 != -1) {
                connect add;
                add.v = num2;
                add.time = num;
                Adj[++book].push_back(add);
                add.v = book;
                Adj[num2].push_back(add);
                sta[book] = a;
            }
            else {
                connect add;
                add.v = book + 2;
                add.time = num;
                Adj[book + 1].push_back(add);
                add.v = book + 1;
                Adj[book + 2].push_back(add);
                sta[book + 1] = a;
                sta[book + 2] = b;
                book += 2;
            }
        }
        int start = -1,end = -1;
        for (int i = 1;i <= book;++i) {
            if (st.compare(sta[i]) == 0) {
                start = i;
            }
            if (en.compare(sta[i]) == 0) {
                end = i;
            }
            sta[i] = "";
        }
        Dijkstra(start);
        if (dis[end] == INF || start == -1 || end == -1) {
            cout << -1 << endl;
        }
        else {
            cout << dis[end] << endl;
        }
		// 清空邻接表
        for (int i = 1;i <= N;++i) {
            Adj[i].clear();
        }
    }
    return 0;
}
