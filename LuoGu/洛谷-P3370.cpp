#include <bits/stdc++.h>

const int N = 1e4 + 5;
const int L = 1e4 + 5;

const unsigned long long BASE = 131;

unsigned long long Hash(char s[]) {
  int len = std::strlen(s + 1);
  unsigned long long ret = 0;
  for (int i = 1; i <= len; ++i) {
    ret = ret * BASE + (unsigned long long)s[i];
  }
  return ret;
}

int n;
char s[L];
unsigned long long val[N];
int ans;

int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i) {
    scanf("%s", s + 1);
    val[i] = Hash(s);
  }
  std::sort(val + 1, val + n + 1);
  ans = std::unique(val + 1, val + n + 1) - val - 1;
  printf("%d\n", ans);
  return 0;
}

