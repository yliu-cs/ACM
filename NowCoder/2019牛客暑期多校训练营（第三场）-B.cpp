#include <bits/stdc++.h>
const int maxn = 1e5 + 5;
 
int n;
char s[maxn];
int cnt[2];
int pref[maxn];
 
int main() {
  scanf("%d", &n);
  scanf("%s", s + 1);
  for (int i = 1; i <= n; ++i) {
    ++cnt[s[i] - '0'];
    pref[i] = pref[i - 1] + ((s[i] - '0') == 1);
  }
  int bl = 0, br = n / 2, ans = 0;
  while (bl <= br) {
    int m = (bl + br) >> 1;
    bool flag = false;
    for (int i = 0, l = 1, r = m * 2; i < n - m * 2 + 1; ++i, ++l, ++r) {
      if ((pref[r] - pref[l - 1]) * 2 == r - l + 1) {
        flag = true;
        break;
      }
    }
    if (flag) {
      ans = m * 2;
      bl = m + 1;
    }
    else br = m - 1;
  }
  printf("%d %d\n", ans, 2 * std::min(cnt[0], cnt[1]));
  return 0;
}