#include <bits/stdc++.h>
void Circle(int x) {
  for (int i = 0; i < x; ++i) std::cout << 'o';
}
void Dot(int x) {
  for (int i = 0; i < x; ++i) std::cout << '.';
}
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int w; std::cin >> w;
  Circle(3); Dot(w);
  Circle(3); Dot(w);
  Circle(3); Dot(w);
  Circle(3);
  std::cout << '\n';

  Dot(2); Circle(1); Dot(w);
  Circle(1); Dot(1); Circle(1); Dot(w);
  Dot(1); Circle(1); Dot(1); Dot(w);
  Circle(1); Dot(1); Circle(1);
  std::cout << '\n';

  Circle(3); Dot(w);
  Circle(1); Dot(1); Circle(1); Dot(w);
  Dot(1); Circle(1); Dot(1); Dot(w);
  Circle(3);
  std::cout << '\n';

  Circle(1); Dot(2); Dot(w);
  Circle(1); Dot(1); Circle(1); Dot(w);
  Dot(1); Circle(1); Dot(1); Dot(w);
  Circle(1); Dot(1); Circle(1);
  std::cout << '\n';

  Circle(3); Dot(w);
  Circle(3); Dot(w);
  Circle(3); Dot(w);
  Circle(3);
  std::cout << '\n';
  return 0;
}
