#include <bits/stdc++.h>
using namespace std;

const int maxn = 2e1 + 5;

long long Dp[maxn][maxn];

void Init() {
    memset(Dp, 0, sizeof(Dp));
    Dp[0][0] = 1;
    for (int i = 1; i <= 19; ++i) {
        for (int j = 0; j < 10; ++j) {
            for (int k = 0; k < 10; ++k) {
                if (!(j == 4 && k == 9)) {
                    Dp[i][j] += Dp[i - 1][k];
                }
            }
        }
    }
}

long long Cal(long long X) {
    long long Ans = 0, Len = 0;
    long long Digit[maxn];
    while (X) {
        Digit[++Len] = X % 10;
        X /= 10;
    }
    Digit[Len + 1] = 0;
    for (int i = Len; i > 0; --i) {
        for (int j = 0; j < Digit[i]; ++j) {
            if (Digit[i + 1] != 4 || j != 9) {
                Ans += Dp[i][j];
            }
        }
        if (Digit[i + 1] == 4 && Digit[i] == 9) {
            break;
        }
    }
    return Ans;
}

int main(int argc, char *argv[]) {
    Init();
    int T;
    scanf("%d", &T);
    for (int Case = 1; Case <= T; ++Case) {
        long long N;
        scanf("%lld", &N);
        printf("%lld\n", N + 1 - Cal(N + 1));
    }
    return 0;
}

