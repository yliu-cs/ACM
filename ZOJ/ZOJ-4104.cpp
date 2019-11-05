#include <bits/stdc++.h>
const int maxn = 1e5 + 5;

int t, n;
int arr[maxn];
std::map<int, std::vector<int> > map;
int sz, last;
bool flag;
int ans;

int main() {

  scanf("%d", &t);
  for (int cas = 1; cas <= t; ++cas) {
    map.clear();

    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
      scanf("%d", &arr[i]);
      map[arr[i]].push_back(i);
    }

    std::sort(arr, arr + n);
    sz = std::unique(arr, arr + n) - arr;

    last = -1;
    flag = false;
    ans = 0;
    for (int i = sz - 1; i >= 0; --i) {
      if (flag) {
        ans += (int)map[arr[i]].size();
        continue;
      }
      std::sort(map[arr[i]].begin(), map[arr[i]].end());
      if (last == -1) {
        last = map[arr[i]][0];
        continue;
      }
      if (map[arr[i]].back() < last) {
        last = std::min(last, map[arr[i]][0]);
        continue;
      }
      flag = true;
      int idx = std::lower_bound(map[arr[i]].begin(), map[arr[i]].end(), last) - map[arr[i]].begin();
      ans += (int)map[arr[i]].size() - idx;
      last = std::min(last, map[arr[i]][0]);
    }

    std::cout << ans << '\n';
  }

  return 0;
}

