#include <bits/stdc++.h>

const int N = 5e5 + 5;

char s[N];

int main() {
  scanf("%s", s + 1);
  int len = std::strlen(s + 1);
  char min = 'z';
  for (int i = 1; i <= len; ++i) {
    if (i == 1) {
      printf("Mike\n");
      min = std::min(min, s[i]);
      continue;
    }
    if (min < s[i]) {
      printf("Ann\n");
    }
    else {
      printf("Mike\n");
    }
    min = std::min(min, s[i]);
  }
  return 0;
}

