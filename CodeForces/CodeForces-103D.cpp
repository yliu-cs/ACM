#include <bits/stdc++.h>

const int N = 3e5 + 5;
const int Q = 3e5 + 5;

int n, q, block;
long long a[N];
struct Query {
  int a, b, id;
};
bool operator < (const Query &k1, const Query &k2) {
  return k1.b < k2.b;
}
Query qry[Q];
long long buf[N], ans[Q];

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cin >> n;
  block = std::sqrt(n);
  for (int i = 1; i <= n; ++i) {
    std::cin >> a[i];
  }
  std::cin >> q;
  for (int i = 1; i <= q; ++i) {
    std::cin >> qry[i].a >> qry[i].b;
    qry[i].id = i;
  }
  std::sort(qry + 1, qry + q + 1);
  for (int i = 1; i <= q; ++i) {
    if (qry[i].b > block) {
      for (int j = qry[i].a; j <= n; j += qry[i].b) {
        ans[qry[i].id] += a[j];
      }
    }
    else {
      if (qry[i].b == qry[i - 1].b) {
        ans[qry[i].id] = buf[qry[i].a];
        continue;
      }
      for (int j = n; j > 0; --j) {
        if (j + qry[i].b > n) {
          buf[j] = a[j];
        }
        else {
          buf[j] = a[j] + buf[j + qry[i].b];
        }
      }
      ans[qry[i].id] = buf[qry[i].a];
    }
  }
  for (int i = 1; i <= q; ++i) {
    std::cout << ans[i] << '\n';
  }
  return 0;
}

