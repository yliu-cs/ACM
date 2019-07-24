#include <bits/stdc++.h>
const int maxn = 3e1 + 5;

int n;
int c[maxn][maxn];
long long ans;
std::vector<int> a, b;

void Dfs(int idx, long long cur) {
  if (idx == n * 2 + 1) {
    ans = std::max(ans, cur);
    return;
  }
  long long sum;
  if ((int)a.size() < n) {
    a.push_back(idx);
    sum = 0;
    for (int &v : b) sum += c[idx][v];
    Dfs(idx + 1, cur + sum);
    a.pop_back();
  }
  if ((int)b.size() < n) {
    b.push_back(idx);
    sum = 0;
    for (int &v : a) sum += c[idx][v];
    Dfs(idx + 1, cur + sum);
    b.pop_back();
  }
}

int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n * 2; ++i)
    for (int j = 1; j <= n * 2; ++j)
      scanf("%d", &c[i][j]);
  Dfs(1, 0ll);
  printf("%lld\n", ans);
  return 0;
}