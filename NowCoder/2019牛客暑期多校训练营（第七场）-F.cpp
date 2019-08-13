#include <bits/stdc++.h>
const int maxn = 1e5 + 5;
struct BitTree {
  long long arr[maxn * 2];
  inline int lowbit(int x) {
    return x & (-x);
  }
  void Init() {
    memset(arr, 0, sizeof(arr));
  }
  void Modify(int idx, int x) {
    while (idx < maxn * 2) {
      arr[idx] += x;
      idx += lowbit(idx);
    }
  }
  long long Query(int idx) {
    long long ret = 0;
    while (idx > 0) {
      ret += arr[idx];
      idx -= lowbit(idx);
    }
    return ret;
  }
};
BitTree T1, T2;
std::set<int> set;
void Add(int x) {
  if (set.empty()) {
    set.emplace(x);
    return;
  }
  auto it = set.lower_bound(x);
  if (it == set.begin()) {
    int v = (*it) - x;
    T1.Modify(v, 1);
    T2.Modify(v, v);
  }
  else if (it == set.end()) {
    int v = x - (*std::prev(it));
    T1.Modify(v, 1);
    T2.Modify(v, v);
  }
  else {
    int v1 = x - (*std::prev(it)), v2 = (*it) - x, v3 = (*it) - (*std::prev(it));
    T1.Modify(v1, 1);
    T1.Modify(v2, 1);
    T1.Modify(v3, -1);
    T2.Modify(v1, v1);
    T2.Modify(v2, v2);
    T2.Modify(v3, -v3);
  }
  set.emplace(x);
}
void Del(int x) {
  auto it = set.find(x);
  if (set.size() == 1) {
    set.erase(it);
    return;
  }
  if (it == set.begin()) {
    int v = (*std::next(it)) - x;
    T1.Modify(v, -1);
    T2.Modify(v, -v);
  }
  else if (it == std::prev(set.end())) {
    int v = x - (*std::prev(it));
    T1.Modify(v, -1);
    T2.Modify(v, -v);
  }
  else {
    int v1 = x - (*std::prev(it)), v2 = (*std::next(it)) - x, v3 = (*std::next(it)) - (*std::prev(it));
    T1.Modify(v1, -1);
    T1.Modify(v2, -1);
    T1.Modify(v3, 1);
    T2.Modify(v1, -v1);
    T2.Modify(v2, -v2);
    T2.Modify(v3, v3);
  }
  set.erase(it);
}
long long ori[maxn], inc[maxn], all[maxn];
std::vector<int> add[maxn], del[maxn];
int main() {
  int t;
  scanf("%d", &t);
  for (int cas = 1; cas <= t; ++cas) {
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) scanf("%lld%lld%lld", &ori[i], &inc[i], &all[i]);
    int m;
    scanf("%d", &m);
    for (int i = 1; i <= n + 1; ++i) {
      add[i].clear();
      del[i].clear();
    }
    for (int i = 1, w, l, r; i <= m; ++i) {
      scanf("%d%d%d", &w, &l, &r);
      add[l].emplace_back(w);
      del[r + 1].emplace_back(w);
    }
    set.clear();
    T1.Init();
    T2.Init();
    long long ans = 0;
    for (int i = 1; i <= n + 1; ++i) {
      for (int &v : add[i]) Add(v);
      for (int &v : del[i]) Del(v);
      if (set.empty()) continue;
      ans += std::min(all[i], ori[i] + (*set.begin()) * inc[i]);
      if (inc[i] == 0) continue;
      ans += T2.Query(all[i] / inc[i]) * inc[i] + (set.size() - 1 - T1.Query(all[i] / inc[i])) * all[i];
    }
    printf("Case #%d: %lld\n", cas, ans);
  }
  return 0;
}
