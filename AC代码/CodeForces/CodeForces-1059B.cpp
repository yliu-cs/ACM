#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e3 + 5;

int N, M;
char Maze[maxn][maxn];
bool Book[maxn][maxn];

void Change(int X, int Y) {
    for (int i = -1; i <= 1; ++i) {
        for (int j = -1; j <= 1; ++j) {
            if (i == 0 && j == 0) {
                continue;
            }
            int NX = X + i, NY = Y + j;
            if (NX >= 0 && NX < N && NY >= 0 && NY < M) {
                if (Maze[NX][NY] == '.') {
                    return;
                }
            }
        }
    }
    for (int i = -1; i <= 1; ++i) {
        for (int j = -1; j <= 1; ++j) {
            if (i == 0 && j == 0) {
                continue;
            }
            int NX = X + i, NY = Y + j;
            Book[NX][NY] = true;
        }
    }
}

int main(int argc, char *argv[]) {
    scanf("%d%d", &N, &M);
    for (int i = 0; i < N; ++i) {
        scanf("%s", Maze[i]);
    }
    memset(Book, false, sizeof(Book));
    for (int i = 1; i < N - 1; ++i) {
        for (int j = 1; j < M - 1; ++j) {
            Change(i, j);
        }
    }
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            if (Maze[i][j] == '#' && Book[i][j] == false) {
                printf("NO\n");
                return 0;
            }
        }
    }
    printf("YES\n");
    return 0;
}
