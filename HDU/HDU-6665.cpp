#include <bits/stdc++.h>
struct point  {
  long long x, y;
  void Read() {
    scanf("%lld%lld", &x, &y);
  }
};
bool operator == (const point &k1, const point &k2) {
  return k1.x == k2.x && k1.y == k2.y;
}
bool operator > (const point &k1, const point &k2) {
  return k1.x > k2.x && k1.y > k2.y;
}
bool operator < (const point &k1, const point &k2) {
  return k1.x < k2.x && k1.y < k2.y;
}
struct rectangle {
  point s, t;
  void Read() {
    s.Read(); t.Read();
  }
};
bool operator == (const rectangle &k1, const rectangle &k2) {
  return k1.s == k2.s && k1.t == k2.t;
}
int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    rectangle a, b;
    a.Read(); b.Read();
    if (a == b) {
      printf("2\n");
      continue;
    }
    if ((a.s.y > b.s.y) ||
        (a.s.y == b.s.y && a.t.y < b.t.y) ||
        (a.s.y == b.s.y && a.t.y == b.t.y && a.s.x > b.s.x) ||
        (a.s.y == b.s.y && a.t.y == b.t.y && a.s.x == b.s.x && a.t.x < b.t.x)) {
          std::swap(a, b);
        }
    if ((b.s > a.s && a.t > b.t) ||
        (a.s == b.s && b.t < a.t) ||
        (a.t == b.t && a.s < b.s) ||
        (a.s.y == b.s.y && a.t.x == b.t.x && b.s.x > a.s.x && b.t.y < a.t.y) ||
        (a.s.x == b.s.x && a.t.y == b.t.y && b.s.y > a.s.y && b.t.x < a.t.x) ||
        (b.s > a.s && b.t.x == a.t.x && b.t.y < a.t.y) ||
        (b.s > a.s && b.t.y == a.t.y && b.t.x < a.t.x) ||
        (b.t < a.t && b.s.x == a.s.x && b.s.y > a.s.y) ||
        (b.t < a.t && a.s.y == b.s.y && b.s.x > a.s.x) ||
        (a.t == b.t && a.s.y == b.s.y && a.s.x < b.s.x) ||
        (a.s == b.s && a.t.x == b.t.x && a.t.y > b.t.y) ||
        (a.s == b.s && b.t.y == a.t.y && b.t.x < a.t.x) ||
        (a.t == b.t && a.s.x == b.s.x && b.s.y > a.s.y) ||
        (b.s.y >= a.t.y) ||
        (b.s.x >= a.t.x) ||
        (b.t.x <= a.s.x)) {
          printf("3\n");
          continue;
        }
    if (b.s.y > a.s.y && b.t.y < a.t.y && b.s.x < a.s.x && b.t.x > a.t.x) {
      printf("6\n");
      continue;
    }
    if ((b.s.y == a.s.y && b.s.x < a.s.x && b.t.x > a.t.x && b.t.y < a.t.y) ||
        (b.t.x == a.t.x && b.t.y < a.t.y && a.s.x > b.s.x && a.s.y < b.s.y) ||
        (b.t.y == a.t.y && a.s.y < b.s.y && a.s.x > b.s.x && a.t.x < b.t.x) ||
        (a.s.x == b.s.x && a.t.x < b.t.x && a.s.y < b.s.y && a.t.y > b.t.y)) {
          printf("5\n");
          continue;
        }
    printf("4\n");
  }
  return 0;
}
