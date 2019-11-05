#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false); cin.tie(0);
  int n, m; cin >> n >> m;
  cout << __gcd(n, m) << " " << n * m / __gcd(n, m);
  return 0;
}

