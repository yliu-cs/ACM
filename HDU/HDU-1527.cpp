#include <bits/stdc++.h>
using namespace std;
#define mem(a,b) memset(a,b,sizeof(a))
#define pb push_back
#define mp make_pair
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> P;
const int INF = 0x3f3f3f3f;
const int maxn = 1e5;
const int mod = 1e9+7;
const double eps = 1e-8;
const double pi = asin(1.0)*2;
const double e = 2.718281828459;
void fre() {
    freopen("C_IN.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
}

// 威佐夫博弈
/*
 * 数据输入a和b对两数做差取k
 * 通过威佐夫博弈的公式算出奇异局a[k]直接判断a[k]和a是否相等
 */

int main(){
    //fre();
    int n, m;
    while (~scanf("%d%d", &n, &m)) {
        int a, b;
        a = min(n, m);
        b = max(n, m);
        int k = b - a;
        int judge = (int)(k * (1 + sqrt(5.0)) / 2.0);
        bool ans = judge == a ? 0 : 1;
        printf("%d\n", ans);
    }
    return 0;
}
