#include <bits/stdc++.h>

const int N = 1e5 + 5;
const int K = 1e5 + 5;

int n, k;
std::vector<std::pair<int, int>> edge;
int pre[N + K];
std::set<int> set;

int Find(int x) {
  if (pre[x] == x) {
    return x;
  }
  return pre[x] = Find(pre[x]);
}

void Union(int u, int v) {
  pre[Find(u)] = Find(v);
}

int main() {
  scanf("%d%d", &n, &k);
  for (int i = 1; i <= k; ++i) {
    int a, b;
    scanf("%d%d", &a, &b);
    edge.push_back({n + i, a});
    edge.push_back({n + i, b});
  }
  for (int i = 1; i <= n + k; ++i) {
    pre[i] = i;
  }
  for (auto &e : edge) {
    int u = e.first, v = e.second;
    if (Find(u) != Find(v)) {
      Union(u, v);
    }
  }
  for (int i = 1; i <= n + k; ++i) {
    set.insert(Find(i));
  }
  std::cout << k - (n - (int)set.size()) << '\n';
  return 0;
}

