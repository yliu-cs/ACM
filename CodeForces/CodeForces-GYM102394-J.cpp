#include <bits/stdc++.h>

int t, n;

int main() {
  scanf("%d", &t);
  while (t--) {
    scanf("%d", &n);
    if (n % 2 == 0) {
      if (n == 2 || n == 4) {
        printf("-1\n");
      }
      else {
        printf("2 %d\n", n - 2);
      }
    }
    else {
      if (n == 1 || n == 3 || n == 5) {
        printf("-1\n");
      }
      else {
        printf("3 %d\n", n - 3);
      }
    }
  }
  return 0;
}

