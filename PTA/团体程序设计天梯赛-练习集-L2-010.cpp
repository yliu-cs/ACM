#include <iostream>
#include <string>
#include <iomanip>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;
const int maxn = 110;
const int INF = 0x3f3f3f3f;

int maze[maxn][maxn];
int n, m, k;
int pre[maxn];

int find(int x) {
    int r = x;
    while (r != pre[r]) {
        r = pre[r];
    }
    return r;
}

void join(int x, int y) {
    int xx = find(x);
    int yy = find(y);
    if (xx != yy) {
        pre[xx] = yy;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    memset(maze, 0, sizeof(maze));
    cin >> n >> m >> k;
    for (int i = 1; i <= n; ++i) {
        pre[i] = i;
    }
    while (m--) {
        int a, b, c;
        cin >> a >> b >> c;
        if (c == 1) {
            if (find(a) != find(b)) {
                join(a, b);
            }
        }
        else {
            maze[a][b] = c;
            maze[b][a] = c;
        }
    }
    while (k--) {
        int a, b;
        cin >> a >> b;
        if (find(a) == find(b) && maze[a][b] == 0) {
            cout << "No problem" << endl;
        }
        else if (find(a) != find(b) && maze[a][b] == 0) {
            cout << "OK" << endl;
        }
        else if (maze[a][b] == -1 && find(a) == find(b)) {
            cout << "OK but..." << endl;
        }
        else if (maze[a][b] == -1) {
            cout << "No way" << endl;
        }
    }
    return 0;
}
