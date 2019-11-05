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
const int maxn = 40010;
const double eps = 1e-5;

struct connect {
    int v;
    int dis;
};

int T, n, m;
int dis[maxn];
int Startv, Endv;
bool Flag_end;
bool vis[maxn];
vector<connect> Adj[maxn];

// 数据读取
void Get_Information() {
    cin >> n >> m;
    for (int i = 0; i < n - 1; ++i) {
        int Input_first, Input_second, Input_distance;
        cin >> Input_first >> Input_second >> Input_distance;
        connect add;
        add.v = Input_second;
        add.dis = Input_distance;
        Adj[Input_first].push_back(add);
        add.v = Input_first;
        Adj[Input_second].push_back(add);
    }
}

// 深度优先搜索
void Dfs_Road(int now, int sum) {
    if (now == Endv) {
        Flag_end = 1;
        cout << sum << endl;
    }
    else if (Adj[now].empty()) {
        return;
    }
    else {
        for (int i = 0; i < Adj[now].size(); ++i) {
            int v = Adj[now][i].v;
            if (vis[v] == 0) {
                vis[v] = 1;
                Dfs_Road(Adj[now][i].v, sum + Adj[now][i].dis);
                if (Flag_end) {
                    return;
                }
                vis[v] = 0;
            }
        }
    }
}

// 处理询问
void Ask_Output() {
    cin >> Startv >> Endv;
    Flag_end = 0;
    mem(vis, 0);
    vis[Startv] = 1;
    Dfs_Road(Startv, 0);
}

// 清空邻接表
void Clear_List() {
    for (int i = 0; i <= n; ++i) {
        Adj[i].clear();
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> T;
    while (T--) {
        Get_Information();
        while (m--) {
            Ask_Output();
        }
        Clear_List();
    }
    return 0;
}
