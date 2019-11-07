#include <bits/stdc++.h>

const int N = 10;
const int INF = 1e5 + 5;

int t, min, c[N];

int main() {
  scanf("%d", &t);
  while (t--) {
    for (int i = 0; i < N; ++i) {
      scanf("%d", &c[i]);
    }
    min = c[0] + 1;
    for (int i = 1; i < N; ++i) {
      min = std::min(min, c[i]);
    }
    if (min == c[0] + 1) {
      printf("1");
      for (int j = 0; j < c[0] + 1; ++j) {
        printf("0");
      }
      printf("\n");
    }
    else {
      for (int i = 1; i < N; ++i) {
        if (c[i] == min) {
          for (int j = 0; j < c[i] + 1; ++j) {
            printf("%d", i);
          }
          printf("\n");
          break;
        }
      }
    }
  }
  return 0;
}

