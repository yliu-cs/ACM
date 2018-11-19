#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e1 + 5;

int Dp[maxn][maxn];

void Init() {
    Dp[0][0] = 1;
    for (int i = 1; i <= 7; ++i) {
        for (int j = 0; j < 10; ++j) {
            for (int k = 0; k < 10; ++k) {
                if (j != 4 && !(j == 6 && k == 2)) {
                    Dp[i][j] += Dp[i - 1][k];
                }
            }
        }
    }
}

int Cal(int X) {
    int Ans = 0, Len = 0;
    int Digit[maxn];
    while (X) {
        Digit[++Len] = X % 10;
        X /= 10;
    }
    Digit[Len + 1] = 0;
    for (int i = Len; i > 0; --i) {
        for (int j = 0; j < Digit[i]; ++j) {
            if (Digit[i + 1] != 6 || j != 2) {
                Ans += Dp[i][j];
            }
        }
        if (Digit[i] == 4 || (Digit[i + 1] == 6 && Digit[i] == 2)) {
            break;
        }
    }
    return Ans;
}

int main(int argc, char *argv[]) {
    Init();
    int N, M;
    while (~scanf("%d%d", &N, &M) && N + M) {
        printf("%d\n", Cal(M + 1) - Cal(N));
    }
    return 0;
}

