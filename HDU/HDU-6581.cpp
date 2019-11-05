#include <bits/stdc++.h>
const int maxn = 1e5 + 5;
const double eps = 1e-9;

int Sgn(double k) {
  return fabs(k) < eps ? 0 : (k < 0 ? -1 : 1);
}

int Cmp(double k1, double k2) {
  return Sgn(k1 - k2);
}

double Max(double k1, double k2) {
  return Cmp(k1, k2) > 0 ? k1 : k2;
}

int t;
int n;
double l[maxn];
double s[maxn];
double v[maxn];
double last[maxn];
double ans;

int main() {
  while (~scanf("%d", &n)) {
    for (int i = 0; i <= n; ++i) scanf("%lf", &l[i]);
    for (int i = 0; i <= n; ++i) scanf("%lf", &s[i]);
    for (int i = 0; i <= n; ++i) scanf("%lf", &v[i]);
    last[0] = 0.0;
    for (int i = 1; i <= n; ++i) last[i] = last[i - 1] + l[i];
    ans = 0.0;
    for (int i = 0; i <= n; ++i) {
      double t = (last[i] + s[i]) / v[i];
      ans = Max(ans, t);
    }
    printf("%.10lf\n", ans);
  }
  return 0;
}