const int maxn = "Edit";

int phi[maxn];

void GetPhi() {
  for (int i = 1; i < maxn; ++i) phi[i] = i;
  for (int i = 2; i < maxn; i += 2) phi[i] /= 2;
  for (int i = 3; i < maxn; i += 2)
    if (phi[i] == i)
      for (int j = i; j < maxn; j += i) phi[j] = phi[j] / i * (i - 1);
}
