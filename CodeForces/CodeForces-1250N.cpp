#include <bits/stdc++.h>

const int N = 2e5 + 5;

int t, n;
std::vector<int> vertex;
std::vector<std::pair<int, int>> edge;
std::map<std::pair<int, int>, int> map;
std::vector<int> g[N];

int Hash(int x) {
  return std::lower_bound(vertex.begin(), vertex.end(), x) - vertex.begin() + 1;
}

bool vis[N];
std::vector<std::pair<int, int>> ans;

void Mark(int u) {
  vis[u] = true;
  for (auto &v : g[u]) {
    if (vis[v]) {
      continue;
    }
    Mark(v);
  }
}

bool used[N];
std::set<std::pair<int, int>> set;

void Dfs(int u) {
  used[u] = true;
  for (auto &v : g[u]) {
    set.insert({std::min(u, v), std::max(u, v)});
    if (used[v]) {
      continue;
    }
    Dfs(v);
  }
}

int pre[N];

int Find(int x) {
  if (pre[x] == x) {
    return x;
  }
  return pre[x] = Find(pre[x]);
}

void Union(int x, int y) {
  pre[Find(x)] = Find(y);
}

int main() {
  scanf("%d", &t);
  while (t--) {
    scanf("%d", &n);
    vertex.clear();
    edge.clear();
    for (int i = 1; i <= n; ++i) {
      int u, v;
      scanf("%d%d", &u, &v);
      vertex.push_back(u);
      vertex.push_back(v);
      edge.push_back({u, v});
    }
    std::sort(vertex.begin(), vertex.end());
    vertex.erase(std::unique(vertex.begin(), vertex.end()), vertex.end());
    for (auto &e : edge) {
      e.first = Hash(e.first);
      e.second = Hash(e.second);
    }
    for (int i = 1; i <= (int)vertex.size(); ++i) {
      g[i].clear();
      vis[i] = false;
      used[i] = false;
      pre[i] = i;
    }
    map.clear();
    ans.clear();
    for (int i = 0; i < (int)edge.size(); ++i) {
      std::pair<int, int> e = edge[i];
      if (map[{e.first, e.second}] || map[{e.second, e.first}]) {
        continue;
      }
      g[e.first].push_back(e.second);
      g[e.second].push_back(e.first);
      map[{e.first, e.second}] = map[{e.second, e.first}] = i + 1;
    }
    Mark(1);
    for (int i = 1; i <= (int)vertex.size(); ++i) {
      if (vis[i]) {
        continue;
      }
      if ((int)g[i].size() == 1) {
        ans.push_back({map[{i, g[i][0]}], i});
        Mark(i);
      }
    }
    for (int i = 1; i <= (int)vertex.size(); ++i) {
      if (vis[i]) {
        continue;
      }
      set.clear();
      Dfs(i);
      for (auto &e : set) {
        if (Find(e.first) == Find(e.second)) {
          ans.push_back({map[{e.first, e.second}], e.first});
          break;
        }
        Union(e.first, e.second);
      }
      Mark(i);
    }
    printf("%d\n", (int)ans.size());
    for (auto &pr : ans) {
      printf("%d %d %d\n", pr.first, vertex[pr.second - 1], vertex[0]);
    }
  }
  return 0;
}

