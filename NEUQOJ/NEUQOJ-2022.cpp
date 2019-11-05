#include <bits/stdc++.h>

int n;
long long ans;

int main() {
  scanf("%d", &n);
  for (int i = 0, x; i < n; ++i) {
    scanf("%d", &x);
    ans += x;
  }
  if (ans > 0) printf("icebound is happy.\n");
  else if (ans == 0) printf("icebound is ok.\n");
  else printf("icebound is sad.\n");
  return 0;
}

