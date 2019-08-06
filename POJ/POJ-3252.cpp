#include <cstdio>
#include <iostream>
#include <cstring>
using namespace std;

const int maxn = 3e1 + 5;

int Dp[maxn][maxn][maxn];
int Digit[maxn];

// Site:数位，NumOfZero:高位0的个数，NumOfOne:高位1的个数，Flag:前导0标记，Limit:高数位是否达上限
int Dfs(int Site, int NumOfZero, int NumOfOne, bool Flag, bool Limit) {
    if (Site == 0) {
        return NumOfZero >= NumOfOne;
    }
    if (!Limit && ~Dp[Site][NumOfZero][NumOfOne]) {
        return Dp[Site][NumOfZero][NumOfOne];
    }
    int Max = Limit ? Digit[Site] : 1;
    int Ans = 0;
    for (int i = 0; i <= Max; ++i) {
        int NowNumOfZero = (Flag && i == 0) ? 0 : NumOfZero + (i == 0);
        int NowNumOfOne = (Flag && i == 0) ? 0 : NumOfOne + (i == 1);
        Ans += Dfs(Site - 1, NowNumOfZero, NowNumOfOne, Flag && i == 0, Limit && i == Max);
    }
    if (!Flag) {
        Dp[Site][NumOfZero][NumOfOne] = Ans;
    }
    return Ans;
}

int Cal(int X) {
    // 分解X为二进制
    int Len = 0;
    while (X) {
        Digit[++Len] = X & 1;
        X >>= 1;
    }
    return Dfs(Len, 0, 0, true, true);
}

int main(int argc, char *argv[]) {
    int L, R;
    memset(Dp, -1, sizeof(Dp));
    while (scanf("%d%d", &L, &R) == 2) {
        printf("%d\n", Cal(R) - Cal(L - 1));
    }
    return 0;
}
