#include <bits/stdc++.h>

const int N = 1e5 + 5;

int t, n, k, w[N];
long long sum;

int main() {
  scanf("%d", &t);
  while (t--) {
    scanf("%d%d", &n, &k);
    sum = 0;
    for (int i = 1; i <= n; ++i) {
      scanf("%d", &w[i]);
      sum += w[i];
    }
    for (int i = 1; i <= n; ++i) {
      printf("%.8lf ", (double)w[i] / (double)sum * (double)(sum + k));
    }
    printf("\n");
  }
  return 0;
}

