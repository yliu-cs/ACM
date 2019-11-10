#include <bits/stdc++.h>

const int N = 1e5 + 5;

int next[N], extend[N];

void GetNext(char s[]) {
  int slen = std::strlen(s), j = 0;
  next[0] = slen;
  while (j + 1 < slen && s[j] == s[j + 1]) {
    ++j;
  }
  next[1] = j;
  for (int i = 2, k = 1; i < slen; ++i) {
    if (i + next[i - k] < next[k] + k) {
      next[i] = next[i - k];
    }
    else {
      j = std::max(0, next[k] + k - i);
      while (i + j < slen && s[i + j] == s[j]) {
        ++j;
      }
      next[i] = j;
      k = i;
    }
  }
}

void ExKMP(char s[], char p[]) {
  int slen = std::strlen(s), plen = std::strlen(p);
  GetNext(s);
  int j = 0;
  while (j < plen && j < slen && s[j] == p[j]) {
    ++j;
  }
  extend[0] = j;
  for (int i = 1, k = 0; i < plen; ++i) {
    if (i + next[i - k] < extend[k] + k) {
      extend[i] = next[i - k];
    }
    else {
      j = std::max(0, extend[k] + k - i);
      while (i + j < plen && j < slen && p[i + j] == s[j]) {
        ++j;
      }
      extend[i] = j;
      k = i;
    }
  }
}

char a[N], b[N];

int main() {
  scanf("%s%s", a, b);
  ExKMP(b, a);
  int alen = std::strlen(a), blen = std::strlen(b);
  for (int i = 0; i < blen; ++i) {
    printf("%d ", next[i]);
  }
  printf("\n");
  for (int i = 0; i < alen; ++i) {
    printf("%d ", extend[i]);
  }
  printf("\n");
  return 0;
}

