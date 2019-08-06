#include <bits/stdc++.h>
using namespace std;
#define mem(a,b) memset(a,b,sizeof(a))
#define pb push_back
#define mp make_pair
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> P;
const int INF = 0x3f3f3f3f;
const int maxn = 2e5+5;
const int mod = 1e9+7;
const double eps = 1e-8;
const double pi = asin(1.0)*2;
const double e = 2.718281828459;
void fre() {
    freopen("out.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
}

// 巴什博弈
/*
 * 若总数为3的倍数
 * 后手保证所拿数量与先手之和为3的倍数则必胜
 *
 * 若总数不是3的倍数
 * 先手拿除于3的余数
 * 以后先手所拿数量与后手所拿之和为3的倍数
 * 则先手必胜
 */

int main(){
    //fre();
    int n;
    while (~scanf("%d", &n)) {
        if (n % 3) {
            printf("Kiki\n");
        }
        else {
            printf("Cici\n");
        }
    }
    return 0;
}
