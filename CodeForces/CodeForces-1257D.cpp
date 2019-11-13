#include <bits/stdc++.h>
 
const int N = 2e5 + 5;
const int LOG = 25;
 
struct SpareTable {
  int n, a[N], max[N][LOG];
 
  void Init(int a[]) {
    int m = log2(n) + 1;
    for (int i = 1; i <= n; ++i) {
      max[i][0] = a[i];
    }
    for (int j = 1; j < m; ++j) {
      for (int i = 1; i + (1 << j) - 1 <= n; ++i) {
        max[i][j] = std::max(max[i][j - 1], max[i + (1 << (j - 1))][j - 1]);
      }
    }
  }
 
  int QueryMax(int l, int r) {
    int k = log2(r - l + 1);
    return std::max(max[l][k], max[r - (1 << k) + 1][k]);
  }
};
 
int t, n, maxa, maxp, a[N];
struct Hero {
  int p, s;
};
bool operator < (const Hero &k1, const Hero &k2) {
  return k1.p < k2.p;
}
int m;
Hero hero[N];
int p[N], s[N];
SpareTable st1, st2;
int cur, ans;
 
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cin >> t;
  while (t--) {
    maxa = 0;
    std::cin >> n;
    for (int i = 1; i <= n; ++i) {
      std::cin >> a[i];
      maxa = std::max(maxa, a[i]);
    }
    st1.n = n;
    st1.Init(a);
    maxp = 0;
    std::cin >> m;
    for (int i = 1; i <= m; ++i) {
      std::cin >> hero[i].p >> hero[i].s;
      maxp = std::max(maxp, hero[i].p);
    }
    if (maxa > maxp) {
      std::cout << -1 << '\n';
      continue;
    }
    std::sort(hero + 1, hero + m + 1);
    for (int i = 1; i <= m; ++i) {
      p[i] = hero[i].p;
      s[i] = hero[i].s;
    }
    st2.n = m;
    st2.Init(s);
    cur = ans = 0;
    while (true) {
      int bl = 1, br = n - cur, bans = 1;
      while (bl <= br) {
        int bm = (bl + br) / 2;
        int monster = st1.QueryMax(cur + 1, cur + bm);
        int idx = std::lower_bound(p + 1, p + m + 1, monster) - p;
        if (idx > m) {
          br = bm - 1;
          continue;
        }
        int maxs = st2.QueryMax(idx, m);
        if (maxs >= bm) {
          bans = bm;
          bl = bm + 1;
        }
        else {
          br = bm - 1;
        }
      }
      ++ans;
      cur += bans;
      if (cur >= n) {
        break;
      }
    }
    std::cout << ans << '\n';
  }
  return 0;
}
