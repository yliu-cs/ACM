const int maxn = "Edit";
const int mod = "Edit";

long long staggered[maxn];

// 错排
void GetStaggered() {
  staggered[1] = 0; staggered[2] = 1;
  for (int i = 3; i < maxn; ++i) staggered[i] = (i - 1) * (staggered[i - 1] + staggered[i - 2]) % mod;
}

