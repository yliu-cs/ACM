// 1582年10月4日之后
int Zeller(int y, int m, int d) {
  if (m == 1 || m == 2) {
    --y;
    m += 12;
  }
  int c = y / 100;
  y %= 100;
  return ((y + y / 4 + c / 4 - 2 * c + 26 * (m + 1) / 10 + d - 1) % 7 + 7) % 7;
}