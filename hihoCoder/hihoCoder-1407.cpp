#include <bits/stdc++.h>

const int N = 1e5 + 5;
const int C = 1e3 + 5;
const int INF = 1e9 + 5;

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

bool Check(int x) {
  int min = INF, max = -INF;
  for (int i = 1; i <= n; ++i) {
    if (height[i] < x) {
      min = sa[i];
      max = sa[i];
    }
    else {
      min = std::min(min, sa[i]);
      max = std::max(max, sa[i]);
      if (max - min >= x) {
        return true;
      }
    }
  }
  return false;
}

int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i) {
    scanf("%d", &ch[i]);
  }
  Build();
  int l = 0, r = n, ans;
  while (l <= r) {
    int m = (l + r) / 2;
    if (Check(m)) {
      ans = m;
      l = m + 1;
    }
    else {
      r = m - 1;
    }
  }
  printf("%d\n", ans);
  return 0;
}

