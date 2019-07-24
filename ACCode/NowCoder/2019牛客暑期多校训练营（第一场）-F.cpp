#include <bits/stdc++.h>
typedef long long ll;

struct point { ll x, y; };
point operator - (point k1, point k2) { return (point){k1.x - k2.x, k1.y - k2.y}; }
ll operator ^ (point k1, point k2) { return k1.x * k2.y - k1.y * k2.x; }

int main() {
  point a, b, c;
  while (~scanf("%lld%lld%lld%lld%lld%lld", &a.x, &a.y, &b.x, &b.y, &c.x,&c.y)) {
    printf("%lld\n", 11 * std::abs((b - a) ^ (c - a)));
  }
  return 0;
}
