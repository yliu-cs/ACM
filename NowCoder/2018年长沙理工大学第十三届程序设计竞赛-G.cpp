#include <bits/stdc++.h>
using namespace std;
#define mem(a,b) memset(a,b,sizeof(a))
typedef long long ll;
typedef pair<int, int> P;
const int INF = 0x3f3f3f3f;
const int maxn = 502;
const double eps = 1e-5;
const double e = 2.718281828459;
 
struct ac {
    int x, y, step;
};
 
int t;
int n, m;
int st_i, st_j;
int key_cnt;
int bfs_key_cnt;
int en_i, en_j;
int ans;
char maze[maxn][maxn];
int dis_p[maxn][maxn];
int dis_e[maxn][maxn];
bool vis[maxn][maxn];
int dx[4] = {1, -1, 0, 0}, dy[4] = {0, 0, 1, -1};
 
void bfs(int x, int y) {
    mem(vis, 0);
    bfs_key_cnt = 0;
    queue<ac> que;
    ac push_;
    push_.x = x;
    push_.y = y;
    push_.step = 0;
    que.push(push_);
    while (!que.empty()) {
        ac keep = que.front();
        que.pop();
        if (maze[keep.x][keep.y] == 'K') {
            if (x == st_i && y == st_j) {
                dis_p[keep.x][keep.y] += keep.step;
            }
            else if (x == en_i && y == en_j) {
                dis_e[keep.x][keep.y] += keep.step;
            }
            bfs_key_cnt++;
            if (bfs_key_cnt == key_cnt) {
                return;
            }
        }
        for (int i = 0; i < 4; ++i) {
            int nx = keep.x + dx[i], ny = keep.y + dy[i];
            if (!vis[nx][ny] && nx > 0 && nx <= n && ny > 0 && ny <= m && maze[nx][ny] != '#' && maze[nx][ny] != 'E') {
                vis[nx][ny] = 1;
                ac _push;
                _push.x = nx;
                _push.y = ny;
                _push.step = keep.step + 1;
                que.push(_push);
            }
        }
    }
}
 
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> t;
    while (t--) {
        mem(dis_p, 0);
        mem(dis_e, 0);
        ans = INF;
        cin >> n >> m;
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= m; ++j) {
                cin >> maze[i][j];
                if (maze[i][j] == 'P') {
                    st_i = i;
                    st_j = j;
                }
                else if (maze[i][j] == 'K') {
                    key_cnt++;
                }
                else if (maze[i][j] == 'E') {
                    en_i = i;
                    en_j = j;
                }
            }
        }
        bfs(st_i, st_j);
        bfs(en_i, en_j);
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= m; ++j) {
                if (dis_p[i][j] + dis_e[i][j] < ans && dis_p[i][j] != 0 && dis_e[i][j] != 0) {
                    ans = dis_p[i][j] + dis_e[i][j];
                }
            }
        }
        if (ans != INF) {
            cout << ans << endl;
        }
        else {
            cout << "No solution" << endl;
        }
    }
    return 0;
}
