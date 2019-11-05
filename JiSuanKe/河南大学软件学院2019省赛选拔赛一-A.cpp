#include <bits/stdc++.h>
const int maxn = 1e3 + 5;

int t;
int n;
int arr[maxn];

int main() {
  std::cin >> t;
  while (t--) {
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) scanf("%d", &arr[i]);

    int ans = 0;
    for (int i = 0; i < n; ++i) {
      for (int j = i + 1; j < n; ++j) {
        for (int k = j + 1; k < n; ++k) {
          ans = std::max(ans, ((arr[i] + arr[j]) ^ arr[k]));
          ans = std::max(ans, ((arr[i] + arr[k]) ^ arr[j]));
          ans = std::max(ans, ((arr[j] + arr[k]) ^ arr[i]));
        }
      }
    }

    std::cout << ans << '\n';
  }
  return 0;
}
