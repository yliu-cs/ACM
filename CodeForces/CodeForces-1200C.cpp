// Author: Tony5t4rk Time: 2019-08-11 21:05:43 
#include <bits/stdc++.h>

int main() {
  long long n, m, q;
  std::cin >> n >> m >> q;
  long long gcd = std::__gcd(n, m);
  long long k1 = n / gcd, k2 = m / gcd;
  while (q--) {
    long long a, b, c, d;
    std::cin >> a >> b >> c >> d;
    if (a == 2 && c == 1) std::swap(b, d);
    if (a == 1 && c == 1) {
      long long q1 = (b + k1 - 1) / k1, q2 = (d + k1 - 1) / k1;
      std::cerr << q1 << ' ' << q2 << '\n';
      if (q1 == q2) std::cout << "YES\n";
      else std::cout << "NO\n";
    }
    else if (a == 2 && c == 2) {
      long long q1 = (b + k2 - 1) / k2, q2 = (d + k2 - 1) / k2;
      std::cerr << q1 << ' ' << q2 << '\n';
      if (q1 == q2) std::cout << "YES\n";
      else std::cout << "NO\n";
    }
    else {
      long long q1 = (b + k1 - 1) / k1, q2 = (d + k2 - 1) / k2;
      std::cerr << q1 << ' ' << q2 << '\n';
      if (q1 == q2) std::cout << "YES\n";
      else std::cout << "NO\n";
    }
  }
  return 0;
}

