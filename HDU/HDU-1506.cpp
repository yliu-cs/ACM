#include <bits/stdc++.h>
const int maxn = 1e5 + 5;
typedef long long ll;

int n;
ll arr[maxn];
int l[maxn], r[maxn];
std::stack<int> s;
ll ans = 0;

int main() {
  while (~scanf("%d", &n) && n) {
    while (!s.empty()) s.pop();
    s.push(0);
    for (int i = 1; i <= n; ++i) scanf("%lld", &arr[i]);
    arr[n + 1] = 0;
    for (int i = 1; i <= n + 1; ++i) {
      l[i] = r[i] = i;
      while (s.size() > 1 && arr[s.top()] >= arr[i]) {
        r[s.top()] = i - 1;
        s.pop();
      }
      l[i] = s.top();
      s.push(i);
    }
    ans = 0;
    for (int i = 1; i <= n; ++i) ans = std::max(ans, (r[i] - l[i]) * arr[i]);
    printf("%lld\n", ans);
  }
  return 0;
}