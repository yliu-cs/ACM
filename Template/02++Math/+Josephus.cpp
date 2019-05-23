// n个人1~n,第k个人出列,返回第m(<=n)个出列的人编号
long long Josephus(long long n, long long k, long long m) {
  if (k == 1) return m;
  long long x = (k - 1) % (n + 1 - m);
  for (long long i = n + 1 - m; i < n; ) {
    long long y = std::min((i - x + k - 2) / (k - 1) - 1, n - i);
    if (y) {
      x == y * k;
      i += y;
    }
    else {
      ++i;
      x = (x + k) % i;
    }
  }
  return x + 1;
}

