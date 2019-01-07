
#include <bits/stdc++.h>
using namespace std;
#define mem(a,b) memset(a,b,sizeof(a))
#define pb push_back
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> P;
const int INF = 0x3f3f3f3f;
const int maxn = 1e5+5;
const int mod = 1e9+7;
const double eps = 1e-8;
const double pi = asin(1.0)*2;
const double e = 2.718281828459;
void fre() {
    freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
}

struct point {
    double x, y;
};

struct edge {
    point a, b;
}p[maxn];

int n;
bool flag;

// 叉乘判断两线段是否相交
bool judge(edge a, edge b) {
    if (min(a.a.x, a.b.x) > max(b.a.x, b.b.x) || min(a.a.y, a.b.y) > max(b.a.y, b.b.y) || min(b.a.x, b.b.x) > max(a.a.x, a.b.x) || min(b.a.y, b.b.y) > max(a.a.y, a.b.y)) {
        return 0;
    }
    double h, i, j, k;
    h = (a.b.x - a.a.x) * (b.a.y - a.a.y) - (a.b.y - a.a.y) * (b.a.x - a.a.x);
    i = (a.b.x - a.a.x) * (b.b.y - a.a.y) - (a.b.y - a.a.y) * (b.b.x - a.a.x);
    j = (b.b.x - b.a.x) * (a.a.y - b.a.y) - (b.b.y - b.a.y) * (a.a.x - b.a.x);
    k = (b.b.x - b.a.x) * (a.b.y - b.a.y) - (b.b.y - b.a.y) * (a.b.x - b.a.x);
    return h * i <= eps && j * k <= eps;
}

int main() {
    //fre();
    while (~scanf("%d", &n) && n) {
        flag = 0;
        for (int i = 1; i <= n; ++i) {
            scanf("%lf%lf%lf%lf", &p[i].a.x, &p[i].a.y, &p[i].b.x, &p[i].b.y);
        }
        printf("Top sticks:");
        for (int i = 1; i <= n; ++i) {
            bool ok = 1;
            for (int j = i + 1; j <= n; ++j) {
                if (judge(p[i], p[j])) {
                    ok = 0;
                    break;
                }
            }
            if (ok) {
                if (!flag) {
                    flag = 1;
                    printf(" %d", i);
                }
                else {
                    printf(", %d", i);
                }
            }
        }
        printf(".\n");
    }
    return 0;
}

