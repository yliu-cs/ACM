#include <bits/stdc++.h>

const int N = 2e2 + 5;
const int L1 = 75;
const int L2 = 1e6 + 5;
const int C = 26;

int tot, trie[N * L1][C], cnt[N * L1], map[N * L1], fail[N * L1];

int Get(char x) {
  return (int)(x - 'a');
}

void Insert(char s[], int idx) {
  int len = std::strlen(s + 1), cur = 0;
  for (int i = 1; i <= len; ++i) {
    int x = Get(s[i]);
    if (trie[cur][x] == 0) {
      trie[cur][x] = ++tot;
    }
    cur = trie[cur][x];
  }
  ++cnt[cur];
  map[cur] = idx;
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

int rec[N];

void Query(char s[]) {
  int len = std::strlen(s + 1), cur = 0;
  for (int i = 1; i <= len; ++i) {
    int x = Get(s[i]);
    cur = trie[cur][x];
    for (int j = cur; j && cnt[j] != -1; j = fail[j]) {
      rec[map[j]] += cnt[j];
    }
  }
}

int n, ans;
char s[N][L1], str[L2];

int main() {
  while (~scanf("%d", &n) && n) {
    tot = 0;
    for (int i = 0; i < N * L1; ++i) {
      for (int j = 0; j < C; ++j) {
        trie[i][j] = 0;
      }
      cnt[i] = fail[i] = map[i] = 0;
    }
    for (int i = 1; i <= n; ++i) {
      scanf("%s", s[i] + 1);
      Insert(s[i], i);
      rec[i] = 0;
    }
    GetFail();
    scanf("%s", str + 1);
    Query(str);
    ans = 0;
    for (int i = 1; i <= n; ++i) {
      ans = std::max(ans, rec[i]);
    }
    printf("%d\n", ans);
    for (int i = 1; i <= n; ++i) {
      if (rec[i] == ans) {
        printf("%s\n", s[i] + 1);
      }
    }
  }
  return 0;
}

