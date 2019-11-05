#include <bits/stdc++.h>

int main() {
  int t; scanf("%d", &t);
  for (int cas = 1; cas <= t; ++cas) {
    int n; scanf("%d", &n);
    std::vector<int> arr(n);
    for (int &v : arr) scanf("%d", &v);
    std::sort(arr.begin(), arr.end());
    long long ans = 0;
    for (int i = 0; i < n - 1; ++i) ans += arr[i];
    printf("%lld\n", ans);
  }
  return 0;
}

