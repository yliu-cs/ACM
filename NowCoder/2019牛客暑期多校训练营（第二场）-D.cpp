#include <bits/stdc++.h>
const int maxn = 1e2 + 5;
int n, k;
int w[maxn];
struct node {
  long long v;
  std::bitset<maxn> g;
  bool operator < (const node &k) const {
    return v > k.v;
  }
};
char s[maxn];
std::bitset<maxn> g[maxn];
int main() {
  scanf("%d%d", &n, &k);
  for (int i = 1; i <= n; ++i) scanf("%d", &w[i]);
  for (int i = 1; i <= n; ++i) {
    scanf("%s", s + 1);
    for (int j = 1; j <= n; ++j) g[i][j] = (s[j] == '1');
  }
  std::priority_queue<node> que;
  std::bitset<maxn> ori; ori.reset();
  que.push((node){0ll, ori});
  while (!que.empty()) {
    node cur = que.top();
    que.pop();
    --k;
    if (!k) {
      printf("%lld\n", cur.v);
      return 0;
    }
    int pos = 0;
    std::bitset<maxn> vis = cur.g;
    for (int i = 1; i <= n; ++i)
      if (vis[i]) pos = i;
    for (int i = pos + 1; i <= n; ++i) {
      if ((g[i] & vis) == vis) {
        vis[i] = 1;
        que.push((node){cur.v + 1ll * w[i], vis});
        vis[i] = 0;
      }
    }
  }
  printf("-1\n");
  return 0;
}
