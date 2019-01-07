#include <bits/stdc++.h>
using namespace std;

const int maxn = 15;
const int mod = 13;

int Digit[maxn];
// Dp[i][j][k]，i:数位，j:余数，k:末尾数
int Dp[maxn][maxn][maxn];

int Dfs(int Site, int Mod, int Flag, bool Limit) {
    if (Site == 0) {
        return (!Mod && Flag == 3);
    }
    if (!Limit && ~Dp[Site][Mod][Flag]) {
        return Dp[Site][Mod][Flag];
    }
    int Max = Limit ? Digit[Site] : 9;
    int Ans = 0;
    for (int i = 0; i <= Max; ++i) {
        int NowMod = (Mod * 10 + i) % mod;
        if (Flag == 1 && i == 3) {
            Ans += Dfs(Site - 1, NowMod, 3, Limit && i == Max);
        }
        else if (i == 1) {
            Ans += Dfs(Site - 1, NowMod, 1, Limit && i == Max);
        }
        else if (Flag == 1 && i != 3) {
            Ans += Dfs(Site - 1, NowMod, 0, Limit && i == Max);
        }
        else {
            Ans += Dfs(Site - 1, NowMod, Flag, Limit && i == Max);
        }
    }
    if (!Limit) {
        Dp[Site][Mod][Flag] = Ans;
    }
    return Ans;
}

int Cal(int X) {
    int Len = 0;
    while (X) {
        Digit[++Len] = X % 10;
        X /= 10;
    }
    memset(Dp, -1, sizeof(Dp));
    return Dfs(Len, 0, 0, 1);
}

int main(int argc, char *argv[]) {
    int X;
    while (~scanf("%d", &X)) {
        printf("%d\n", Cal(X));
    }
    return 0;
}
