#include <bits/stdc++.h>
const int maxn = 1e6 + 5;

char a[maxn], b[maxn];

int main() {
  int t; scanf("%d", &t);
  for (int cas = 1; cas <= t; ++cas) {
    int n; scanf("%d", &n);
    scanf("%s", a);
    scanf("%s", b);

    int cnt = 0;
    for (int i = 0; i < n; ++i) {
      if (a[i] != b[i] && (i == 0 || a[i - 1] == b[i - 1])) ++cnt;
    }

    if (cnt > 2) printf("0\n");
    else if (cnt == 0) printf("%lld\n", 1ll * n * (n + 1) / 2);
    else if (cnt == 1) printf("%lld\n", 2ll * (n - 1));
    else if (cnt == 2) printf("6\n");
  }
  return 0;
}

