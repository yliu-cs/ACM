#include <bits/stdc++.h>

int days[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

int Zeller(int y, int m, int d) {
  if (m == 1 || m == 2) {
    --y;
    m += 12;
  }
  int c = y / 100;
  y %= 100;
  return ((y + y / 4 + c / 4 - 2 * c + 26 * (m + 1) / 10 + d - 1) % 7 + 7) % 7;
}

bool IsLeapYear(int y) {
  return (!(y % 4) && (y % 100)) || !(y % 400);
}

bool IsValidDay(int y, int m, int d) {
  if (y < 1600 || y > 9999) return false;
  if (m < 1 || m > 12) return false;
  if (d <= 0) return false;
  if (m == 2 && IsLeapYear(y)) return d <= days[m] + 1;
  return d <= days[m];
}

void GetDate(const std::string &date, int &y, int &m, int &d, const std::vector<int> &map) {
  y = m = d = 0;
  for (int i = 0; i < 4; ++i) y = y * 10 + map[date[i] - 'A'];
  for (int i = 5; i < 7; ++i) m = m * 10 + map[date[i] - 'A'];
  for (int i = 8; i < 10; ++i) d = d * 10 + map[date[i] - 'A'];
}

bool Check(const std::vector<int> &map, const std::vector<std::string> &cons) {
  for (std::string c : cons) {
    int y, m, d;
    GetDate(c, y, m, d, map);
    if (!IsValidDay(y, m, d)) return false;
    if (Zeller(y, m, d) != 5) return false;
  }
  return true;
}

int main() {
  int t;
  std::cin >> t;
  for (int cas = 1; cas <= t; ++cas) {
    int n;
    std::cin >> n;
    std::vector<std::string> cons(n);
    for (std::string &s : cons) std::cin >> s;
    std::sort(cons.begin(), cons.end());
    cons.erase(std::unique(cons.begin(), cons.end()), cons.end());
    std::vector<int> map;
    for (int i = 0; i < 10; ++i) map.emplace_back(i);
    bool flag = false;
    do {
      if (Check(map, cons)) {
        flag = true;
        break;
      }
    } while (std::next_permutation(map.begin(), map.end()));
    std::cout << "Case #" << cas << ": ";
    if (flag) {
      for (int i = 0; i < 10; ++i) std::cout << map[i];
    }
    else std::cout << "Impossible";
    std::cout << '\n';
  }
  return 0;
}