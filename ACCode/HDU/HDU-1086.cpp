
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
	// 重载坐标相减
    Point operator - (const Point &b) const {
        return Point{x - b.x, y - b.y};
    }
    double operator ^ (const Point &b) const {
        return x * b.y - y * b.x;
    }
};

struct Segment {
    Point p, q;
    void input() {
        p.input(); q.input();
    }
	// 重载线段叉乘
    double operator ^ (const Segment &b) const {
        return (q - p) ^ (b.q - b.p);
    }
};

// 利用叉乘判断两线段是否相交
bool judge(Segment a, Segment b) {
    if ((a ^ Segment{a.p, b.p}) * (a ^ Segment{a.p, b.q}) <= 0 &&
        (b ^ Segment{b.p, a.p}) * (b ^ Segment{b.p, a.q}) <= 0) {
        return 1;
    }
    return 0;
}

int main(int argc, char *argv[]) {
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    int n;
    while (read(n) && n) {
        vector<Segment> Segment(n);
        for (int i = 0; i < n; ++i) {
            Segment[i].input();
        }
        int cnt = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
				// 相交计数
                if (judge(Segment[i], Segment[j])) {
                    cnt++;
                }
            }
        }
        print(cnt);
    }
#ifndef ONLINE_JUDGE
    fclose(stdin);
    fclose(stdout);
    system("gedit out.txt");
#endif
    return 0;
}
