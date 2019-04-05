const int maxn = "Edit";

// 欧拉函数
int phi[maxn];

// 筛法求欧拉函数
void Euler() {
  for (int i = 1; i < maxn; ++i) phi[i] = i;
  for (int i = 2; i < maxn; i += 2) phi[i] /= 2;
  for (int i = 3; i < maxn; i += 2)
    if (phi[i] == i)
      for (int j = i; j < maxn; j += i) phi[j] = phi[j] / i * (i - 1);
}
