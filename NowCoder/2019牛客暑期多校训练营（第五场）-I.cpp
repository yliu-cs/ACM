#include <bits/stdc++.h>
const double eps = 1e-9;
const double pi = acos(-1.0);
int Sgn(double k) {
  return std::fabs(k) < eps ? 0 : (k < 0 ? -1 : 1);
}
int Cmp(double k1, double k2) {
  return Sgn(k1 - k2);
}
struct point {
  double x, y;
  point operator + (const point &k) const { return (point){k.x + x, k.y + y}; }
  point operator - (const point &k) const { return (point){x - k.x, y - k.y}; }
  point operator * (double k) const { return (point){x * k, y * k}; };
  point operator / (double k) const { return (point){x / k, y / k}; };
  int operator == (const point &k) const { return Cmp(x, k.x) == 0 && Cmp(y, k.y) == 0; };
  point Turn(double k) { return (point){x * std::cos(k) - y * std::sin(k), x * std::sin(k) + y * std::cos(k)}; }
  point Turn90() { return (point){-y, x}; }
  double Abs() { return sqrt(x * x + y * y); }
  double Abs2() { return x * x + y * y; }
  double Dis(point k) { return ((*this) - k).Abs(); }
  point Unit() { double w = Abs(); return (point){x / w, y / w}; }
  void Print() { printf("%.12lf %.12lf ", x, y); }
};
struct circle {
  point o;
  double r;
};
int CheckPosCC(circle k1, circle k2) {
  if (Cmp(k1.r, k2.r) == -1) std::swap(k1, k2);
  double dis = k1.o.Dis(k2.o);
  int w1 = Cmp(dis, k1.r + k2.r), w2 = Cmp(dis, k1.r - k2.r);
  if (w1 > 0) return 4;
  if (w1 == 0) return 3;
  else if (w2 > 0) return 2;
  else if (w2 == 0) return 1;
  else return 0;
}
std::vector<point> GetCC(circle k1, circle k2) {
  int pd = CheckPosCC(k1, k2);
  if (pd == 0 || pd == 4) return {};
  double a = (k2.o - k1.o).Abs2();
  double cosA = (k1.r * k1.r + a - k2.r * k2.r) / (2 * k1.r * sqrt(std::max(a, 0.0)));
  double b = k1.r * cosA, c = sqrt(std::max(0.0, k1.r * k1.r - b * b));
  point k = (k2.o - k1.o).Unit(), m = k1.o + k * b, del = k.Turn90() * c;
  return {m - del, m + del};
}
bool IsIn(point k, double w, double h) {
  double x = k.x, y = k.y;
  return Sgn(x) >= 0 && Cmp(x, w) <= 0 && Sgn(y) >= 0 && Cmp(y, h) <= 0;
}
std::vector<point> Find(double w, double h, double a, double b, double c) {
  std::vector<point> ret;
  if (Cmp(a, std::sqrt(w * w + h * h)) > 0) return ret;
  ret.push_back((point){0., 0.});
  if (Cmp(a, w) <= 0) ret.push_back((point){a, 0.});
  else ret.push_back((point){w, std::sqrt(a * a - w * w)});
  std::vector<point> cross = GetCC((circle){ret[0], b}, (circle){ret[1], c});
  if (cross.empty()) {
    ret.clear();
    return ret;
  }
  if (IsIn(cross[0], w, h)) ret.push_back(cross[0]);
  else if (IsIn(cross[1], w, h)) ret.push_back(cross[1]);
  else ret.clear();
  return ret;
}
void Solve(double w, double h, double a, double b, double c) {
  std::vector<point> ans;
  for (int i = 0; i < 1; ++i) {
    ans = Find(i ? h : w, i ? w : h, a, b, c);
    if (!ans.empty()) {
      if (!i) {
        ans[0].Print(); ans[1].Print(); ans[2].Print();
        printf("\n");
      }
      else {
        for (int i = 0; i < ans.size(); ++i) {
          ans[i] = ans[i].Turn(-pi * 0.5);
          ans[i].y += w;
        }
        ans[0].Print(); ans[1].Print(); ans[2].Print();
      }
      return;
    }
    ans = Find(i ? h : w, i ? w : h, a, c, b);
    if (!ans.empty()) {
      if (!i) {
        ans[1].Print(); ans[0].Print(); ans[2].Print();
        printf("\n");
      }
      else {
        for (int i = 0; i < ans.size(); ++i) {
          ans[i] = ans[i].Turn(-pi * 0.5);
          ans[i].y += w;
        }
        ans[1].Print(); ans[0].Print(); ans[2].Print();
      }
      return;
    }
    ans = Find(i ? h : w, i ? w : h, b, a, c);
    if (!ans.empty()) {
      if (!i) {
        ans[0].Print(); ans[2].Print(); ans[1].Print();
        printf("\n");
      }
      else {
        for (int i = 0; i < ans.size(); ++i) {
          ans[i] = ans[i].Turn(-pi * 0.5);
          ans[i].y += w;
        }
        ans[0].Print(); ans[2].Print(); ans[1].Print();
      }
      return;
    }
    ans = Find(i ? h : w, i ? w : h, b, c, a);
    if (!ans.empty()) {
      if (!i) {
        ans[1].Print(); ans[2].Print(); ans[0].Print();
        printf("\n");
      }
      else {
        for (int i = 0; i < ans.size(); ++i) {
          ans[i] = ans[i].Turn(-pi * 0.5);
          ans[i].y += w;
        }
        ans[1].Print(); ans[2].Print(); ans[0].Print();
      }
      return;
    }
    ans = Find(i ? h : w, i ? w : h, c, b, a);
    if (!ans.empty()) {
      if (!i) {
        ans[2].Print(); ans[1].Print(); ans[0].Print();
        printf("\n");
      }
      else {
        for (int i = 0; i < ans.size(); ++i) {
          ans[i] = ans[i].Turn(-pi * 0.5);
          ans[i].y += w;
        }
        ans[2].Print(); ans[1].Print(); ans[0].Print();
      }
      return;
    }
    ans = Find(i ? h : w, i ? w : h, c, a, b);
    if (!ans.empty()) {
      if (!i) {
        ans[2].Print(); ans[0].Print(); ans[1].Print();
        printf("\n");
      }
      else {
        for (int i = 0; i < ans.size(); ++i) {
          ans[i] = ans[i].Turn(-pi * 0.5);
          ans[i].y += w;
        }
        ans[2].Print(); ans[0].Print(); ans[1].Print();
      }
      return;
    }
  }
  assert(1 > 2);
}
int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    double w, h, a, b, c;
    scanf("%lf%lf%lf%lf%lf", &w, &h, &a, &b, &c);
    Solve(w, h, a, b, c);
  }
  return 0;
}
