#include <bits/stdc++.h>
typedef double db;
const db inf = 1e10;
const db eps = 1e-9;
const int maxn = 1e4 + 5;
int Sgn(db k) { return std::fabs(k) < eps ? 0 : (k < 0 ? -1 : 1); }
int Cmp(db k1, db k2) { return Sgn(k1 - k2); }
db Min(db k1, db k2) { return Cmp(k1, k2) < 0 ? k1 : k2; }
db Max(db k1, db k2) { return Cmp(k1, k2) > 0 ? k1 : k2; }
struct Point { db x, y; };
Point operator + (Point k1, Point k2) { return (Point){k1.x + k2.x, k1.y + k2.y}; }
Point operator - (Point k1, Point k2) { return (Point){k1.x - k2.x, k1.y - k2.y}; }
Point operator * (Point k1, db k2) { return (Point){k1.x * k2, k1.y * k2}; }
Point operator / (Point k1, db k2) { return (Point){k1.x / k2, k1.y / k2}; }
db operator * (Point k1, Point k2) { return k1.x * k2.x + k1.y * k2.y; }
db operator ^ (Point k1, Point k2) { return k1.x * k2.y - k1.y * k2.x; }
bool operator < (Point k1, Point k2) { return Cmp(k1.x, k2.x) == 0 ? Cmp(k1.y, k2.y) < 0 : Cmp(k1.x, k2.x) < 0; }
db GetLen(Point k) { return std::sqrt(k * k); }
db GetDis(Point k1, Point k2) { return GetLen(k2 - k1); }
struct Line { Point s, t; };
typedef Line Seg;
db GetLen(Seg k) { return GetLen(k.t - k.s); }
bool operator < (Seg k1, Seg k2) { return k1.s < k2.s; }
bool IsInter(Seg k1, Seg k2) {
    return
            Cmp(Max(k1.s.x, k1.t.x), Min(k2.s.x, k2.t.x)) >= 0 &&
            Cmp(Max(k2.s.x, k2.t.x), Min(k1.s.x, k1.t.x)) >= 0 &&
            Cmp(Max(k1.s.y, k1.t.y), Min(k2.s.y, k2.t.y)) >= 0 &&
            Cmp(Max(k2.s.y, k2.t.y), Min(k1.s.y, k1.t.y)) >= 0 &&
            Sgn((k2.s - k1.t) ^ (k1.s - k1.t)) * Sgn((k2.t - k1.t) ^ (k1.s - k1.t)) <= 0 &&
            Sgn((k1.s - k2.t) ^ (k2.s - k2.t)) * Sgn((k1.t - k2.t) ^ (k2.s - k2.t)) <= 0;
}
db GetDis(Point k1, Seg k2) {
    if (Sgn((k1 - k2.s) * (k2.t - k2.s)) < 0 || Sgn((k1 - k2.t) * (k2.s - k2.t)) < 0) return Min(GetDis(k1, k2.s), GetDis(k1, k2.t));
    return std::fabs((k1 - k2.s) ^ (k2.t - k2.s)) / GetLen(k2);
}
db GetDis(Seg k1, Seg k2) {
    if (IsInter(k1, k2)) return 0.;
    return Min(Min(GetDis(k1.s, k2), GetDis(k1.t, k2)), Min(GetDis(k2.s, k1), GetDis(k2.t, k1)));
}
Seg seg[maxn];
int main() {
    int t;
    scanf("%d", &t);
    for (int cas = 1; cas <= t; ++cas) {
        int n;
        scanf("%d", &n);
        for (int i = 1; i <= n; ++i) {
            scanf("%lf%lf%lf%lf", &seg[i].s.x, &seg[i].s.y, &seg[i].t.x, &seg[i].t.y);
            if (seg[i].t < seg[i].s) std::swap(seg[i].s, seg[i].t);
        }
        std::sort(seg + 1, seg + n + 1);
        db ans = inf;
        for (int i = 1; i <= n; ++i) {
            for (int j = i + 1; j <= n; ++j) {
                if (Cmp(seg[j].s.x - seg[i].t.x, ans) > 0) break;
                ans = Min(ans, GetDis(seg[i], seg[j]));
            }
        }
        printf("%.12f\n", ans);
    }
    return 0;
}