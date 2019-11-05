#include <bits/stdc++.h>
#define lowbit(x) (x&(-x))
const int maxn = 5e5 + 5;

struct BitTree {
  int arr[maxn];

  void Init() { memset(arr, 0, sizeof(0)); }

  void Modify(int idx, int x) {
    while (idx < maxn) {
      arr[idx] += x;
      idx += lowbit(idx);
    }
  }

  int Query(int idx) {
    int ret = 0;
    while (idx > 0) {
      ret += arr[idx];
      idx -= lowbit(idx);
    }
    return ret;
  }
};

int n, m;
BitTree tree;
int last;

int main() {
  scanf("%d%d", &n, &m);
  for (int i = 1, x, diff; i <= n; ++i) {
    scanf("%d", &x);
    diff = x - last;
    tree.Modify(i, diff);
    last = x;
  }
  for (int i = 0, op; i < m; ++i) {
    scanf("%d", &op);
    if (op == 1) {
      int l, r, x; scanf("%d%d%d", &l, &r, &x);
      tree.Modify(l, x);
      tree.Modify(r + 1, -x);
    }
    else {
      int idx; scanf("%d", &idx);
      printf("%d\n", tree.Query(idx));
    }
  }
  return 0;
}

