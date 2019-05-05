const double pi = acos(-1.0);
const double e = 2.718281828459;

int GetStirling(int x) {
  if (x <= 1) return 1;
  return (int)ceil(log10(2 * pi * x) / 2 + x * log10(x / e));
}

