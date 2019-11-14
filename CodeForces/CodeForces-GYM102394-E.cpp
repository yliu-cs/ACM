#include <bits/stdc++.h>

const int N = 1e6 + 5;

template <typename t>
inline bool Read(t &ret) {
  char c; int sgn;
  if (c = getchar(), c == EOF) return false;
  while (c != '-' && (c < '0' || c > '9')) c = getchar();
  sgn = (c == '-') ? -1 : 1;
  ret = (c == '-') ? 0 : (c - '0');
  while (c = getchar(), c >= '0' && c <= '9') ret = ret * 10 + (c - '0');
  ret *= sgn;
  return true;
}

int t, n, opt[N], uni[N][2];
long long max, len[N], cnt[N];
std::vector<int> s[N], arr;
std::map<int, long long> map;

int main() {
  Read(t);
  while (t--) {
    Read(n);
    for (int i = 1; i <= n; ++i) {
      Read(opt[i]);
      cnt[i] = 0;
      if (opt[i] == 1) {
        Read(len[i]);
        s[i].clear();
        for (int j = 1; j <= len[i]; ++j) {
          int x;
          Read(x);
          s[i].emplace_back(x);
        }
      }
      else {
        Read(uni[i][0]);
        Read(uni[i][1]);
        len[i] = len[uni[i][0]] + len[uni[i][1]];
      }
    }
    cnt[n] = 1;
    for (int i = n; i > 0; --i) {
      if (opt[i] == 2) {
        cnt[uni[i][0]] += cnt[i];
        cnt[uni[i][1]] += cnt[i];
      }
    }
    map.clear();
    max = 0;
    for (int i = 1; i <= n; ++i) {
      if (opt[i] == 1) {
        for (auto &v : s[i]) {
          map[v] += cnt[i];
          max = std::max(max, map[v]);
        }
      }
    }
    if (2ll * max > len[n]) {
      printf("%lld\n", 2ll * (len[n] - max));
    }
    else {
      printf("%lld\n", len[n]);
    }
  }
  return 0;
}

