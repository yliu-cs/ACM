#include <bits/stdc++.h>
const int maxm = 2e3 + 5;
const double eps = 1e-6;

int n, m, k;
std::vector<double> eng[maxm];
double pro[maxm];
double dp[maxm][maxm];
double ans;

int main() {
  scanf("%d%d%d", &n, &m, &k);

  for (int i = 0, tar; i < n; ++i) {
    double p;
    scanf("%d%lf", &tar, &p);
    eng[tar].push_back(1.0 - p);
  }

  for (int i = 1; i <= m; ++i) {
    double _p = 1.0;
    for (double &p : eng[i]) _p *= p;
    pro[i] = 1.0 - _p;
  }

  dp[1][0] = 1.0 - pro[1]; dp[1][1] = pro[1];
  for (int i = 2; i <= m; ++i) {
    for (int k = 0; k <= i; ++k) {
      dp[i][k] = dp[i - 1][k] * (1.0 - pro[i]);
      if (k > 0) dp[i][k] += dp[i - 1][k - 1] * pro[i];
    }
  }

  ans = 0.0;
  for (int i = k; i <= m; ++i) ans += dp[m][i];

  printf("%.3lf\n", ans);
  return 0;
}

