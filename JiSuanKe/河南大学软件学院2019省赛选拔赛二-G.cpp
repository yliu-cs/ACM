#include <bits/stdc++.h>
const int maxn = 1e6 + 5;

int n;
int l_s[maxn], r_s[maxn];
int sz[maxn], val[maxn];
int ans;

bool Check(int l, int r) {
  if (val[l] != val[r]) return false;
  if (l == -1 && r == -1) return true;
  if (l == -1 || r == -1) return false;
  return Check(l_s[l], r_s[r]) && Check(r_s[l], l_s[r]);
}

int Dfs(int o) {
  if (o == -1) return 0;
  sz[o] = Dfs(l_s[o]) + Dfs(r_s[o]) + 1;
  return sz[o];
}

void Solve(int o) {
  if (o == -1) return;
  if (sz[l_s[o]] == sz[r_s[o]] && Check(l_s[o], r_s[o])) {
    ans = std::max(ans, sz[o]);
    return;
  }
  Solve(l_s[o]); Solve(r_s[o]);
}

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr); std::cout.tie(nullptr);

  scanf("%d", &n);
  for (int i = 1; i <= n; ++i) scanf("%d", &val[i]);
  for (int i = 1, l, r; i <= n; ++i) {
    scanf("%d%d", &l, &r);
    l_s[i] = l;
    r_s[i] = r;
  }

  Dfs(1);
  Solve(1);

  printf("%d\n", ans);
  return 0;
}
