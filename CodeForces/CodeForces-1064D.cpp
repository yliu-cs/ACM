#include <bits/stdc++.h>
using namespace std;

const int INF = 0x3f3f3f3f;
const int maxn = 2e3 + 5;

struct Search {
    int X, Y;
    int LeftCnt, RightCnt;
};

int N, M;
int R, C;
int StartX, StartY;
int Ans;
char Maze[maxn][maxn];
bool Vis[maxn][maxn];
int LeftCnt[maxn][maxn];
int RightCnt[maxn][maxn];
int DX[4] = {1, -1, 0, 0}, DY[4] = {0, 0, -1, 1};

void Bfs() {
    memset(Vis, false, sizeof(Vis));
    memset(LeftCnt, INF, sizeof(LeftCnt));
    memset(RightCnt, INF, sizeof(RightCnt));
    queue<Search> Que;
    Que.push(Search {StartX, StartY, 0, 0});
    Vis[StartX][StartY] = true;
    Ans++;
    while (!Que.empty()) {
        Search Cur = Que.front(); Que.pop();
        for (int i = 0; i < 4; ++i) {
            int NX = Cur.X + DX[i], NY = Cur.Y + DY[i];
            if (NX >= 1 && NX <= N && NY >= 1 && NY <= M && Maze[NX][NY] == '.') {
                Search Temp;
                if (i == 2) {
                    if (Cur.LeftCnt + 1 > R) {
                        continue;
                    }
                    Temp = Search {NX, NY, Cur.LeftCnt + 1, Cur.RightCnt};
                }
                else if (i == 3) {
                    if (Cur.RightCnt + 1 > C) {
                        continue;
                    }
                    Temp = Search {NX, NY, Cur.LeftCnt, Cur.RightCnt + 1};
                }
                else {
                    Temp = Search {NX, NY, Cur.LeftCnt, Cur.RightCnt};
                }
                if (Vis[NX][NY]) {
                    if (Temp.LeftCnt >= LeftCnt[NX][NY] && Temp.RightCnt >= RightCnt[NX][NY]) {
                        continue;
                    }
                    else {
                        if (Temp.LeftCnt < LeftCnt[NX][NY]) {
                            LeftCnt[NX][NY] = Temp.LeftCnt;
                        }
                        if (Temp.RightCnt < RightCnt[NX][NY]) {
                            RightCnt[NX][NY] = Temp.RightCnt;
                        }
                    }
                }
                Que.push(Temp);
                if (!Vis[NX][NY]) {
                    Ans++;
                }
                Vis[NX][NY] = true;
            }
        }
    }
}

int main(int argc, char *argv[]) {
    scanf("%d%d", &N, &M);
    scanf("%d%d", &StartX, &StartY);
    scanf("%d%d", &R, &C);
    for (int i = 1; i <= N; ++i) {
        scanf("%s", Maze[i] + 1);
    }
    Ans = 0;
    Bfs();
    printf("%d\n", Ans);
    return 0;
}
