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

int main() {
  scanf("%d%d", &n, &m);
  tree.Init();
  for (int i = 1, x; i <= n; ++i) {
    scanf("%d", &x);
    tree.Modify(i, x);
  }
  for (int i = 1, op; i <= m; ++i) {
    scanf("%d", &op);
    if (op == 1) {
      int idx, x; scanf("%d%d", &idx, &x);
      tree.Modify(idx, x);
    }
    else {
      int l, r; scanf("%d%d", &l, &r);
      printf("%d\n", tree.Query(r) - tree.Query(l - 1));
    }
  }
  return 0;
}

