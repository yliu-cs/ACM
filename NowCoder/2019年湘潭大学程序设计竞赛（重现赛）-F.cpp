#include <bits/stdc++.h>
const int maxn = 1e5 + 5;

int t;
int n, m;
char str[maxn];
std::vector<std::pair<int, int>> idx[2];
int ans;

int main() {
  scanf("%d", &t);
  for (int cas = 1; cas <= t; ++cas) {
    scanf("%d%d", &n, &m);
    scanf("%s", str);

    idx[0].clear(); idx[1].clear();
    for (int i = 0; i < n; ++i) {
      int lptr = i, rptr = i;
      if (i - 1 >= 0 && str[i - 1] != str[i]) {
        --lptr;
        while (lptr - 1 >= 0 && str[lptr - 1] != str[i]) --lptr;
      }
      if (i + 1 < n && str[i + 1] != str[i]) {
        ++rptr;
        while (rptr + 1 < n && str[rptr + 1] != str[i]) ++rptr;
      }
      idx[(int)(str[i] - '0')].push_back({lptr, rptr});
    }

    if ((int)idx[0].size() < m || (int)idx[1].size() < m) {
      printf("%d\n", n);
      continue;
    }

    int max = 1;
    for (int i = 1, len = 1; i < n; ++i) {
      if (str[i - 1] == str[i]) len++;
      else len = 1;
      max = std::max(max, len);
    }

    ans = max;

    if (m == 0) {
      printf("%d\n", ans);
      continue;
    }

    for (int l = 0, r; l + m - 1 < (int)idx[0].size(); ++l) {
      r = l + m - 1;
      ans = std::max(ans, idx[0][r].second - idx[0][l].first + 1);
    }
    for (int l = 0, r; l + m - 1 < (int)idx[1].size(); ++l) {
      r = l + m - 1;
      ans = std::max(ans, idx[1][r].second - idx[1][l].first + 1);
    }

    printf("%d\n", ans);
  }
  return 0;
}

