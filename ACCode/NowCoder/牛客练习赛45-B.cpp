#include <bits/stdc++.h>

int t;
char map[3][3];

bool Check() {
  for (int i = 0; i < 3; ++i) {
    int cnt = 0;
    for (int j = 0; j < 3; ++j) {
      cnt += (map[i][j] == 'W');
    }
    if (cnt == 3) return true;
  }
  for (int j = 0; j < 3; ++j) {
    int cnt = 0;
    for (int i = 0; i < 3; ++i) {
      cnt += (map[i][j] == 'W');
    }
    if (cnt == 3) return true;
  }
  if (map[0][0] == 'W' && map[1][1] == 'W' && map[2][2] == 'W') return true;
  if (map[0][2] == 'W' && map[1][1] == 'W' && map[2][0] == 'W') return true;
  return false;
}

bool AliceCheck() {
  bool ret = false;
  for (int i = 0; i < 3; ++i) {
    for (int j = 0; j < 3; ++j) {
      if (map[i][j] == '#') {
        map[i][j] = 'W';
        if (Check()) ret = true;
        map[i][j] = '#';
        if (ret) return true;
      }
    }
  }
  return false;
}

bool BobCheck() {
  bool ret = false;
  for (int i = 0; i < 3; ++i) {
    for (int j = 0; j < 3; ++j) {
      if (map[i][j] == 'W') {
        map[i][j] = '#';
        if (!AliceCheck()) ret = true;
        map[i][j] = 'W';
        if (ret) return true;
      }
    }
  }
  return false;
}

int main() {
  scanf("%d", &t);
  for (int cas = 1; cas <= t; ++cas) {
    for (int i = 0; i < 3; ++i) scanf("%s", map[i]);
    if (!AliceCheck()) printf("Bob\n");
    else {
      if (BobCheck()) printf("Emmm\n");
      else printf("Alice\n");
    }
  }
  return 0;
}

