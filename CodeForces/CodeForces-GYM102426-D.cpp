#include <bits/stdc++.h>

std::map<std::string, double> map;

void Init() {
  map["H"] = 1.008; map["He"] = 4.003; map["Li"] = 6.941; map["Be"] = 9.012; map["B"] = 10.81;
  map["C"] = 12.01; map["N"] = 14.01; map["O"] = 16.00; map["F"] = 19.00; map["Ne"] = 20.18;
  map["Na"] = 22.99; map["Mg"] = 24.31; map["Al"] = 26.98; map["Si"] = 28.09; map["P"] = 30.97;
  map["S"] = 32.07; map["Cl"] = 35.45; map["Ar"] = 39.95; map["K"] = 39.10; map["Ca"] = 40.08;
  map["Sc"] = 44.96; map["Ti"] = 47.88; map["V"] = 50.94; map["Cr"] = 52.00; map["Mn"] = 54.94;
  map["Fe"] = 55.85; map["Co"] = 58.93; map["Ni"] = 58.69; map["Cu"] = 63.55; map["Zn"] = 65.39;
  map["Ga"] = 69.72; map["Ge"] = 72.59; map["As"] = 74.92; map["Se"] = 78.96; map["Br"] = 79.90;
  map["Kr"] = 83.80; map["Rb"] = 85.47; map["Sr"] = 87.62; map["Y"] = 88.91; map["Zr"] = 91.22;
  map["Nb"] = 92.91; map["Mo"] = 95.94; map["Tc"] = 97.91; map["Ru"] = 101.1; map["Rh"] = 102.9;
  map["Pd"] = 106.4; map["Ag"] = 107.9; map["Cd"] = 112.4; map["In"] = 114.8; map["Sn"] = 118.7;
  map["Sb"] = 121.8; map["Te"] = 127.6; map["I"] = 126.9; map["Xe"] = 131.3; map["Cs"] = 132.9;
  map["Ba"] = 137.3; map["La"] = 138.9; map["Ce"] = 140.1; map["Pr"] = 140.9; map["Nd"] = 144.2;
  map["Pm"] = 144.9; map["Sm"] = 150.4; map["Eu"] = 152.0; map["Gd"] = 157.3; map["Tb"] = 158.9;
  map["Dy"] = 162.5; map["Ho"] = 164.9; map["Er"] = 167.3; map["Tm"] = 168.9; map["Yb"] = 173.0;
  map["Lu"] = 175.0; map["Hf"] = 178.5; map["Ta"] = 180.9; map["W"] = 183.9; map["Re"] = 186.2;
  map["Os"] = 190.2; map["Ir"] = 192.2; map["Pt"] = 195.1; map["Au"] = 197.0; map["Hg"] = 200.6;
  map["Tl"] = 204.4; map["Pb"] = 207.2; map["Bi"] = 209.0; map["Po"] = 209.0; map["At"] = 210.0;
  map["Rn"] = 222.0; map["Fr"] = 223.0; map["Ra"] = 226.0; map["Ac"] = 227.0; map["Th"] = 232.0;
  map["Pa"] = 231.0; map["U"] = 238.0; map["Np"] = 237.1; map["Pu"] = 244.1; map["Am"] = 243.1;
  map["Cm"] = 247.1; map["Bk"] = 247.1; map["Cf"] = 252.1; map["Es"] = 252.1; map["Fm"] = 257.1;
  map["Md"] = 258.1; map["No"] = 259.1; map["Lr"] = 262.1; map["Rf"] = 265.1; map["Db"] = 268.1;
  map["Sg"] = 271.1; map["Bh"] = 270.1; map["Hs"] = 277.2; map["Mt"] = 276.2; map["Ds"] = 281.2;
  map["Rg"] = 280.2; map["Cn"] = 285.2; map["Nh"] = 284.2; map["Fl"] = 289.2; map["Mc"] = 288.2;
  map["Lv"] = 293.2; map["Ts"] = 294.2; map["Og"] = 294.2;
}

int t;
std::string s;

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.setf(std::ios::fixed);
  std::cout.precision(3);
  Init();
  std::cin >> t;
  while (t--) {
    std::cin >> s;
    double ans = 0.;
    int ptr = 0;
    while (ptr < (int)s.length()) {
      std::string buf;
      buf += s[ptr++];
      if (std::islower(s[ptr])) {
        buf += s[ptr++];
      }
      int cnt = 0;
      while (std::isdigit(s[ptr])) {
        cnt = (cnt * 10) + (s[ptr] - '0');
        ++ptr;
      }
      if (cnt == 0) {
        cnt = 1;
      }
      ans += map[buf] * cnt;
    }
    std::cout << ans << '\n';
  }
  return 0;
}

