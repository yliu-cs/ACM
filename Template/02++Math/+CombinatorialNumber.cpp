const int mod = "Edit";
const int maxn  = "Edit";

int c[maxn][maxn];

void GetC() {
  memset(c, 0, sizeof(c));
  c[0][0] = 1;
  for (int i = 1; i < maxn; ++i) {
    c[i][0] = 1;
    for (int j = 1; j <= i; ++j) {
      if (j == i) c[i][j] = 1;
      else c[i][j] = (c[i - 1][j - 1] + c[i - 1][j]) % mod;
    }
  }
}