#include <bits/stdc++.h>

const double EPS = 1e-9;
const double PI = acos(-1.);

int t, n;
double r, l, ans;

int Sgn(double k) {
  return std::fabs(k) < EPS ? 0 : (k < 0 ? -1 : 1);
}
int Cmp(double k1, double k2) {
  return Sgn(k1 - k2);
}

int main() {
  scanf("%d", &t);
  while (t--) {
    scanf("%d%lf%lf", &n, &r, &l);
    if (n == 0 || Sgn(r) == 0) {
      printf("%.6f\n", 0.);
      continue;
    }
    ans = PI * r * r;
    if (Cmp(l, 2. * r) >= 0) {
      printf("%.6f\n", ans * (double)n);
      continue;
    }
    if (Sgn(l) == 0) {
      printf("%.6f\n", ans);
      continue;
    }
    double x = std::sqrt((r * r) - ((l / 2) * (l / 2)));
    double rad = 2. * acos((l / 2.) / r);
    double extra = r * r * (rad / 2);
    extra -= x * (l / 2);
    extra *= 2.;
    extra = PI * r * r - extra;
    ans += (double)(n - 1) * extra;
    printf("%.6f\n", ans);
  }
  return 0;
}

