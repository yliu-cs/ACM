// Author: Tony5t4rk Time: 2019-08-11 21:33:41 
#include <bits/stdc++.h>
const int maxn = 2e3 + 5;

char map[maxn][maxn];
std::pair<int, int> c[maxn], r[maxn];

int main() {
  int n, k;
  scanf("%d%d", &n, &k);
  for (int i = 1; i <= n; ++i) {
    r[i] = {-1, -1};
    c[i] = {-1, -1};
  }
  int ori = 0;
  for (int i = 1; i <= n; ++i) {
    scanf("%s", map[i] + 1);
    for (int j = 1; j <= n; ++j) {
      if (map[i][j] == 'B') {
        if (r[i].first == -1) r[i].first = j;
        r[i].second = j;
      }
    }
    if (r[i].first == -1) ++ori;
  }
  for (int j = 1; j <= n; ++j) {
    for (int i = 1; i <= n; ++i) {
      if (map[i][j] == 'B') {
        if (c[j].first == -1) c[j].first = i;
        c[j].second = i;
      }
    }
    if (c[j].first == -1) ++ori;
  }
  int ans = 0;
  for (int i = 1; i <= n - k + 1; ++i) {
    std::multiset<int> fi;
    std::multiset<std::pair<int, int> > la;
    int cnt = 0;
    for (int l = i; l <= i + k - 1; ++l) {
      if (r[l].first == -1) continue;
      if (r[l].second <= k) {
        fi.insert(r[l].first);
        ++cnt;
      }
      else la.insert({r[l].second, r[l].first});
    }
    for (int l = 1; l <= k; ++l) {
      if (c[l].first != -1 && c[l].first >= i && c[l].second <= i + k - 1) ++cnt;
    }
    ans = std::max(ans, cnt);
    for (int j = 2; j <= n - k + 1; ++j) {
      if (c[j - 1].first != -1 && c[j - 1].first >= i && c[j - 1].second <= i + k - 1) --cnt;
      if (c[j + k - 1].first != -1 && c[j + k - 1].first >= i && c[j + k - 1].second <= i + k - 1) ++cnt;
      while (!fi.empty() && *fi.begin() < j) {
        --cnt;
        fi.erase(fi.begin());
      }
      while (!la.empty() && la.begin()->first <= j + k - 1) {
        if (la.begin()->second >= j) {
          ++cnt;
          fi.insert(la.begin()->second);
        }
        la.erase(la.begin());
      }
      ans = std::max(ans, cnt);
    }
  }
  std::cout << ans + ori << '\n';
  return 0;
}

