// Author: Tonyst4rk Time: 2019-10-29 15:52:54
#include <bits/stdc++.h>

const int N = 1e5 + 5;

struct Index {
  int val, pos;
};
bool operator < (const Index &k1, const Index &k2) {
  return k1.val < k2.val;
}

int n;
Index idx[N];
int ans[N];

int main() {
  scanf("%d", &n);
  for (int i = 1, x; i <= n; ++i) {
    scanf("%d", &x);
    idx[i] = ((Index){x, i});
  }
  std::sort(idx + 1, idx + n + 1);
  std::reverse(idx + 1, idx + n + 1);
  for (int i = 1; i <= n; ++i) {
    ans[idx[i].pos] = i;
  }
  for (int i = 1; i <= n; ++i) {
    printf("%d ", ans[i]);
  }
  printf("\n");
  return 0;
}

