#include <bits/stdc++.h>

const int N = 2e4 + 5;
const int C = 105;

int que[N];

int MonoQueue(int arr[], int n, int k) {
  int head = 1, tail = 0, ret = 0;
  for (int i = 1; i < k; ++i) {
    while (head <= tail && arr[que[tail]] >= arr[i]) {
      --tail;
    }
    que[++tail] = i;
  }
  for (int i = k; i <= n; ++i) {
    while (head <= tail && arr[que[tail]] >= arr[i]) {
      --tail;
    }
    que[++tail] = i;
    while (que[head] <= i - k) {
      ++head;
    }
    ret = std::max(ret, arr[que[head]]);
  }
  return ret;
}

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

int k;

int main() {
  scanf("%d%d", &n, &k);
  for (int i = 1; i <= n; ++i) {
    scanf("%d", &ch[i]);
  }
  Build();
  printf("%d\n", MonoQueue(height, n, k - 1));
  return 0;
}

