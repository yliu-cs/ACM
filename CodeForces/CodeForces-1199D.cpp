#include <bits/stdc++.h>

const int N = 2e5 + 5;

int a[N], tree[N * 4], lazy[N * 4];

void Pull(int o) {
  tree[o] = std::max(tree[o * 2], tree[o * 2 + 1]);
}

void Push(int o) {
  if (lazy[o] != 0) {
    tree[o * 2] = std::max(tree[o * 2], lazy[o]);
    lazy[o * 2] = std::max(lazy[o * 2], lazy[o]);
    tree[o * 2 + 1] = std::max(tree[o * 2 + 1], lazy[o]);
    lazy[o * 2 + 1] = std::max(lazy[o * 2 + 1], lazy[o]);
    lazy[o] = 0;
  }
}

void Build(int o, int l, int r) {
  tree[o] = lazy[o] = 0;
  if (l == r) {
    tree[o] = a[l];
    return;
  }
  Push(o);
  int m = (l + r) / 2;
  Build(o * 2, l, m);
  Build(o * 2 + 1, m + 1, r);
  Pull(o);
}

void Modify(int o, int l, int r, int idx, int v) {
  if (l == r) {
    tree[o] = v;
    return;
  }
  Push(o);
  int m = (l + r) / 2;
  if (idx <= m) {
    Modify(o * 2, l, m, idx, v);
  }
  else {
    Modify(o * 2 + 1, m + 1, r, idx, v);
  }
  Pull(o);
}

void Query(int o, int l, int r) {
  if (l == r) {
    a[l] = tree[o];
    return;
  }
  Push(o);
  int m = (l + r) / 2;
  Query(o * 2, l, m);
  Query(o * 2 + 1, m + 1, r);
}

int main() {
  int n;
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i) {
    scanf("%d", &a[i]);
  }
  Build(1, 1, n);
  int q;
  scanf("%d", &q);
  while (q--) {
    int opt;
    scanf("%d", &opt);
    if (opt == 1) {
      int p, x;
      scanf("%d%d", &p, &x);
      Modify(1, 1, n, p, x);
    }
    else {
      int x;
      scanf("%d", &x);
      tree[1] = std::max(tree[1], x);
      lazy[1] = std::max(lazy[1], x);
    }
  }
  Query(1, 1, n);
  for (int i = 1; i <= n; ++i) {
    printf("%d ", a[i]);
  }
  printf("\n");
  return 0;
}

