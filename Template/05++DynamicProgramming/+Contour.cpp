const int maxn = "Edit";

int dp[2][1 << maxn];

void Update(int cur, int a, int b) {
  if (b & (1 << M)) dp[cur][b ^ (1 << M)] = dp[cur][b ^ (1 << M)] + dp[cur ^ 1][a];
}

// 轮廓线dp(1*2在N*M图上摆放数)
int Contour(int N, int M) {
  memset(dp, 0, sizeof(dp));
  int cur = 0;
  dp[cur][(1 << M) - 1] = 1;
  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < M; ++j) {
      cur ^= 1;
      memset(dp[cur], 0, sizeof(dp[cur]));
      for (int k = 0; k < (1 << M); ++k) {
        Update(cur, k, k << 1);
        if (i && !(k & (1 << (M - 1)))) Update(cur, k, (k << 1) ^ (1 << M) ^ 1);
        if (j && (!(k & 1))) Update(cur, k, (k << 1) ^ 3);
      }
    }
  }
  return dp[cur][(1 << M) - 1];
}

