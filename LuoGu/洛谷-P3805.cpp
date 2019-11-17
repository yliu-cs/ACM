#include <bits/stdc++.h>

const int N = 2e7 + 5;

char ch[N * 2];
int pl[N * 2];

void Manacher(char s[]) {
  int len = std::strlen(s), l = 0;
  ch[l++] = '$';
  ch[l++] = '#';
  for (int i = 0; i < len; ++i) {
    ch[l++] = s[i];
    ch[l++] = '#';
  }
  ch[l] = '\0';
  int mx = 0, id = 0;
  for (int i = 0; i < l; ++i) {
    pl[i] = mx > i ? std::min(pl[2 * id - i], mx - i) : 1;
    while (ch[i + pl[i]] == ch[i - pl[i]]) {
      ++pl[i];
    }
    if (i + pl[i] > mx) {
      mx = i + pl[i];
      id = i;
    }
  }
}

char s[N];

int main() {
  scanf("%s", s);
  Manacher(s);
  int len = std::strlen(s), ans = 0;
  for (int i = 0; i < 2 * len + 2; ++i) {
    ans = std::max(ans, pl[i] - 1);
  }
  printf("%d\n", ans);
  return 0;
}

