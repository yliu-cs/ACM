#include <iostream>
#include <string>
#include <iomanip>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;
const int maxn = 10010;
const int INF = 0x3f3f3f3f;

int n, m, k;
int cnt, res;
bool vis[maxn];
bool book = 0;
int min_dis[maxn];
vector<int> adj[maxn];

void dfs(int st, int step) {
    for (int i = 0; i < adj[st].size(); ++i) {
        if (!vis[adj[st][i]]) {
            book = 1;
            vis[adj[st][i]] = 1;
            if (min_dis[adj[st][i]] == 0 || step + 1 < min_dis[adj[st][i]]) {
                min_dis[adj[st][i]] = step + 1;
            }
            dfs(adj[st][i], step + 1);
            vis[adj[st][i]] = 0;
        }
    }
    return;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m >> k;
    while (m--) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    while (k--) {
        book = 0;
        int ask;
        cin >> ask;
        res = 0; cnt = 0;
        memset(vis, 0, sizeof(vis));
        memset(min_dis, 0, sizeof(min_dis));
        vis[ask] = 1;
        dfs(ask, 0);
        int temp = 0, res_;
        for (int i = 1; i <= n; ++i) {
            if (min_dis[i] > temp) {
                temp = min_dis[i];
                res_ = i;
            }
        }
        if (book) {
            cout << res_ << endl;
        }
        else {
            cout << 0 << endl;
        }
    }
    return 0;
}
