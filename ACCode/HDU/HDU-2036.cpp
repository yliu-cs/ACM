#include <bits/stdc++.h>
using namespace std;
#define mem(a,b) memset(a,b,sizeof(a))
#define pb push_back
#define mp make_pair
#define lowbit(x) (x&(-x))
#define XDebug(x) cout<<#x<<"="<<x<<endl;
#define ArrayDebug(x,i) cout<<#x<<"["<<i<<"]="<<x[i]<<endl;
#define print(x) out(x);putchar('\n');
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> PII;
typedef pair<double,double> PDD;
typedef pair<ll,ll> PLL;
const int INF = 0x3f3f3f3f;
const int maxn = 1e3 + 5;
const int mod = 1e9 + 7;
const double eps = 1e-8;
const double pi = asin(1.0) * 2;
const double e = 2.718281828459;
template <class T>
inline bool read(T &ret) {
    char c;
    int sgn;
    if (c = getchar(), c == EOF) {
        return 0;
    }
    while (c != '-' && (c < '0' || c > '9')) {
        c = getchar();
    }
    sgn = (c == '-') ? -1 : 1;
    ret = (c == '-') ? 0 : (c - '0');
    while (c = getchar(), c >= '0' && c <= '9') {
        ret = ret * 10 + (c - '0');
    }
    ret *= sgn;
    return 1;
}
template <class T>
inline void out(T x) {
    if (x < 0) {
        putchar('-');
        x = -x;
    }
    if (x > 9) {
        out(x / 10);
    }
    putchar(x % 10 + '0');
}

struct Point {
    double x, y;
    Point(double _x = 0.0, double _y = 0.0): x(_x), y(_y) {}
    void input() {
        scanf("%lf%lf", &x, &y);
    }
    void output() {
        printf("%lf %lf", x, y);
    }
	// 坐标减法
    Point operator - (const Point &b) const{
        return Point{x - b.x, y - b.y};
    }
	// 向量叉乘
    double operator ^ (const Point &b) const {
        return x * b.y - y * b.x;
    }
};

// 两点间距离
double PointDis(Point a, Point b) {
    return hypot(a.x - b.x, a.y - b.y);
}

int main(int argc, char *argv[]) {
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    int n;
    while (read(n) && n) {
        vector<Point> points(n);
        double ans = 0;
        for (int i = 0; i < n; ++i) {
            points[i].input();
            if (i > 0) {
				// 叉乘计算面积
                ans += points[i] ^ points[i - 1];
            }
        }
        ans += points[0] ^ points.back();
        ans = abs(ans / 2.0);
        if (n < 3) {
            ans = 0;
        }
        printf("%.1lf\n", ans);
    }
#ifndef ONLINE_JUDGE
    fclose(stdin);
    fclose(stdout);
    system("gedit out.txt");
#endif
    return 0;
}
