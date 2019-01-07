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

/*
 * 每个人出一个1~K的数
 * 当所有数之和到达N时最后一个出数的人输
 * 若想要取得游戏的胜利必须在出数之后所有数之和达到n-1
 * 此时就变为n-1个石子的巴什博弈原型题目
 */

int main(){
    //fre();
    int n, k;
    while (scanf("%d%d", &n, &k) != EOF, n, k) {
        if ((n - 1) % (k + 1)) {
            printf("Tang\n");
        }
        else {
            printf("Jiang\n");
        }
    }
    return 0;
}
