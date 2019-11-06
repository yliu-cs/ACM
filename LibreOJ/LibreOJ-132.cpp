#include <bits/stdc++.h>

const int N = 1e6 + 5;

int n, q;
long long c1[N], c2[N];

void Modify(int x, long long v) {
  for (int i = x; i <= n; i += i & (-i)) {
    c1[i] += v;
    c2[i] += x * v;
  }
}

void Modify(int l, int r, long long v) {
  Modify(l, v);
  Modify(r + 1, -v);
}

long long Query(int x) {
  long long ret = 0;
  for (int i = x; i > 0; i -= i & (-i)) {
    ret += c1[i] * (x + 1) - c2[i];
  }
  return ret;
}

long long Query(int l, int r) {
  return Query(r) - Query(l - 1);
}

int main() {
  scanf("%d%d", &n, &q);
  for (int i = 1; i <= n; ++i) {
    int x;
    scanf("%d", &x);
    Modify(i, i, x);
  }
  while (q--) {
    int opt;
    scanf("%d", &opt);
    if (opt == 1) {
      int l, r;
      long long v;
      scanf("%d%d%lld", &l, &r, &v);
      Modify(l, r, v);
    }
    else {
      int l, r;
      scanf("%d%d", &l, &r);
      printf("%lld\n", Query(l, r));
    }
  }
  return 0;
}

