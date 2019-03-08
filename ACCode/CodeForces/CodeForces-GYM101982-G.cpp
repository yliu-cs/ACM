#include <bits/stdc++.h>
using namespace std;
typedef double db;
const db inf = 1e20;
const db eps = 1e-9;

int Sgn(db k) {return fabs(k) < eps ? 0 : (k < 0 ? -1 : 1);}
int Cmp(db k1, db k2) {return Sgn(k1 - k2);}
db min(db k1, db k2) {return Cmp(k1, k2) < 0 ? k1 : k2;}
struct point {db x, y;};
point operator - (point k1, point k2) {return (point){k1.x - k2.x, k1.y - k2.y};}
point operator + (point k1, point k2) {return (point){k1.x + k2.x, k1.y + k2.y};}
db operator * (point k1, point k2) {return k1.x * k2.x + k1.y * k2.y;}
db operator ^ (point k1, point k2) {return k1.x * k2.y - k1.y * k2.x;}
db GetLen(point k) {return sqrt(k * k);}
db DisP2P(point k1, point k2) {return sqrt((k2 - k1) * (k2 - k1));}
struct line {point s, t;};
typedef line seg;
db GetLen(line k) {return GetLen(k.t - k.s);}
db DisP2Line(point k1, line k2) {return fabs((k1 - k2.s) ^ (k2.t - k2.s)) / GetLen(k2);}
db DisP2Seg(point k1, line k2) {
  if (Sgn((k1 - k2.s) * (k2.t - k2.s)) < 0 || Sgn((k1 - k2.t) * (k2.s - k2.t)) < 0) {
    return min(DisP2P(k1, k2.s), DisP2P(k1, k2.t));
  }
  return DisP2Line(k1, k2);
}

int main() {
  ios::sync_with_stdio(false); cin.tie(0);
  cout << fixed << setprecision(3);
  point goat; db x1, y1, x2, y2;
  cin >> goat.x >> goat.y >> x1 >> y1 >> x2 >> y2;
  db ans = inf;
  ans = min(ans, DisP2Seg(goat, (line){(point){x1, y1}, (point){x2, y1}}));
  ans = min(ans, DisP2Seg(goat, (line){(point){x1, y1}, (point){x1, y2}}));
  ans = min(ans, DisP2Seg(goat, (line){(point){x2, y1}, (point){x2, y2}}));
  ans = min(ans, DisP2Seg(goat, (line){(point){x1, y2}, (point){x2, y2}}));
  cout << ans << endl;
  return 0;
}

