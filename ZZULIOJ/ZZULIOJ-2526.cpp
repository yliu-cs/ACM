#include <bits/stdc++.h>
const int maxn = 1e2 + 5;

int n, m;
struct constraint {
  std::string str;
  int a, b;
};
constraint ck[maxn];
bool flag;
std::string ans;

int Check(std::string s, int p) {
  std::map<int, int> cnt;
  for (auto &c : ck[p].str) ++cnt[c - '0'];

  int a = 0, b = 0;
  for (int i = 0; i < (int)s.size(); ++i) {
    if (s[i] == ck[p].str[i]) ++a;
    if (cnt[s[i] - '0']) ++b;
  }
  b -= a;

  if (a > ck[p].a || b > ck[p].b) return 2;
  return a == ck[p].a && b == ck[p].b;
}

void Dfs(int pos, std::string cur) {
  if (pos == m) {
    for (int i = 1; i <= n; ++i) {
      if (Check(cur, i) != 1) return;
    }
    flag = true;
    ans = cur;
  }
  for (int i = 1; i <= n; ++i) {
    if (Check(cur, i) == 2) return;
  }
  for (int i = 0; i <= 9; ++i) {
    Dfs(pos + 1, cur + (char)(i + '0'));
    if (flag) return;
  }
}

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr); std::cout.tie(nullptr);

  std::cin >> n >> m;
  for (int i = 1; i <= n; ++i) std::cin >> ck[i].str >> ck[i].a >> ck[i].b;

  flag = false;
  Dfs(0, "");

  std::cout << ans << '\n';
  return 0;
}

