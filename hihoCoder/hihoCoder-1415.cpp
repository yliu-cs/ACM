#include <bits/stdc++.h>

const int N = 2e5 + 5;
const int C = 256;

int n, ch[N];
int cnta[N], cntb[N], a[N], b[N], tsa[N];
int rk[N], sa[N], height[N];

void Build() {
  for (int i = 0; i < C; ++i) {
    cnta[i] = 0;
  }
  for (int i = 1; i <= n; ++i) {
    ++cnta[ch[i]];
  }
  for (int i = 1; i < C; ++i) {
    cnta[i] += cnta[i - 1];
  }
  for (int i = n; i > 0; --i) {
    sa[cnta[ch[i]]--] = i;
  }
  rk[sa[1]] = 1;
  for (int i = 2; i <= n; ++i) {
    rk[sa[i]] = rk[sa[i - 1]];
    if (ch[sa[i]] != ch[sa[i - 1]]) {
      ++rk[sa[i]];
    }
  }
  for (int l = 1; rk[sa[n]] < n; l <<= 1) {
    for (int i = 0; i <= n; ++i) {
      cnta[i] = cntb[i] = 0;
    }
    for (int i = 1; i <= n; ++i) {
      a[i] = rk[i];
      ++cnta[a[i]];
      if (i + l <= n) {
        b[i] = rk[i + l];
      }
      else {
        b[i] = 0;
      }
      ++cntb[b[i]];
    }
    for (int i = 1; i <= n; ++i) {
      cntb[i] += cntb[i - 1];
    }
    for (int i = n; i > 0; --i) {
      tsa[cntb[b[i]]--] = i;
    }
    for (int i = 1; i <= n; ++i) {
      cnta[i] += cnta[i - 1];
    }
    for (int i = n; i > 0; --i) {
      sa[cnta[a[tsa[i]]]--] = tsa[i];
    }
    rk[sa[1]] = 1;
    for (int i = 2; i <= n; ++i) {
      rk[sa[i]] = rk[sa[i - 1]];
      if (a[sa[i]] != a[sa[i - 1]] || b[sa[i]] != b[sa[i - 1]]) {
        ++rk[sa[i]];
      }
    }
  }
  for (int i = 1, j = 0; i <= n; ++i) {
    if (j != 0) {
      --j;
    }
    while (ch[i + j] == ch[sa[rk[i] - 1] + j]) {
      ++j;
    }
    height[rk[i]] = j;
  }
}

char s1[N], s2[N], s[N];
int len1, len2, ans;

int main() {
  scanf("%s", s1 + 1);
  scanf("%s", s2 + 1);
  len1 = std::strlen(s1 + 1);
  len2 = std::strlen(s2 + 1);
  n = len1 + len2 + 1;
  for (int i = 1; i <= len1; ++i) {
    s[i] = s1[i];
  }
  s[len1 + 1] = '#';
  for (int i = 1; i <= len2; ++i) {
    s[len1 + 1 + i] = s2[i];
  }
  s[n + 1] = '\0';
  for (int i = 1; i <= n; ++i) {
    ch[i] = (int)s[i];
  }
  Build();
  for (int i = 2; i <= n; ++i) {
    if (std::max(sa[i], sa[i - 1]) > len1 && std::min(sa[i], sa[i - 1]) <= len1) {
      ans = std::max(ans, height[i]);
    }
  }
  printf("%d\n", ans);
  return 0;
}

