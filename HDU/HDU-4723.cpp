
#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <algorithm>
#include <iomanip>
#include <cctype>
#include <cmath>
#include <stack>
#include <queue>
#include <vector>
#include <cstdlib>
#include <sstream>
#include <set>
#include <map>
using namespace std;
#define mem(a,b) memset(a,b,sizeof(a))
typedef long long ll;
typedef pair<int, int> P;
const int INF = 0x3f3f3f3f;
const int maxn = 1e5+5;
const double eps = 1e-5;
const double e = 2.718281828459;

/*
 * 贪心
 * 从左至右依次连接线段
 * 连接方法为：
 * 先连接两条线上最左边的两点
 * 然后依次比较第一条线上第一个未连接点到第二条线上最后一个已连接点的距离和第二条线上第一个未连接点到第一条线上最后一个已连接点的距离选择短的那条线段连接
 * 直到有一条线上所有点全部连接完毕
 * 再循环那条点没有全部连接完的直线
 * 把剩下的点全部与另一条直线上最后一个点相连成线段
 */

int t;
int a, b;
double a_b_dis;
int n, m;
int c_cnt, d_cnt;
double c[maxn], d[maxn];
double ans;

// 数据读取
void Get_information() {
    scanf("%d%d%d%d", &a, &b, &n, &m);
    a_b_dis = pow(a - b, 2);
    for (int i = 0; i < n; ++i) {
        scanf("%lf", &c[i]);
    }
    for (int i = 0; i < m; ++i) {
        scanf("%lf", &d[i]);
    }
}

// 平面距离计算
double Cal_dis(double x1, double x2) {
    return sqrt(pow(x1 - x2, 2) + a_b_dis);
}

void Solve() {
    ans += Cal_dis(c[0], d[0]);
    c_cnt = 1; d_cnt = 1;
    while (c_cnt < n && d_cnt < m) {
        double c_judge_temp = Cal_dis(c[c_cnt], d[d_cnt - 1]);
        double d_judge_temp = Cal_dis(c[c_cnt - 1], d[d_cnt]);
        if (c_judge_temp < d_judge_temp) {
            ans += c_judge_temp;
            c_cnt++;
        }
        else {
            ans += d_judge_temp;
            d_cnt++;
        }
    }
    while (c_cnt < n) {
        ans += Cal_dis(c[c_cnt], d[d_cnt - 1]);
        c_cnt++;
    }
    while (d_cnt < m) {
        ans += Cal_dis(c[c_cnt - 1], d[d_cnt]);
        d_cnt++;
    }
}

int main() {
	// "cin"&"cout"会TLE
    scanf("%d", &t);
    for (int Case = 1; Case <= t; ++Case) {
        ans = 0;
        Get_information();
        if (n == 1 && m == 1) {
            printf("Case #%d: %.2lf\n", Case, ans);
            continue;
        }
        if (!n || !m) {
            printf("Case #%d: %.2lf\n", Case, ans);
            continue;
        }
        Solve();
        printf("Case #%d: %.2lf\n", Case, ans);
    }
    return 0;
}
