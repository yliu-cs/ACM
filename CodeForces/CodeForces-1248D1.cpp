// Author: Tony5t4rk Time: 2019-10-21 17:01:05 
#include <bits/stdc++.h>
const int INF = 1e9 + 5;
const int N = 3e5 + 5;
int n, min, shift;
char s[N], str[N];
int val[N];
int ori, cnt, last;
int ans, l, r;
int Get(int x) {
  int ret = x + shift;
  while (ret > n) ret -= n;
  return ret;
}
int main() {
  scanf("%d%s", &n, s + 1);
  min = INF;
  for (int i = 1; i <= n; ++i) {
    val[i] = val[i - 1] + (s[i] == '(' ? 1 : -1);
    min = std::min(min, val[i]);
  }
  if (val[n] != 0) {
    printf("0\n1 1\n");
    return 0;
  }
  for (int i = 1; i <= n; ++i) {
    if (val[i] == min) {
      shift = i;
      int idx = 0;
      for (int j = i + 1; j <= n; ++j) str[++idx] = s[j];
      for (int j = 1; j <= i; ++j) str[++idx] = s[j];
      break;
    }
  }
  for (int i = 1; i <= n; ++i) {
    val[i] = val[i - 1] + (str[i] == '(' ? 1 : -1);
    ori += (val[i] == 0);
  }
  l = 1, r = 1;
  for (int i = 1; i <= n; ++i) {
    if (val[i] == 2) ++cnt;
    else if (val[i] <= 1) {
      if (ori + cnt > ans) {
        ans = ori + cnt;
        l = Get(last + 1);
        r = Get(i);
      }
      cnt = 0;
      last = i;
    }
  }
  cnt = last = 0;
  for (int i = 1; i <= n; ++i) {
    if (val[i] == 1) ++cnt;
    else if (val[i] == 0) {
      if (cnt > ans) {
        ans = cnt;
        l = Get(last + 1);
        r = Get(i);
      }
      cnt = 0;
      last = i;
    }
  }
  printf("%d\n%d %d\n", ans, l, r);
  return 0;
}
