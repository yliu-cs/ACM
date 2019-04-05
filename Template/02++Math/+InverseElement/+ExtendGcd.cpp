// 扩展欧几里得，a*x+b*y=d
long long ExtendGcd(long long a, long long b, long long &x, long long &y) {
  // 无最大公约数
  if (a == 0 && b == 0) return -1;
  if (b == 0) {
    x = 1;
    y = 0;
    return a;
  }
  long long d = ExtendGcd(b, a % b, y, x);
  y -= a / b * x;
  return d;
}

// 逆元，ax = 1(mod M)
long long GetInv(long long a, long long N) {
  long long x, y;
  long long d = ExtendGcd(a, N, x, y);
  if (d == 1) return (x % N + N) % N;
  else return -1;
}

