#include <bits/stdc++.h>
using namespace std;
#define mem(a,b) memset(a,b,sizeof(a))
#define pb push_back
#define mp make_pair
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> P;
const int INF = 0x3f3f3f3f;
const int maxn = 20;
const int mod = 1e9+7;
const double eps = 1e-8;
const double pi = asin(1.0)*2;
const double e = 2.718281828459;
void fre() {
    freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
}

int main(){
    //fre();
    int m;
    scanf("%d", &m);
    while (m--) {
        int num;
        scanf("%d", &num);
        double ans = 0;
        bool flag = 1;
        for (double i = 1; i <= num; ++i) {
            if (flag) {
                ans += 1 / i;
                flag = !flag;
            }
            else {
                ans -= 1 / i;
                flag = !flag;
            }
        }
        printf("%.2lf\n", ans);
    }
    return 0;
}
