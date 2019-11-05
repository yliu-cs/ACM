#include <bits/stdc++.h>
#include <bits/extc++.h>

std::set<char> set, num;
std::string str;
int max;
int cnt[26];
int map[26][26];
bool vis[26];
bool ans[26];

int Get(char x) {
  return x - 'a';
}

bool Check(char k) {
  return set.find(k) == set.end();
}

void Dfs(int idx) {
  if (idx == 26) {
    int sum = 0;
    for (int i = 0; i < 26; ++i) {
      for (int j = 0; j < 26; ++j) {
        if (vis[i] ^ vis[j] == 1) sum += map[i][j];
      }
    }
    if (sum > max) {
      max = sum;
      for (int i = 0; i < 26; ++i) ans[i] = vis[i];
    }
    return;
  }
  if (num.find(idx) != num.end()) {
    Dfs(idx + 1);
    return;
  }
  Dfs(idx + 1);
  vis[idx] = true;
  Dfs(idx + 1);
  vis[idx] = false;
}

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr); std::cout.tie(nullptr);

  freopen("consonant.in", "r", stdin);
  freopen("consonant.out", "w", stdout);
 
  set.emplace('a');
  set.emplace('e');
  set.emplace('i');
  set.emplace('o');
  set.emplace('u');
  set.emplace('w');
  set.emplace('y');
  for (auto &v : set) num.emplace(v - 'a');

  std::cin >> str;
  for (int i = 1; i < (int)str.size(); ++i) {
    if (Check(str[i]) && Check(str[i - 1])) {
      ++map[Get(str[i - 1])][Get(str[i])];
    }
  }

  Dfs(0);

  for (char &c : str) {
    if (ans[Get(c)]) c = toupper(c);
    std::cout << c;
  }
  
  return 0;
}

