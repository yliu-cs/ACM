#include <bits/stdc++.h>
using namespace std;
 
const int maxn = 1e3 + 5;
 
char Str1[maxn], Str2[maxn];
int Len1, Len2;
int Dp[maxn][maxn];
int Ans;
 
void Debug() {
    for (int i = 0; i < Len1; ++i) {
        for (int j = 0; j < Len2; ++j) {
            printf("Dp[%d][%d]=%d ", i, j, Dp[i][j]);
        }
        printf("\n");
    }
}
 
int main(int argc, char *argv[]) {
    scanf("%s%s", Str1, Str2);
    Len1 = strlen(Str1), Len2 = strlen(Str2);
    for (int i = 1; i <= Len1; ++i) {
        for (int j = 1; j <= Len2; ++j) {
            if (Str1[i - 1] == Str2[j - 1]) {
                Dp[i][j] = Dp[i - 1][j - 1] + 1;
            }
            else {
                Dp[i][j] = max(Dp[i - 1][j], Dp[i][j - 1]);
            }
        }
    }
    Ans = Dp[Len1][Len2];
    printf("%d\n", Ans);
    return 0;
}
