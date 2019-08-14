#include <bits/stdc++.h>
const int maxn = 1e5 + 5;
struct team {
  std::string name;
  int n, t;
};
bool operator < (const team &k1, const team &k2) {
  if (k1.n == k2.n) return k1.t < k2.t;
  return k1.n > k2.n;
}
team a[maxn];
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int t;
  std::cin >> t;
  while (t--) {
    int n, d;
    std::cin >> n >> d;
    for (int i = 1; i <= n; ++i) std::cin >> a[i].name >> a[i].n >> a[i].t;
    std::sort(a + 1, a + n + 1);
    if (n * d % 10 != 5) {
      std::cout << "Quailty is very great\n";
      continue;
    }
    int pos = (n * d + 9) / 10;
    std::cout << a[pos].name << '\n';
  }
  return 0;
}
