#include <bits/stdc++.h>
using namespace std;
typedef double db;
const db eps = 1e-12;

int Sgn(db k) {return fabs(k) < eps ? 0 : (k < 0 ? -1 : 1);}
int Cmp(db k1, db k2) {return Sgn(k1 - k2);}

namespace Simpson {
  db a;

  db F(db x) {
    return pow(x, a / x - x);
  }

  db Simpson(db l, db r) {
    db m = (l + r) / 2.0;
    return (F(l) + 4 * F(m) + F(r)) * (r - l) / 6.0;
  }

  db Asr(db l, db r, db ans) {
    db m = (l + r) / 2.0;
    db l_ans = Simpson(l, m), r_ans = Simpson(m, r);
    if (Cmp(fabs(l_ans + r_ans - ans), 15.0 * eps) <= 0) return l_ans + r_ans + (l_ans + r_ans - ans) / 15.0;
    return Asr(l, m, l_ans) + Asr(m, r, r_ans);
  }
};

int main() {
  ios::sync_with_stdio(false); cin.tie(0);
  cout << fixed << setprecision(5);
  cin >> Simpson::a;
  if (Sgn(Simpson::a) < 0) cout << "orz" << endl;
  else cout << Simpson::Asr(eps, 20.0, Simpson::Simpson(eps, 20.0)) << endl;
  return 0;
}
