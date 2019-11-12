#include <bits/stdc++.h>

const int N = 2e5 + 5;
const int L1 = 2e5 + 5;
const int L2 = 2e6 + 5;
const int C = 26;

int tot, trie[L1][C], cnt[L1 * C], map[L1 * C], fail[L1 * C];
std::vector<int> g[L1 * C];

int Get(char x) {
  return (int)(x - 'a');
}

void Insert(char s[], int idx) {
  int len = std::strlen(s), cur = 0;
  for (int i = 0; i < len; ++i) {
    int x = Get(s[i]);
    if (trie[cur][x] == 0) {
      trie[cur][x] = ++tot;
    }
    cur = trie[cur][x];
  }
  map[idx] = cur;
}

void GetFail() {
  std::queue<int> que;
  for (int i = 0; i < C; ++i) {
    if (trie[0][i] != 0) {
      fail[trie[0][i]] = 0;
      que.push(trie[0][i]);
    }
  }
  while (!que.empty()) {
    int cur = que.front();
    que.pop();
    for (int i = 0; i < C; ++i) {
      if (trie[cur][i] != 0) {
        fail[trie[cur][i]] = trie[fail[cur]][i];
        que.push(trie[cur][i]);
      }
      else {
        trie[cur][i] = trie[fail[cur]][i];
      }
    }
  }
}

void BuildFail() {
  for (int i = 1; i <= tot; ++i) {
    g[fail[i]].emplace_back(i);
  }
}

void Query(char s[]) {
  int len = std::strlen(s), cur = 0;
  for (int i = 0; i < len; ++i) {
    int x = Get(s[i]);
    cur = trie[cur][x];
    ++cnt[cur];
  }
}

void Dfs(int u) {
  for (auto &v : g[u]) {
    Dfs(v);
    cnt[u] += cnt[v];
  }
}

int n;
char s[L1], str[L2];

int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i) {
    scanf("%s", s);
    Insert(s, i);
  }
  GetFail();
  BuildFail();
  scanf("%s", str);
  Query(str);
  Dfs(0);
  for (int i = 1; i <= n; ++i) {
    printf("%d\n", cnt[map[i]]);
  }
  return 0;
}

