#include <bits/stdc++.h>

const int N = 2e5 + 5;
const long long INF = 1e18 + 5;

long long max[N * 4], idx[N * 4], lazy[N * 4];

void Pull(int o) {
  if (max[o * 2] > max[o * 2 + 1]) {
    max[o] = max[o * 2];
    idx[o] = idx[o * 2];
  }
  else {
    max[o] = max[o * 2 + 1];
    idx[o] = idx[o * 2 + 1];
  }
}

void Push(int o) {
  if (lazy[o] != 0) {
    max[o * 2] += lazy[o];
    max[o * 2 + 1] += lazy[o];
    lazy[o * 2] += lazy[o];
    lazy[o *2 + 1] += lazy[o];
    lazy[o] = 0;
  }
}

void Build(int o, int l, int r) {
  max[o] = lazy[o] = 0;
  if (l == r) {
    idx[o] = l;
    return;
  }
  int m = (l + r) / 2;
  Build(o * 2, l, m);
  Build(o * 2 + 1, m + 1, r);
  Pull(o);
}

void Modify(int o, int l, int r, int ql, int qr, long long v) {
  if (ql <= l && qr >= r) {
    max[o] += v;
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
    return {max[o], idx[o]};
  }
  Push(o);
  int m = (l + r) / 2;
  std::pair<long long, int> ret = {-INF, 0};
  if (ql <= m) {
    std::pair<long long, int> lq = Query(o * 2, l, m, ql, qr);
    if (lq.first > ret.first) {
      ret = lq;
    }
  }
  if (qr > m) {
    std::pair<long long, int> rq = Query(o * 2 + 1, m + 1, r, ql, qr);
    if (rq.first > ret.first) {
      ret = rq;
    }
  }
  return ret;
}

int n;
long long k;
struct Project {
  int l, r;
  long long p;
};
Project pro[N];
std::vector<Project> vec[N];
struct Record {
  long long p, l, r;
};
Record ans;
std::vector<int> cho;

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cin >> n >> k;
  for (int i = 1; i <= n; ++i) {
    std::cin >> pro[i].l >> pro[i].r >> pro[i].p;
    vec[pro[i].r].push_back(pro[i]);
  }
  ans.p = 0;
  Build(1, 1, N - 1);
  for (int r = 1; r < N; ++r) {
    Modify(1, 1, N - 1, 1, r, -k);
    for (auto &p : vec[r]) {
      Modify(1, 1, N - 1, 1, p.l, p.p);
    }
    std::pair<long long, int> buf = Query(1, 1, N - 1, 1, r);
    if (buf.first > ans.p) {
      ans.p = buf.first;
      ans.l = buf.second;
      ans.r = r;
    }
  }
  for (int i = 1; i <= n; ++i) {
    if (pro[i].l >= ans.l && pro[i].r <= ans.r) {
      cho.push_back(i);
    }
  }
  if (ans.p == 0) {
    std::cout << ans.p << '\n';
  }
  else {
    std::cout << ans.p << ' ' << ans.l << ' ' << ans.r << ' ' << cho.size() << '\n';
    for (auto &v : cho) {
      std::cout << v << ' ';
    }
    std::cout << '\n';
  }
  return 0;
}

