#include <bits/stdc++.h>
const int maxn = 1e3 + 5;
int a[maxn], b[maxn];
int main() {
  int t;
  scanf("%d", &t);
  for (int cas = 1; cas <= t; ++cas) {
    int n;
    scanf("%d", &n);
    int idxa = -1, idxb = -1;
    int _a = -1, _b = -1;
    for (int i = 1; i <= n; ++i) scanf("%d", &a[i]);
    for (int i = 1; i <= n; ++i) scanf("%d", &b[i]);
    std::reverse(a + 1, a + n + 1);
    std::reverse(b + 1, b + n + 1);
    for (int i = 1; i <= n; ++i) {
      if (idxa == -1 && a[i] != 0) {
        idxa = n - i;
        _a = a[i];
      }
    }
    for (int i = 1; i <= n; ++i) {
      if (idxb == -1 && b[i] != 0) {
        idxb = n - i;
        _b = b[i];
      }
    }
    if (idxa == idxb) {
      int gcd = std::__gcd(_a, _b);
      printf("%d/%d\n", _a / gcd, _b / gcd);
    }
    else if (idxa < idxb) printf("0/1\n");
    else printf("1/0\n");
  }
  return 0;
}
