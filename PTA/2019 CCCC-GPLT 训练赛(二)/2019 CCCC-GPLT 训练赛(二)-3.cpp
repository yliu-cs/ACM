#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e4 + 5;

bool is_prime[maxn];
vector<int> fac[maxn];

void Sieve() {
  memset(is_prime, true, sizeof(is_prime));
  for (long long i = 2; i < maxn; ++i) {
    if (is_prime[i]) {
      for (long long j = i + i; j < maxn; j += i) {
        is_prime[j] = false;
        fac[j].emplace_back(i);
      }
    }
  }
}

vector<int> ans;

bool Check(int k) {
  ans.clear();
  int sum = 0;
  for (int i = 1; i < k; ++i) {
    if (k % i == 0) {
      sum += i;
      if (i != 1) ans.emplace_back(i);
    }
  }
  return sum == k;
}

int main() {
  ios::sync_with_stdio(false); cin.tie(0);
  Sieve();
  int n, m; cin >> n >> m;
  bool flag = false;
  for (int i = n; i <= m; ++i) {
    if (Check(i)) {
      cout << i << " = " << 1;
      for (auto &it : ans) cout << " + " << it;
      cout << endl;
      flag = true;
    }
  }
  if (!flag) cout << "None" << endl;
  return 0;
}

