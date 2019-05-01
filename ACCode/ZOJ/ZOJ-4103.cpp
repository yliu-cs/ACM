#include <bits/stdc++.h>
const int maxn = 1e5 + 5;

int t;
int n;
bool vis[maxn];
std::vector<int> ans;
int cur, tot;

int main() {
  scanf("%d", &t);
  for (int cas = 1; cas <= t; ++cas) {
    scanf("%d", &n);

    ans.clear();
    for (int i = 1; i <= n; ++i) vis[i] = false;

    int cur = 1;
    for (int i = 1; i <= n; ++i) {
      ans.push_back(cur);
      vis[cur] = true;
      if (cur == n / 2 && !vis[n]) cur = n;
      else if (cur - 1 >= 1 && !vis[cur - 1]) --cur;
      else if (cur * 2 <= n && !vis[cur * 2]) cur *= 2;
      else break;
    }

    tot = 0;
    for (int i = 0; i < (int)ans.size(); ++i) {
      ++tot;
      printf("%d%c", ans[i], tot == n ? '\n' : ' ');
      if (i + 1 < (int)ans.size() && ans[i] / 2 == ans[i + 1] / 2 && ans[i] / 2 >= 1 && !vis[ans[i] / 2]) {
        ++tot;
        printf("%d%c", ans[i] / 2, tot == n ? '\n' : ' ');
      }
    }
  }

  return 0;
}

