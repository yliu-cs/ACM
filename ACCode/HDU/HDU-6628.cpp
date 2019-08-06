#include <bits/stdc++.h>
const int maxn = 25;

int t;
int n, k;
bool suc;
int diff[maxn];
std::set<int> vis;

void Dfs(int pos, int num, int min, int max) {
  if (max - min >= n || vis.find(num) != vis.end()) return;
  if (pos == n) {
    --k;
    if (k == 0) {
      int num = std::abs(min) + 1;
      for (int i = 0; i < pos; ++i) {
        num += diff[i];
        if (i != 0) printf(" ");
        printf("%d", num);
      }
      printf("\n");
      suc = true;
    }
    return;
  }
  vis.emplace(num);
  for (int i = 1 - n; i <= n - 1; ++i) {
    diff[pos] = i;
    Dfs(pos + 1, num + i, std::min(min, num + i), std::max(max, num + i));
    if (suc) return;
  }
  vis.erase(num);
}

int main() {
  scanf("%d", &t);
  for (int cas = 1; cas <= t; ++cas) {
    scanf("%d%d", &n, &k);
    suc = false;
    vis.clear();
    diff[0] = 0;
    Dfs(1, 0, 0, 0);
  }
  return 0;
}