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

/*
 * 判断多边形是凸多边形还是凹多边形
 * 
 * 对于多边形的任意一条边
 * 多边形其它顶点都在这条边所在直线的一侧则多边形为凸多边形
 * 反之为凹多边形。
 *
 * 题目将多边形顶点按照逆时针顺序给出
 * 所以使用叉乘依次判断顶点是否在前面的两个顶点所在直线逆时针方向即可。
 *
 * 直线属于凸多边形
 * 注意判断第一和第二个顶点
 */

struct Point {
    double x, y;
    Point(double _x = 0.0, double _y = 0.0): x(_x), y(_y) {}
    void input() {
        scanf("%lf%lf", &x, &y);
    }
    void output() {
        printf("%lf %lf", x, y);
    }
    bool operator == (const Point &b) const {
        return x == b.x && y == b.y;
    }
    Point operator - (const Point &b) const {
        return Point{x - b.x, y - b.y};
    }
    double operator ^ (const Point &b) const {
        return x * b.y - y * b.x;
    }
};

int main(int argc, char *argv[]) {
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    int n;
    while (read(n) && n) {
        vector<Point> points(n);
        bool flag = 1;
        for (int i = 0; i <= n + 1; ++i) {
            if (i == n) {
                points.pb(points[0]);
            }
            else if (i == n + 1) {
                points.pb(points[1]);
            }
            else {
                points[i].input();
            }
            if (i > 1) {
                if (((points[i - 1] - points[i - 2]) ^ (points[i] - points[i - 2])) <= 0) {
                    flag = 0;
                }
            }
        }
        if (flag) {
            printf("convex\n");
        }
        else {
            printf("concave\n");
        }
    }
#ifndef ONLINE_JUDGE
    fclose(stdin);
    fclose(stdout);
    system("gedit out.txt");
#endif
    return 0;
}
