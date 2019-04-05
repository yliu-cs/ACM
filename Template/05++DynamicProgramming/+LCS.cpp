const int maxn = "Edit";

// dp[i][j]:str1[1]~str1[i]和str2[1]~str2[j]对应的公共子序列长度
int dp[maxn][maxn];

// 最长公共子序列(LCS)
void GetLCS(std::string str1, std::string str2) {
  for (int i = 0; i < int(str1.length()); ++i) {
    for (int j = 0; j < int(str2.length()); ++j) {
      if (str1[i] == str2[j]) dp[i + 1][j + 1] = dp[i][j] + 1;
      else dp[i + 1][j + 1] = std::max(dp[i][j + 1], dp[i + 1][j]);
    }
  }
}
