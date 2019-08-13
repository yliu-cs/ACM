#include <bits/stdc++.h>
const int maxn = 1e4 + 5;
int n, m;
int tot;
char map[maxn];
int code[26], sz[26];
int pre[maxn];
std::vector<int> next[maxn];
std::string ans;
bool TopoSort() {
  std::queue<int> que;
  for (int i = 0; i < tot; ++i) {
    if (pre[i] == 0) que.push(i);
  }
  while (!que.empty()) {
    int cur = que.front();
    que.pop();
    ans += map[cur];
    for (int &v : next[cur]) {
      --pre[v];
      if (pre[v] == 0) que.push(v);
    }
  }
  return ans.size() == n;
}
int main() {
  std::cin >> n >> m;
  memset(code, -1, sizeof(code));
  m = m * (m - 1) / 2;
  for (int i = 1; i <= m; ++i) {
    char c1, c2;
    int len;
    std::cin >> c1 >> c2 >> len;
    std::string s;
    std::cin.get();
    std::getline(std::cin, s);
    int cnt[2] = {0, 0};
    for (int i = 0; i < len; ++i) ++cnt[s[i] == c2];
    if ((code[c1 - 'a'] != -1 && cnt[0] != sz[c1 - 'a']) || (code[c2 - 'a'] != -1 && cnt[1] != sz[c2 - 'a'])) {
      std::cout << -1 << '\n';
      return 0;
    }
    sz[c1 - 'a'] = cnt[0];
    sz[c2 - 'a'] = cnt[1];
    int idx[2] = {0, 0};
    if (code[c1 - 'a'] == -1) {
      idx[0] = tot;
      code[c1 - 'a'] = idx[0];
      tot += cnt[0];
    }
    else idx[0] = code[c1 - 'a'];
    if (code[c2 - 'a'] == -1) {
      idx[1] = tot;
      code[c2 - 'a'] = idx[1];
      tot += cnt[1];
    }
    else idx[1] = code[c2 - 'a'];
    for (int i = 0; i < len; ++i) {
      if (i == 0) {
        if (s[i] == c1) map[idx[0]++] = c1;
        else map[idx[1]++] = c2;
        continue;
      }
      if (s[i] == c1) {
        if (s[i - 1] == c1) {
          next[idx[0] - 1].push_back(idx[0]);
          map[idx[0]] = c1;
          ++pre[idx[0]];
        }
        else {
          next[idx[1] - 1].push_back(idx[0]);
          map[idx[0]] = c1;
          ++pre[idx[0]];
        }
        ++idx[0];
      }
      else {
        if (s[i - 1] == c1) {
          next[idx[0] - 1].push_back(idx[1]);
          map[idx[1]] = c2;
          ++pre[idx[1]];
        }
        else {
          next[idx[1] - 1].push_back(idx[1]);
          map[idx[1]] = c2;
          ++pre[idx[1]];
        }
        ++idx[1];
      }
    }
  }
  if (TopoSort()) std::cout << ans << '\n';
  else std::cout << -1 << '\n';
  return 0;
}
