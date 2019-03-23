#include <bits/stdc++.h>

int main() {
  int n; char c; scanf("%d %c", &n, &c);
  getchar();
  const int maxn = 1e6 + 5;
  char str[maxn]; fgets(str, maxn, stdin);
  int len = strlen(str);
  if (str[len - 1] == '\n') str[len - 1] = '\0';
  len = strlen(str);
  if (len >= n) {
    for (int i = len - n; i < len; ++i) printf("%c", str[i]);
  }
  else {
    for (int i = 0; i < n - len; ++i) printf("%c", c);
    printf("%s", str);
  }
  return 0;
}
