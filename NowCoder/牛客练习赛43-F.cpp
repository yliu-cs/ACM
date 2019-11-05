#include <bits/stdc++.h>
const int maxn = 1e2 + 5;

int t;
long long k, q, n, m;
long long get;
std::vector<long long> fac;
std::vector<int> prime = {2, 3, 5, 7, 11, 13, 17, 19};

void Dfs(int pos, long long mul, int cnt) {
  if (pos >= (int)fac.size()) {
    if (cnt > 0) {
      if (cnt & 1) get -= n / mul;
      else get += n / mul;
    }
    return;
  }
  Dfs(pos + 1, mul * fac[pos], cnt + 1);
  Dfs(pos + 1, mul, cnt);
}

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr); std::cout.tie(nullptr);

  std::cin >> t;
  for (int cas = 1; cas <= t; ++cas) {
    std::cin >> k >> q >> n >> m;
    if (k == 0 || n < q) {
      std::cout << "QAQ" << '\n';
      continue;
    }
    else if (k >= q) {
      std::cout << "Yes" << '\n';
      continue;
    }

    fac.clear();
    for (auto &p : prime) {
      if (p <= m) fac.push_back(p);
      else break;
    }

    get = n;
    Dfs(0, 1, 0);
    k += get;

    if (k > 0 && k > q) std::cout << "Yes" << '\n';
    else std::cout << "QAQ" << '\n';
  }
  return 0;
}
