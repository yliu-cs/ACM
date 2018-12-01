#include <bits/stdc++.h>
using namespace std;
 
const int INF = 0x3f3f3f3f;
const int maxn = 1e3 + 5;
 
struct Status {
    int X, Y, Time;
};
 
int N, M;
int StartX, StartY;
int EndX, EndY;
int FireX, FireY;
char Maze[maxn][maxn];
int Vis[maxn][maxn];
 
bool Bfs() {
    memset(Vis, INF, sizeof(Vis));
    queue<Status> Que;
    Que.push(Status {StartX, StartY, 0});
    while (!Que.empty()) {
        Status Cur = Que.front(); Que.pop();
        if (Cur.X == EndX && Cur.Y == EndY) {
            return true;
        }
        for (int i = -1; i < 2; ++i) {
            for (int j = -1; j < 2; ++j) {
                if (abs(i) != abs(j)) {
                    int NX = Cur.X + i, NY = Cur.Y + j;
                    if (NX >= 0 && NX < N && NY >= 0 && NY < M && Vis[NX][NY] > Cur.Time + 1 && Maze[NX][NY] != '#') {
                        if (abs(NX - FireX) + abs(NY - FireY) > Cur.Time + 1) {
                            Que.push(Status {NX, NY, Cur.Time + 1});
                            Vis[NX][NY] = Cur.Time + 1;
                        }
                    }
                }
            }
        }
    }
    return false;
}
 
int main(int argc, char *argv[]) {
    while (~scanf("%d%d", &N, &M)) {
        for (int i = 0; i < N; ++i) {
            scanf("%s", Maze[i]);
            for (int j = 0; j < M; ++j) {
                if (Maze[i][j] == 'S') {
                    StartX = i;
                    StartY = j;
                }
                else if (Maze[i][j] == 'E') {
                    EndX = i;
                    EndY = j;
                }
                else if (Maze[i][j] == 'F') {
                    FireX = i;
                    FireY = j;
                }
            }
        }
        if (Bfs()) {
            printf("PIG PIG PIG!\n");
        }
        else {
            printf("A! WO SI LA!\n");
        }
    }
    return 0;
}
