#include <cstdio>
#include <iostream>
using namespace std;

const int maxn = 3;

int T;
char Piece;
char Plat[maxn][maxn];

bool PosJudge(int X, int Y) {
    return X >= 0 && X < maxn && Y >= 0 && Y < maxn;
}

bool Check() {
    for (int i = 0; i < maxn; ++i) {
        int Cnt = 0;
        for (int j = 0; j < maxn; ++j) {
            if (Plat[i][j] == Piece) {
                Cnt++;
            }
        }
        if (Cnt == 3) {
            return true;
        }
    }
    for (int i = 0; i < maxn; ++i) {
        int Cnt = 0;
        for (int j = 0; j < maxn; ++j) {
            if (Plat[j][i] == Piece) {
                Cnt++;
            }
        }
        if (Cnt == 3) {
            return true;
        }
    }
    if (Plat[0][0] == Piece && Plat[1][1] == Piece && Plat[2][2] == Piece) {
        return true;
    }
    else if (Plat[0][2] == Piece && Plat[1][1] == Piece && Plat[2][0] == Piece) {
        return true;
    }
    for (int x = 0; x < maxn; ++x) {
        for (int y = 0; y < maxn; ++y) {
            int Cnt = 0;
            for (int i = -1; i <= 1; ++i) {
                for (int j = -1; j <= 1; ++j) {
                    if (i != 0 && j != 0) {
                        int nx = x + i, ny = y + j;
                        if (PosJudge(nx, ny)) {
                            if (Plat[nx][ny] == Piece) {
                                if (PosJudge(x - i, y - i)) {
                                    if (Plat[x - i][y - i]) {
                                        Cnt++;
                                    }
                                }
                            }
                        }
                    }
                }
            }
            if (Cnt > 1) {
                return true;
            }
        }
    }
    return false;
}

int main(int argc, char *argv[]) {
    cin >> T;
    for (int Case = 1; Case <= T; ++Case) {
        for (int i = 0; i < maxn; ++i) {
            for (int j = 0; j < maxn; ++j) {
                cin >> Plat[i][j];
            }
        }
        cin >> Piece;
        bool Flag = false;
        for (int i = 0; i < maxn; ++i) {
            for (int j = 0; j < maxn; ++j) {
                if (Plat[i][j] == '.') {
                    Plat[i][j] = Piece;
                    if (Check()) {
                        Flag = true;
                        break;
                    }
                    Plat[i][j] = '.';
                }
            }
            if (Flag) {
                break;
            }
        }
        if (Flag) {
            printf("Kim win!\n");
        }
        else {
            printf("Cannot win!\n");
        }
    }
    return 0;
}

