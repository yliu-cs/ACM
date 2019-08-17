#include <bits/stdc++.h>
const int maxn = 1e6 + 5;
struct point { long long x, y; };
point p[maxn];
int Div(long long &t, long long &b, long long &l, long long &r, int id) {
  long long x = p[id].x, y = p[id].y;
  long long h = (t + b) / 2ll, m = (l + r) / 2ll;
  if (x <= h) {
    if (y <= m) return 0;
    return 3;
  }
  if (y <= m) return 1;
  else return 2;
}
void Dfs(long long t, long long b, long long l, long long r, int f, const std::vector<int> &a) {
  if (a.size() == 1) {
    printf("%lld %lld\n", p[a[0]].x, p[a[0]].y);
    return;
  }
  std::vector<int> id[4];
  long long h = (t + b) / 2ll, m = (l + r) / 2ll;
  for (auto &i : a) id[Div(t, b, l, r, i)].push_back(i);
  if (f == 1) {
    if (!id[0].empty()) Dfs(t, h, l, m, 2, id[0]);
    if (!id[1].empty()) Dfs(h + 1, b, l, m, 1, id[1]);
    if (!id[2].empty()) Dfs(h + 1, b, m + 1, r, 1, id[2]);
    if (!id[3].empty()) Dfs(t, h, m + 1, r, 3, id[3]);
  }
  else if (f == 2) {
    if (!id[0].empty()) Dfs(t, h, l, m, 1, id[0]);
    if (!id[3].empty()) Dfs(t, h, m + 1, r, 2, id[3]);
    if (!id[2].empty()) Dfs(h + 1, b, m + 1, r, 2, id[2]);
    if (!id[1].empty()) Dfs(h + 1, b, l, m, 4, id[1]);
  }
  else if (f == 3) {
    if (!id[2].empty()) Dfs(h + 1, b, m + 1, r, 4, id[2]);
    if (!id[1].empty()) Dfs(h + 1, b, l, m, 3, id[1]);
    if (!id[0].empty()) Dfs(t, h, l, m, 3, id[0]);
    if (!id[3].empty()) Dfs(t, h, m + 1, r, 1, id[3]);
  }
  else if (f == 4) {
    if (!id[2].empty()) Dfs(h + 1, b, m + 1, r, 3, id[2]);
    if (!id[3].empty()) Dfs(t, h, m + 1, r, 4, id[3]);
    if (!id[0].empty()) Dfs(t, h, l, m, 4, id[0]);
    if (!id[1].empty()) Dfs(h + 1, b, l, m, 2, id[1]);
  }
}
int main() {
  long long n, k;
  scanf("%lld%lld", &n, &k);
  long long len = 1ll << k;
  std::vector<int> id;
  for (int i = 1; i <= n; ++i) {
    scanf("%lld%lld", &p[i].x, &p[i].y);
    id.emplace_back(i);
  }
  Dfs(1, len, 1, len, 1, id);
  return 0;
}
