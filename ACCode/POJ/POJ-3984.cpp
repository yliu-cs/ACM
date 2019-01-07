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
#include <map>
using namespace std;
#define mem(a,b) memset(a,b,sizeof(a))
#define pb push_back
#define _USE_MATH_DEFINES
typedef long long ll;
typedef pair<int, int> P;
const int INF = 0x3f3f3f3f;
const int maxn = 30;
const double eps = 1e-5;
const double pi = asin(1.0)*2;
const double e = 2.718281828459;

struct ac {
    int i;
    int j;
    int step;
};

int maze[5][5];
bool vis[5][5];
ac path[5][5];
int dx[4] = {1, -1, 0, 0}, dy[4] = {0, 0, 1, -1};
int cnt;
bool flag;

void dfs(int i, int j, int step) {
    if (i == 4 && j == 4) {
        flag = 1;
        cnt = step;
        return;
    }
    else {
        for (int x = 0; x < 4; ++x) {
            int ii = i + dx[x], jj = j + dy[x];
            if (ii >= 0 && ii < 5 && jj >= 0 && jj < 5 && maze[ii][jj] != 1 && !vis[ii][jj]) {
                vis[ii][jj] = 1;
                dfs(ii, jj, step + 1);
                if (flag) {
                    return;
                }
                vis[ii][jj] = 0;
            }
        }
    }
}

void bfs() {
    queue<ac> que;
    ac fi_add;
    fi_add.i = 0;
    fi_add.j = 0;
    fi_add.step = 0;
    que.push(fi_add);
    vis[0][0] = 1;
    while (!que.empty()) {
        ac temp = que.front();
        que.pop();
        if (temp.i == 4 && temp.j == 4) {
            cnt = temp.step;
            return;
        }
        for (int i = 0; i < 4; ++i) {
            int ii = temp.i + dx[i], jj = temp.j + dy[i];
            if (ii >= 0 && ii < 5 && jj >= 0 && jj < 5 && maze[ii][jj] != 1 && !vis[ii][jj]) {
                ac add;
                add.i = ii;
                add.j = jj;
                add.step = temp.step + 1;
                que.push(add);
                path[ii][jj].i = temp.i;
                path[ii][jj].j = temp.j;
                vis[ii][jj] = 1;
            }
        }
    }
}

void find_line(int i, int j) {
    if (i == 0 && j == 0) {
        cout << "(" << i << ", " << j << ")" << endl;
    }
    else {
        find_line(path[i][j].i, path[i][j].j);
        cout << "(" << i << ", " << j << ")" << endl;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    for (int i = 0; i < 5; ++i) {
        for (int j = 0; j < 5; ++j) {
            cin >> maze[i][j];
        }
    }
    cnt = 0;
    bfs();
    find_line(4, 4);
    return 0;
}
