const int maxn = "Edit";

long long catalan[maxn];

// 递推求卡特兰数
void GetCalalan() {
  memset(catalan, 0, sizeof(catalan));
  catalan[0] = catalan[1] = 1;
  for (int i = 2; i < maxn; ++i) catalan[i] = Catalan[i - 1] * (4 * i - 2) / (i + 1);
}
