#include <bits/stdc++.h>

const int N = 6;
const int L = 2e6 + 5;
const int C = 26;

int t;
char s[L];
bool flag[N][C];
char c[N] = {'h', 'a', 'r', 'b', 'i', 'n'};
bool ans;

int main() {
  scanf("%d", &t);
  while (t--) {
    for (int i = 0; i < N; ++i) {
      for (int j = 0; j < C; ++j) {
        flag[i][j] = false;
      }
    }
    for (int i = 0; i < N; ++i) {
      scanf("%s", s);
      int len = std::strlen(s);
      for (int j = 0; j < len; ++j) {
        flag[i][s[j] - 'a'] = true;
      }
    }
    std::sort(c, c + N);
    ans = false;
    do {
      bool f = true;
      for (int i = 0; i < N; ++i) {
        if (!flag[i][c[i] - 'a']) {
          f = false;
          break;
        }
      }
      if (f) {
        ans = true;
        break;
      }
    } while (std::next_permutation(c, c + N));
    if (ans) {
      printf("Yes\n");
    }
    else {
      printf("No\n");
    }
  }
  return 0;
}

