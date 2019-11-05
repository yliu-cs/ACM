#include <bits/stdc++.h>

const int N = 2e3 + 5;
const int M = N * N;

int n;
int x[N], y[N];
long long c[N], k[N];
int pre[N];
struct Edge {
  int u, v;
  long long c;
};
bool operator < (const Edge &k1, const Edge &k2) {
  return k1.c < k2.c;
}
std::vector<Edge> edge;
long long sum;
std::vector<int> ans;
std::vector<std::pair<int, int>> record;

int Dis(int k1, int k2) {
  return std::abs(x[k1] - x[k2]) + std::abs(y[k1] - y[k2]);
}

long long Cal(int k1, int k2) {
  return 1ll * Dis(k1, k2) * (k[k1] + k[k2]);
}

int Find(int k) {
  if (pre[k] == k) {
    return k;
  }
  return pre[k] = Find(pre[k]);
}

void Union(int k1, int k2) {
  pre[Find(k1)] = Find(k2);
}

long long Kruskal() {
  long long ret = 0;
  std::sort(edge.begin(), edge.end());
  for (auto &e : edge) {
    if (Find(e.u) == Find(e.v)) {
      continue;
    }
    Union(e.u, e.v);
    if (e.u == 0) {
      ans.emplace_back(e.v);
    }
    else {
      record.push_back({e.u, e.v});
    }
    ret += e.c;
  }
  return ret;
}

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cin >> n;
  for (int i = 1; i <= n; ++i) {
    std::cin >> x[i] >> y[i];
  }
  for (int i = 1; i <= n; ++i) {
    std::cin >> c[i];
    edge.push_back((Edge){0, i, c[i]});
  }
  for (int i = 1; i <= n; ++i) {
    std::cin >> k[i];
  }
  for (int i = 1; i <= n; ++i) {
    for (int j = i + 1; j <= n; ++j) {
      edge.push_back((Edge){i, j, Cal(i, j)});
    }
  }
  for (int i = 0; i <= n; ++i) {
    pre[i] = i;
  }
  sum = Kruskal();
  std::cout << sum << '\n';
  std::cout << ans.size() << '\n';
  for (auto &v : ans) {
    std::cout << v << ' ';
  }
  std::cout << '\n';
  std::cout << record.size() << '\n';
  for (auto &e : record) {
    std::cout << e.first << ' ' << e.second << '\n';
  }
  return 0;
}

