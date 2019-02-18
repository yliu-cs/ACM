#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 5;

int Digit[15];
int Dp[15];

int Dfs(int Site, bool Pre, bool Limit) {
    if (Site == 0) return 1;
    if (!Limit && ~Dp[Site]) return Dp[Site];
    int Max = Limit ? Digit[Site] : 9;
    int Ans = 0;
    for (int i = 0; i <= Max; ++i) {
        if (i != 8) Ans += Dfs(Site - 1, Pre && i == 0, Limit && i == Max);
    }
    if (!Limit) Dp[Site] = Ans;
    return Ans;
}

int Cal(int Key) {
    int Len = 0;
    while (Key) {
        Digit[++Len] = Key % 10;
        Key /= 10;
    }
    return Dfs(Len, true, true);
}

int L, R;

int main(int argc, char *argv[]) {
    memset(Dp, -1, sizeof(Dp));
    scanf("%d%d", &L, &R);
    printf("%d\n", R - L + 1 - (Cal(R) - Cal(L - 1)));
    return 0;
}

