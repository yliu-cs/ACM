const int maxn = "Edit";

void GetGeneratingFunction() {
  int n;
  int c1[maxn], c2[maxn];
  scanf("%d", &n);
  for (int i = 0; i < maxn; ++i) {
    c1[i] = 1;
    c2[i] = 0;
  }
  // c1[i]为x^i的系数
  // c2为中间变量
  for (int i = 2; i <= n; ++i) {
    for (int j = 0; j <= n; ++j) {
      for (int k = 0; k + j <= n; k += i) {
        c2[j + k] += c1[i];
      }
    }
    for (int j = 0; j <= n; ++j) {
      c1[j] = c2[j];
      c2[j] = 0;
    }
  }
}
