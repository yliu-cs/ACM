#include <bits/stdc++.h>

const int maxn = "Edit";

long long Digit[25];
long long Dp[25][maxn];

// Site:数位,Statu:状态,Pre:前导零,Limit:数位上界
long long Dfs(long long Site, long long Statu, bool Pre, bool Limit) {
    if (Site == 0) {
        return ?;
    }
    if (!Limit && ~Dp[Site][Statu]) {
        return Dp[Site][Statu];
    }
    long long Max = Limit ? Digit[Site] : 9;
    long long Ans = 0;
    for (int i = 0; i <= Max; ++i) {
        long long NowStatu = /*状态转移*/;
        if (NowStatu?) {
            Ans += Dfs(Site - 1, NowStatu, Pre && i == 0, Limit && i == Max);
        }
    }
    if (!Limit) {
        Dp[Site][Statu] = Ans;
    }
    return Ans;
}

long long Cal(long long X) {
    // 数位分解
    long long Len = 0;
    while (X) {
        Digit[++Len] = X % 10;
        X /= 10;
    }
    return Dfs(Len, 0, true, true);
}

