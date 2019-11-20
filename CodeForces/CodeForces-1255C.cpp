#include <bits/stdc++.h>

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int n;
  std::cin >> n;
  std::vector<int> g[n], cnt(n, 0);
  for (int i = 0; i < n - 2; ++i) {
    int x, y, z;
    std::cin >> x >> y >> z;
    --x;
    --y;
    --z;
    g[x].push_back(y); g[x].push_back(z);
    g[y].push_back(x); g[y].push_back(z);
    g[z].push_back(x); g[z].push_back(y);
    ++cnt[x];
    ++cnt[y];
    ++cnt[z];
  }
  int x, y;
  for (int i = 0; i < n; ++i) {
    if (cnt[i] == 1) {
      x = i;
      break;
    }
  }
  if (cnt[g[x][0]] == 2) {
    y = g[x][0];
  }
  else {
    y = g[x][1];
  }
  std::vector<bool> vis(n, false);
  vis[x] = vis[y] = true;
  std::cout << x + 1 << ' ' << y + 1 << ' ';
  for (int i = 0; i < n - 2; ++i) {
    int z;
    for (int j = 0; j < (int)g[x].size(); ++j) {
      if (!vis[g[x][j]]) {
        z = g[x][j];
      }
    }
    vis[z] = true;
    std::cout << z + 1 << ' ';
    x = y;
    y = z;
  }
  std::cout << '\n';
  return 0;
}

