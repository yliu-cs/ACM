#include <bits/stdc++.h>
using namespace std;

const int maxn = 70;
const int mod = 10000;

struct Search {
    // 坐标位置和步数
    int X, Y, Step;
    // 按二进制存全图翻转信息
    unsigned long long Status;
    // 是否拿到钥匙
    bool Key;
    Search() {
        X = Y = Step = 0;
        Status = 0;
        Key = false;
    }
    // 乱搞哈希
    int hash() {
        return (Status % mod + X + Y + Key) % mod;
    }
    bool operator == (const Search &a) {
        return a.X == X && a.Y == Y && a.Status == Status && a.Key == Key;
    }
};

int T;
int N, M;
int StartX, StartY;
int KeyX, KeyY;
int EndX, EndY;
int Ans;
char Plat[maxn][maxn];
queue<Search> Que;
vector<Search> Hash[mod];

bool PosJudge(int X, int Y) {
    return X >= 0 && X < N && Y >= 0 && Y < M;
}

void Add(int X, int Y, int Step, unsigned long long Status, bool Key) {
    // 哈希去重判断此状态是否走过
    Search Judge;
    Judge.X = X; Judge.Y = Y; Judge.Step = Step; Judge.Status = Status; Judge.Key = Key;
    int Temp = Judge.hash();
    for (int i = 0; i < int(Hash[Temp].size()); ++i) {
        if (Hash[Temp][i] == Judge) {
            return;
        }
    }
    // 若没走过则添加进Hash表以及队列中
    Hash[Temp].push_back(Judge);
    Que.push(Judge);
}

// 翻转(X,Y)
unsigned long long Convert(int X, int Y, unsigned long long Status) {
    for (int i = -1; i <= 1; ++i) {
        for (int j = -1; j <= 1; ++j) {
            if (abs(i) != abs(j)) {
                int NX = X + i, NY = Y + j;
                if (PosJudge(NX, NY)) {
                    Status ^= 1ull << (NX * M + NY);
                }
            }
        }
    }
    return Status;
}

// 更新
void Update(int X, int Y, int Step, unsigned long long Status, bool Key) {
    // 是否翻转
    bool Flag = (1ull << (X * M + Y)) & Status;
    // 陷阱但是翻转过，可以走
    if (Plat[X][Y] == 'x' && Flag) {
        Add(X, Y, Step, Status, Key);
    }
    // 不是陷阱并且没有翻转过，可以走
    else if (Plat[X][Y] != 'x' && !Flag) {
        // 拿到钥匙，改变Key状态
        if (X == KeyX && Y == KeyY) {
            Add(X, Y, Step, Status, true);
        }
        // 到达机关，可以翻转四个方向
        else if (Plat[X][Y] == '*') {
            Add(X, Y, Step, Convert(X, Y, Status), Key);
        }
        else {
            Add(X, Y, Step, Status, Key);
        }
    }
}

void Bfs() {
    while (!Que.empty()) {
        Que.pop();
    }
    for (int i = 0; i < mod; ++i) {
        Hash[i].clear();
    }
    Search Start;
    Start.X = StartX; Start.Y = StartY; Start.Step = 0; Start.Status = 0; Start.Key = false;
    Hash[Start.hash()].push_back(Start);
    Que.push(Start);
    while (!Que.empty()) {
        Search Keep = Que.front();
        Que.pop();
        if (Keep.X == EndX && Keep.Y == EndY && Keep.Key == true) {
            Ans = Keep.Step;
            return;
        }
        for (int i = -1; i <= 1; ++i) {
            for (int j = -1; j  <= 1; ++j) {
                if (abs(i) != abs(j)) {
                    int NX = Keep.X + i, NY = Keep.Y + j;
                    if (PosJudge(NX, NY)) {
                        Update(NX, NY, Keep.Step + 1, Keep.Status, Keep.Key);
                    }
                }
            }
        }
    }
}

int main(int argc, char *argv[]) {
    scanf("%d", &T);
    for (int Case = 1; Case <= T; ++Case) {
        scanf("%d%d", &N, &M);
        for (int i = 0; i < N; ++i) {
            scanf("%s", Plat[i]);
            for (int j = 0; j < M; ++j) {
                if (Plat[i][j] == 'S') {
                    StartX = i; StartY = j;
                    Plat[i][j] = '.';
                }
                else if (Plat[i][j] == 'E') {
                    EndX = i; EndY = j;
                    Plat[i][j] = '.';
                }
                else if (Plat[i][j] == 'K') {
                    KeyX = i; KeyY = j;
                    Plat[i][j] = '.';
                }
            }
        }
        Ans = -1;
        Bfs();
        printf("Case #%d:\n%d\n", Case, Ans);
    } 
    return 0;
}

