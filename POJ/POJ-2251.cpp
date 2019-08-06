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
#define maxn 32

const int INF = 100000000;
char maze[maxn][maxn][maxn];
int L,R,C;
int sx,sy,sz;
int gx,gy,gz;
int d[maxn][maxn][maxn];
int dx[6] = {1,-1,0,0,0,0}, dy[6] = {0,0,0,0,1,-1}, dz[6] = {0,0,1,-1,0,0};

struct weizhi {
    int a;
    int b;
    int c;
};

void bfs() {
    queue<weizhi> que;
    for (int i = 1;i <= L;++i) {
        for (int j = 1;j <= R;++j) {
            for (int k = 1;k <= C;++k) {
                d[i][j][k] = INF;
            }
        }
    }
    weizhi q;
    q.a = sz,q.b = sx,q.c = sy;
    que.push(q);
    d[sz][sx][sy] = 0;
    while (que.size()) {
        weizhi p = que.front();
        que.pop();
        if (p.a == gz && p.b == gx && p.c == gy) {
            break;
        }
        for (int i = 0;i < 6;++i) {
            int nz = p.a + dz[i],nx = p.b + dx[i],ny = p.c + dy[i];
            if (0 < nz && nz <= L && 0 < nx && nx <= R && 0 < ny && ny <= C && maze[nz][nx][ny] != '#' && d[nz][nx][ny] == INF) {
                weizhi tianjia;
                tianjia.a = nz;
                tianjia.b = nx;
                tianjia.c = ny;
                que.push(tianjia);
                d[nz][nx][ny] = d[p.a][p.b][p.c] + 1;
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    while (cin >> L >> R >> C) {
        if (L == 0 && R == 0 && C == 0) {
            break;
        }
        for (int i = 1;i <= L;++i) {
            for (int j = 1;j <= R;++j) {
                for (int k = 1;k <= C;++k) {
                    cin >> maze[i][j][k];
                    if (maze[i][j][k] == 'S') {
                        sz = i;
                        sx = j;
                        sy = k;
                    }
                    if (maze[i][j][k] == 'E') {
                        gz = i;
                        gx = j;
                        gy = k;
                    }
                }
            }
        }
        bfs();
        if (d[gz][gx][gy] == INF) {
            cout << "Trapped!" << endl;
        }
        else {
            cout << "Escaped in " << d[gz][gx][gy] << " minute(s)." << endl;
        }
    }
}
