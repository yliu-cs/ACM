#include <bits/stdc++.h>

const int N = 1e6 + 5;

int next[N];

void GetNext(char p[]) {
  int i = 1, j = 0, plen = std::strlen(p + 1);
  next[1] = 0;
  while (i <= plen) {
    if (j == 0 || p[i] == p[j]) {
      next[++i] = ++j;
    }
    else {
      j = next[j];
    }
  }
}

int KMPCount(char s[], char p[]) {
  int ret = 0, plen = std::strlen(p + 1), slen = std::strlen(s + 1);
  for (int i = 1; i <= plen; ++i) {
    next[i] = 1;
  }
  GetNext(p);
  int i = 1, j = 1;
  while (i <= slen) {
    while (j != 0 && s[i] != p[j]) {
      j = next[j];
    }
    ++i;
    ++j;
    if (j > plen) {
      ++ret;
      printf("%d\n", i - plen);
      j = next[j];
    }
  }
  return ret;
}

char s[N], p[N];
int slen, plen;

int main() {
  scanf("%s%s", s + 1, p + 1);
  slen = std::strlen(s + 1);
  plen = std::strlen(p + 1);
  KMPCount(s, p);
  for (int i = 2; i <= plen + 1; ++i) {
    printf("%d ", next[i] - 1);
  }
  return 0;
}

