#include <bits/stdc++.h>
const int maxn = 1e3 + 5;

int t;
int n, k;
std::multiset<int> multiset;
int vol[maxn];
int sum;

bool Check(int x) {
  multiset.clear();
  for (int i = 1; i <= n; ++i) multiset.emplace(vol[i]);
  for (int i = 1; i <= k; ++i) {
    int last = x;
    while (last > 0 && !multiset.empty()) {
      std::multiset<int>::iterator it = multiset.upper_bound(last);
      if (it == multiset.begin()) break;
      it = std::prev(it);
      last -= *it;
      multiset.erase(it);
    }
  }
  return multiset.empty();
}

int main() {
  scanf("%d", &t);
  for (int cas = 1; cas <= t; ++cas) {
    scanf("%d%d", &n, &k);
    sum = 0;
    for (int i = 1; i <= n; ++i) {
      scanf("%d", &vol[i]);
      sum += vol[i];
    }
    sum = (sum + k - 1) / k;
    for (int x = sum; ; ++x) {
      if (Check(x)) {
        printf("Case #%d: %d\n", cas, x);
        break;
      }
    }
  }
  return 0;
}