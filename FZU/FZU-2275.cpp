#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

const int N = 1e5 + 5;

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
      j = next[j];
    }
  }
  return ret;
}

int t;
char s[N], p[N];
int slen, plen;

int main() {
  scanf("%d", &t);
  while (t--) {
    scanf("%s%s", s + 1, p + 1);
    slen = std::strlen(s + 1);
    plen = std::strlen(p + 1);
    if (p[1] == '0' && plen == 1) {
      printf("Alice\n");
      continue;
    }
    if (slen < plen) {
      printf("Bob\n");
      continue;
    }
    if (KMPCount(s, p)) {
      printf("Alice\n");
      continue;
    }
    std::reverse(p + 1, p + plen + 1);
    if (KMPCount(s, p)) {
      printf("Alice\n");
    }
    else {
      printf("Bob\n");
    }
  }
  return 0;
}

