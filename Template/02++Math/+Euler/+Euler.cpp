int GetPhi(int x) {
  int ret = x;
  for (int i = 2; i * i <= x; ++i) {
    if (!(x % i)) {
      ret = ret / i * (i - 1);
      while (!(x % i)) x /= i;
    }
  }
  if (x > 1) ret = ret / x * (x - 1);
  return ret;
}
