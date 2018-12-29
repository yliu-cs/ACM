#include<bits/stdc++.h>
using namespace std;

const int maxn = 1e5 + 5;

int N;
char Str[maxn];
long long Cost[maxn];
long long Dp[maxn][4];

int main(int argc, char *argv[]) {
    scanf("%d%s", &N, Str + 1);
    for (int i = 1; i <= N; ++i) {
        scanf("%lld", &Cost[i]);
    }
    for (int i = 1; i <= N; ++i) {
        for (int j = 0; j < 4; ++j) {
            Dp[i][j] = Dp[i - 1][j];
        }
        if (Str[i] == 'h') {
            Dp[i][0] += Cost[i];
        }
        else if (Str[i] == 'a') {
            // 把i位置之前(包括i)的字符'a'全部清除
            // 或
            // 把i位置之前(不包括i)的字符'h'全部清除并清除i位置的字符'a'
            Dp[i][1] = min(Dp[i - 1][0], Dp[i][1] + Cost[i]);
        }
        else if (Str[i] == 'r') {
            Dp[i][2] = min(Dp[i - 1][1], Dp[i][2] + Cost[i]);
        }
        else if (Str[i] == 'd') {
            Dp[i][3] = min(Dp[i - 1][2], Dp[i][3] + Cost[i]);
        }
    }
    printf("%lld\n", min(Dp[N][0], min(Dp[N][1], min(Dp[N][2], Dp[N][3]))));
    return 0;
}

