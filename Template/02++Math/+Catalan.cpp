const int maxn = "Edit";

long long cat[maxn];

void GetCat() {
  memset(cat, 0, sizeof(cat));
  cat[0] = cat[1] = 1;
  for (int i = 2; i < maxn; ++i) cat[i] = cat[i - 1] * (4 * i - 2) / (i + 1);
}
