#include <bits/stdc++.h>

const int N = 1e5 + 5;
const int INF = 1e9 + 5;

int n, m, idx[N], ele[N], max[N], min[N];

void Swap(int x, int y) {
  std::swap(ele[idx[x]], ele[idx[y]]);
  std::swap(idx[x], idx[y]);
  max[x] = std::max(max[x], idx[x]);
  min[x] = std::min(min[x], idx[x]);
  max[y] = std::max(max[y], idx[y]);
  min[y] = std::min(min[y], idx[y]);
}

int main() {
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; ++i) {
    idx[i] = ele[i] = max[i] = min[i] = i;
  }
  for (int i = 1; i <= m; ++i) {
    int x;
    scanf("%d", &x);
    if (idx[x] == 1) {
      continue;
    }
    Swap(x, ele[idx[x] - 1]);
  }
  for (int i = 1; i <= n; ++i) {
    printf("%d %d\n", min[i], max[i]);
  }
  return 0;
}

