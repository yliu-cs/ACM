#include <bits/stdc++.h>

const int N = 1e6 + 5;
const int C = 26;

int trie[N][C], tot, cnt[N], fail[N];

int Get(char x) {
  return (int)(x - 'a');
}

void Insert(char s[]) {
  int len = std::strlen(s + 1), cur = 0;
  for (int i = 1; i <= len; ++i) {
    int x = Get(s[i]);
    if (trie[cur][x] == 0) {
      trie[cur][x] = ++tot;
    }
    cur = trie[cur][x];
  }
  ++cnt[cur];
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

int Query(char s[]) {
  int len = std::strlen(s + 1), cur = 0, ret = 0;
  for (int i = 1; i <= len; ++i) {
    int x = Get(s[i]);
    cur = trie[cur][x];
    for (int j = cur; j && cnt[j] != -1; j = fail[j]) {
      ret += cnt[j];
      cnt[j] = -1;
    }
  }
  return ret;
}

int n;
char s[N];

int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i) {
    scanf("%s", s + 1);
    Insert(s);
  }
  GetFail();
  scanf("%s", s + 1);
  printf("%d\n", Query(s));
  return 0;
}

