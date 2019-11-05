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
        int Basic = 0;
        for (int i = 0; i < n; ++i) {
            points[i].input();
            if (i > 0) {
                if (points[i].y < points[Basic].y || (points[i].y == points[Basic].y && points[i].x < points[Basic].x)) {
                    Basic = i;
                }
            }
        }
        if (n == 1) {
            printf("%.2lf\n", 0);
            continue;
        }
        else if (n == 2) {
            printf("%.2lf\n", PointDis(points[0], points[1]));
            continue;
        }
        swap(points[0], points[Basic]);
		// 极角排序
        sort(points.begin() + 1, points.end(), [&] (const Point &a, const Point &b) {
            double temp = (a - points[0]) ^ (b - points[0]);
            if (temp > 0) {
                return 1;
            }
            else if (!temp && PointDis(a, points[0]) < PointDis(a, points[0])) {
                return 1;
            }
            return 0;
        });
		// 凸包找点
        vector<Point> Stack;
        Stack.pb(points[0]); Stack.pb(points[1]);
        for (int i = 2; i < n; ++i) {
            while (Stack.size() >= 2 && ((Stack.back() - Stack[Stack.size() - 2]) ^ (points[i] - Stack[Stack.size() - 2])) <= 0) {
                Stack.pop_back();
            }
            Stack.pb(points[i]);
        }
        Stack.pb(points[0]);
        double ans = 0;
        for (int i = 1; i < int(Stack.size()); ++i) {
            ans += PointDis(Stack[i], Stack[i - 1]);
        }
        printf("%.2lf\n", ans);
    }
#ifndef ONLINE_JUDGE
    fclose(stdin);
    fclose(stdout);
    system("gedit out.txt");
#endif
    return 0;
}
