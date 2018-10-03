#include <bits/stdc++.h>

const int maxn = 1e5 + 5;

// Dp[i][j]:Str1[1]~Str1[i]和Str2[1]~Str2[j]对应的公共子序列长度
int Dp[maxn][maxn];

// 最长公共子序列(LCS)
void LCS(std::string Str1, std::string Str2) {
    for (int i = 0; i < int(Str1.length()); ++i) {
        for (int j = 0; j < int(Str2.length()); ++j) {
            if (Str1[i] == Str2[j]) {
                Dp[i + 1][j + 1] = Dp[i][j] + 1;
            }
            else {
                Dp[i + 1][j + 1] = std::max(Dp[i][j + 1], Dp[i + 1][j]);
            }
        }
    }
}
