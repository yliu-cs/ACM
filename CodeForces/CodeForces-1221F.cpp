#include <bits/stdc++.h>

const int N = 5e5 + 5;
const long long INF = 1e18 + 5;

struct Point {
  int x, y, c;
};
std::vector<Point> pt;
std::vector<int> arr;
std::vector<Point> sub[N * 2];

int Get(int x) {
  return std::lower_bound(arr.begin(), arr.end(), x) - arr.begin();
}

std::pair<long long, int> tree[N * 2 * 4];
long long lazy[N * 2 * 4];

void Pull(int o) {
  tree[o] = std::max(tree[o * 2], tree[o * 2 + 1]);
}

void Push(int o) {
  if (lazy[o] != 0) {
    tree[o * 2].first += lazy[o];
    tree[o * 2 + 1].first += lazy[o];
    lazy[o * 2] += lazy[o];
    lazy[o * 2 + 1] += lazy[o];
    lazy[o] = 0;
  }
}

void Build(int o, int l, int r) {
  lazy[o] = 0;
  if (l == r) {
    tree[o] = {-arr[l], l};
    return;
  }
  int m = (l + r) / 2;
  Build(o * 2, l, m);
  Build(o * 2 + 1, m + 1, r);
  Pull(o);
}

void Modify(int o, int l, int r, int ql, int qr, int v) {
  if (ql <= l && qr >= r) {
    tree[o].first += v;
    lazy[o] += v;
    return;
  }
  Push(o);
  int m = (l + r) / 2;
  if (ql <= m) {
    Modify(o * 2, l, m, ql, qr, v);
  }
  if (qr > m) {
    Modify(o * 2 + 1, m + 1, r, ql, qr, v);
  }
  Pull(o);
}

std::pair<long long, int> Query(int o, int l, int r, int ql, int qr) {
  if (ql <= l && qr >= r) {
    return tree[o];
  }
  Push(o);
  int m = (l + r) / 2;
  std::pair<long long, int> ret = {-INF, 0};
  if (ql <= m) {
    ret = std::max(ret, Query(o * 2, l, m, ql, qr));
  }
  if (qr > m) {
    ret = std::max(ret, Query(o * 2 + 1, m + 1, r, ql, qr));
  }
  return ret;
}

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int n;
  std::cin >> n;
  for (int i = 0; i < n; ++i) {
    int x, y, c;
    std::cin >> x >> y >> c;
    pt.push_back((Point){std::min(x, y), std::max(x, y), c});
    arr.push_back(x);
    arr.push_back(y);
  }
  arr.push_back(0);
  std::sort(arr.begin(), arr.end());
  arr.push_back(arr.back() + 1);
  arr.erase(std::unique(arr.begin(), arr.end()), arr.end());
  int sz = (int)arr.size();
  for (auto &p : pt) {
    p.x = Get(p.x);
    p.y = Get(p.y);
    sub[p.x].push_back(p);
  }
  Build(1, 0, sz - 1);
  long long ans = -1;
  int l = -1, r = -1;
  for (int i = sz - 1; i >= 0; --i) {
    for (auto &p : sub[i]) {
      Modify(1, 0, sz - 1, p.y, sz - 1, p.c);
    }
    std::pair<long long, int> buf = Query(1, 0, sz - 1, i, sz - 1);
    if (buf.first + arr[i] > ans) {
      ans = buf.first + arr[i];
      l = arr[i];
      r = arr[buf.second];
    }
  }
  std::cout << ans << '\n';
  std::cout << l << ' ' << l << ' ' << r << ' ' << r << '\n';
  return 0;
}

