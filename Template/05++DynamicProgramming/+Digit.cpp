const int maxn = "Edit";

long long digit[25];
long long dp[25][maxn];

// site:数位,status:状态,pre:前导零,limit:数位上界
long long Dfs(long long site, long long status, bool pre, bool limit) {
  if (site == 0) return ?;
  if (!limit && ~dp[site][status]) return dp[site][status];
  long long max = limit ? digit[site] : 9;
  long long ret = 0;
  for (int i = 0; i <= max; ++i) {
    long long new_status = /*状态转移*/;
    if (new_status?) ret += Dfs(site - 1, new_status, pre && i == 0, limit && i == max);
  }
  if (!limit) dp[site][status] = ret;
  return ret;
}

long long Get(long long x) {
  long long len = 0;
  while (x) {
    digit[++len] = x % 10;
    x /= 10;
  }
  return Dfs(len, 0, true, true);
}

