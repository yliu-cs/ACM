#include <bits/stdc++.h>
using namespace std;
typedef double db;
const int maxn = 1e5 + 5;
const db eps = 0.0;

int Sgn(db k) {return fabs(k) < eps ? 0 : (k < 0 ? -1 : 1);}
int Cmp(db k1, db k2) {return Sgn(k1 - k2);}
db min(db k1, db k2) {if (Cmp(k1, k2) < 0) return k1; return k2;}
struct point {db x, y;};
point operator - (point k1, point k2) {return (point){k1.x - k2.x, k1.y - k2.y};}
point operator + (point k1, point k2) {return (point){k1.x + k2.x, k1.y + k2.y};}
db operator * (point k1, point k2) {return k1.x * k2.x + k1.y * k2.y;}
db operator ^ (point k1, point k2) {return k1.x * k2.y - k1.y * k2.x;}
db GetDisP2P(point k1, point k2) {return sqrt((k2 - k1) * (k2 - k1));}

int n;
point p[maxn];

db ClosestP2P(point p[], int l, int r) {
    if (l + 1 == r) return GetDisP2P(p[l], p[r]);
    if (l + 2 == r) return min(GetDisP2P(p[l + 1], p[r]), min(GetDisP2P(p[l], p[l + 1]), GetDisP2P(p[l], p[r])));
    int mid = (l + r) >> 1;
    db ans = min(solve(l, mid), solve(mid + 1, r));
    vector<point> mid_p;
    for (int i = l; i <= r; ++i) {
        if (Cmp(fabs(p[i].x - p[mid].x), ans) <= 0) mid_p.push_back(p[i]);
    }
    sort(mid_p.begin(), mid_p.end(), [&](point k1, point k2) {return Cmp(k1.y, k2.y) < 0;});
    for (int i = 0; i < mid_p.size(); ++i) {
        for (int j = i + 1; j < mid_p.size(); ++j) {
            if (Cmp(mid_p[j].y - mid_p[i].y, ans) >= 0) break;
            ans = min(ans, GetDisP2P(mid_p[i], mid_p[j]));
        }
    }
    return ans;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    cout << fixed << setprecision(2);
    while (cin >> n && n) {
        for (int i = 1; i <= n; ++i) cin >> p[i].x >> p[i].y;
        sort(p + 1, p + n + 1, [&](point k1, point k2) {return Cmp(k1.x, k2.x) < 0;});
        cout << solve(1, n) / 2.0 << endl;
    }
    return 0;
}

