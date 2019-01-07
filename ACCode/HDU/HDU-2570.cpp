#include <bits/stdc++.h>
using namespace std;
#define mem(a,b) memset(a,b,sizeof(a))
#define pb push_back
#define mp make_pair
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> P;
const int INF = 0x3f3f3f3f;
const int maxn = 102;
const int mod = 1e9+7;
const double eps = 1e-8;
const double pi = asin(1.0)*2;
const double e = 2.718281828459;
void fre() {
    freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
}

/*
 * 浓度的计算是溶质体积除以溶液体积
 * 所以在计算混合浓度的时候不能直接使用分别的浓度计算
 * 而应该计算出总溶质体积然后再除以总溶液体积。
 * 因为溶液混合时体积增大
 * 所以浓度也会下降
 * 所以当浓度到达界限时
 * 再添加一瓶溶液也有可能浓度下降
 * 所以我用的方法是先计算所有溶液混合的总浓度
 * 然后再将溶液浓度按照降序排列
 * 若浓度大于界限
 * 则依次取出一瓶浓度最大的溶液
 */

int c;
int n, v, w;
int ansv;
double ans_v;
double answ;

int main() {
    //fre();
    scanf("%d", &c);
    while (c--) {
        ansv = 0;
        ans_v = 0;
        answ = 0;
        scanf("%d%d%d", &n, &v, &w);
        vector<double> p(n + 1);
        for (int i = 1; i <= n; ++i) {
            scanf("%lf", &p[i]);
            ansv += v;
            ans_v += (double)v * (p[i] / 100.0);
        }
        answ = (double)ans_v / (double)ansv * 100.0;
        sort(p.begin() + 1, p.end());
        reverse(p.begin() + 1, p.end());
        for (int i = 1; i <= n; ++i) {
            //printf("answ=%lf\n", answ);
            if (answ > w) {
                ansv -= v;
                ans_v -= (double)v * (p[i] / 100.0);
                if (ansv == 0) {
                    answ = 0.0;
                }
                else {
                    answ = (double)ans_v / (double)ansv * 100.0;
                }
            }
            else {
                break;
            }
        }
        answ /= 100;
        printf("%d %.2lf\n", ansv, answ);
    }
    return 0;
}
