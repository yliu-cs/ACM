#include <bits/stdc++.h>
using namespace std;
typedef double db;

namespace Simpson {
  db a, b, c, d;

  db F(db x) {
    return (c * x + d) / (a * x + b);
  }

  db Simpson(db l, db r) {
    db m = (l + r) / 2.0;
    return (F(l) + 4 * F(m) + F(r)) * (r - l) / 6.0;
  }

  db Asr(db l, db r, db ans, db eps) {
    db m = (l + r) / 2.0;
    db l_ans = Simpson(l, m), r_ans = Simpson(m, r);
    if (fabs(l_ans + r_ans - ans) <= 15.0 * eps) return l_ans + r_ans + (l_ans + r_ans - ans) / 15.0;
    return Asr(l, m, l_ans, eps / 2.0) + Asr(m, r, r_ans, eps / 2.0);
  }
};

int main() {
  ios::sync_with_stdio(false); cin.tie(0);
  cout << fixed << setprecision(6);
  db l, r; cin >> Simpson::a >> Simpson::b >> Simpson::c >> Simpson::d >> l >> r;
  cout << Simpson::Asr(l, r, Simpson::Simpson(l, r), 1e-6) << endl;
  return 0;
}

