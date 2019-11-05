#include <bits/stdc++.h>
using namespace std;

const int maxn = (int)(1e1 + 5);

int T;
int N;
int Map[maxn][maxn];
int R[maxn], C[maxn];
int RPrefix[maxn];
int CPrefix[maxn];
int RXPrefix[maxn];
int CXPrefix[maxn];
int RVis[maxn][maxn];
int CVis[maxn][maxn];
bool Flag;
int All;

void Init() {
    All = 0;
    for (int i = 1; i <= N - 2; ++i) All += i;
    for (int i = 1; i <= N; ++i) RXPrefix[i] = 0;
    for (int i = 1; i <= N; ++i) CXPrefix[i] = 0;
    for (int i = 1; i <= N; ++i) RPrefix[i] = 0;
    for (int i = 1; i <= N; ++i) CPrefix[i] = 0;
    for (int i = 1; i <= N; ++i)
        for (int j = 1; j <= N; ++j)
            Map[i][j] = 0;
}

void Clean(int &X, int &Y, int &Key) {
    if (RVis[X][0] == 2 || RVis[X][0] == 0) RPrefix[X] -= Key;
    else if (RVis[X][0] == 1) RXPrefix[X] -= Key;
    if (CVis[Y][0] == 2 || CVis[Y][0] == 0) CPrefix[Y] -= Key;
    else if (CVis[Y][0] == 1) CXPrefix[Y] -= Key;
    RVis[X][Key]++; CVis[Y][Key]++;
}

void Display() {
    for (int i = 1; i <= N; ++i) {
        for (int j = 1; j <= N; ++j) {
            printf("%c", Map[i][j] == 0 ? 'X' : Map[i][j] + '0');
        }
        printf("\n");
    }
    printf("\n");
}

void Dfs(int X, int Y) {
    if (X == N + 1 && Y == 1) {
        Flag = true;
        return;
    }
    for (int i = 0; i <= N - 2; ++i) {
        if (RVis[X][i] > 0 && CVis[Y][i] > 0) {
            RVis[X][i]--; CVis[Y][i]--;
            Map[X][Y] = i;
            if (RVis[X][0] == 2 || RVis[X][0] == 0) RPrefix[X] += i;
            else if (RVis[X][0] == 1) RXPrefix[X] += i;
            if (CVis[Y][0] == 2 || CVis[Y][0] == 0) CPrefix[Y] += i;
            else if (CVis[Y][0] == 1) CXPrefix[Y] += i;
            if (RPrefix[X] > (All - R[X])) {Clean(X, Y, i); return;}
            if (CPrefix[Y] > (All - C[Y])) {Clean(X, Y, i); return;}
            if (RXPrefix[X] > R[X]) {Clean(X, Y, i); return;}
            else if (i == 0 && RVis[X][0] == 0 && RXPrefix[X] < R[X]) {
                Clean(X, Y, i);
                continue;
            }
            if (CXPrefix[Y] > C[Y]) {Clean(X, Y, i); return;}
            else if (i == 0 && CVis[Y][0] == 0 && CXPrefix[Y] < C[Y]) {
                Clean(X, Y, i);
                continue;
            }
            if (Y == N) Dfs(X + 1, 1);
            else Dfs(X, Y + 1);
            if (Flag) return;
            Clean(X, Y, i);
        }
    }
}

int main(int argc, char *argv[]) {
    scanf("%d", &T);
    for (int Case = 1; Case <= T; ++Case) {
        scanf("%d", &N);
        for (int i = 1; i <= N; ++i) scanf("%d", &R[i]);
        for (int i = 1; i <= N; ++i) scanf("%d", &C[i]);
        Init();
        for (int i = 1; i <= N; ++i) {
            for (int j = 0; j <= N - 2; ++j) {
                if (j == 0) RVis[i][j] = CVis[i][j] = 2;
                else RVis[i][j] = CVis[i][j] = 1;
            }
        }
        Flag = false;
        Dfs(1, 1);
        Display();
    }
    return 0;
}
