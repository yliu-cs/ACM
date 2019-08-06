#include <bits/stdc++.h>
const int maxn = 1e5 + 5;

char str[maxn];
int len;
int first[26];
int last[26];
struct node {
  int next[26];
  node() {
    memset(next, -1, sizeof(next));
  }
};
node tree[maxn];
char s[maxn];

void Build() {
  for (int i = 0; i < 26; ++i) {
    first[i] = -1;
    last[i] = -1;
  }
  for (int i = len - 1; i >= 0; --i) {
    int pos = str[i] - 'a';
    if (last[pos] == -1) last[pos] = i;
    for (int j = 0; j < 26; ++j) {
      if (first[j] == -1) continue;
      if (tree[i].next[j] == -1) tree[i].next[j] = first[j];
    }
    first[pos] = i;
  }
}

int main() {
  scanf("%s", str);
  len = strlen(str);
  Build();

  int n; scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    scanf("%s", s);
    bool flag = true;
    int cur = first[s[0] - 'a'], s_len = strlen(s);
    if (cur == -1) {
      printf("NO\n");
      continue;
    }
    for (int i = 1; i < s_len; ++i) {
      int pos = s[i] - 'a';
      cur = tree[cur].next[pos];
      if (cur == -1) {
        flag = false;
        break;
      }
    }
    if (flag) printf("YES\n");
    else printf("NO\n");
  }
  return 0;
}

