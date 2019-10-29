// Author: Tonyst4rk Time: 2019-10-29 16:07:53
#include <bits/stdc++.h>

const int N = 1e5 + 5;

int n, q;
int r[N], c[N];
std::vector<int> rodd, reven;
std::vector<int> codd, ceven;

int main() {
  scanf("%d%d", &n, &q);
  for (int i = 1; i <= n; ++i) {
    scanf("%d", &r[i]);
    if (r[i] & 1) rodd.push_back(i);
    else reven.push_back(i);
  }
  for (int i = 1; i <= n; ++i) {
    scanf("%d", &c[i]);
    if (c[i] & 1) codd.push_back(i);
    else ceven.push_back(i);
  }
  while (q--) {
    int r1, c1, r2, c2;
    scanf("%d%d%d%d", &r1, &c1, &r2, &c2);
    if (((r[r1] + c[c1]) & 1) || ((r[r1] + c[c2]) & 1)) {
      printf("NO\n");
      continue;
    }
    int top, bottom, left, right;
    if (c[c1] & 1) {
      auto it = std::lower_bound(reven.begin(), reven.end(), r1);
      if (it == reven.end() || r1 == n) bottom = n;
      else bottom = *it - 1;
      if (it == reven.begin() || r1 == 1) top = 1;
      else {
        --it;
        top = *it + 1;
      }
    }
    else {
      auto it = std::lower_bound(rodd.begin(), rodd.end(), r1);
      if (it == rodd.end() || r1 == n) bottom = n;
      else bottom = *it - 1;
      if (it == rodd.begin() || r1 == 1) top = 1;
      else {
        --it;
        top = *it + 1;
      }
    }
    if (r[r1] & 1) {
      auto it = std::lower_bound(ceven.begin(), ceven.end(), c1);
      if (it == ceven.end() || c1 == n) right = n;
      else right = *it - 1;
      if (it == ceven.begin() || c1 == 1) left = 1;
      else {
        --it;
        left = *it + 1;
      }
    }
    else {
      auto it = std::lower_bound(codd.begin(), codd.end(), c1);
      if (it == codd.end() || c1 == n) right = n;
      else right = *it - 1;
      if (it == codd.begin() || c1 == 1) left = 1;
      else {
        --it;
        left = *it + 1;
      }
    }
    if (r2 >= top && r2 <= bottom && c2 >= left && c2 <= right) printf("YES\n");
    else printf("NO\n");
  }
  return 0;
}

