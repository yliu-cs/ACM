#include <bits/stdc++.h>

const int C = 26;
const int N = 1e5 + 5;

int n;
char str[N];
int cnt[C];

int Get(char x) {
  return x - 'a';
}

int main() {
  scanf("%d%s", &n, str + 1);
  for (int i = 1; i <= n; ++i) {
    ++cnt[Get(str[i])];
  }
  for (int i = 1; i <= cnt[Get('n')]; ++i) {
    printf("1 ");
  }
  for (int i = 1; i <= cnt[Get('r')]; ++i) {
    printf("0 ");
  }
  return 0;
}

