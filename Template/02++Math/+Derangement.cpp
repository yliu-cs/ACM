const int maxn = "Edit";
const int mod = "Edit";

long long stag[maxn];

// 错排
void GetStag() {
  stag[1] = 0; stag[2] = 1;
  for (int i = 3; i < maxn; ++i) stag[i] = (i - 1) * (stag[i - 1] + stag[i - 2]) % mod;
}

