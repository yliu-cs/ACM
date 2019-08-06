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
    freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
}

// 巴什博弈

/*
 * 巴什博弈模型为n个石子
 * 每个人每次可以拿走1~m个石子
 * 最后一个拿走石子的人获胜
 *
 * 当石子有1~m个石子时先手必胜
 * 当石子有m+1个时先手无论拿几个后手都可以拿完，所以先手必败
 * 当石子有m+(2~2m)时，先手可以拿走几个，剩下m+1个，先手必胜
 *
 * 面临m+1个石子的人必败
 * 设当前石子数为n=k*(m+1)+r
 * 先手拿走r个，设后手拿走x个，先手拿走m+1-x个，这样拿下去先手必胜
 * 设当前的石子数为n=k*(m+1)
 * 设先手拿x个，后手一定拿m+1-x个，这样拿下去先手必败
 * 所以巴什博弈的胜者可以通过n%(m+1)是否为0判断
 */
int main(){
    //fre();
    int t;
    scanf("%d", &t);
    while (t--) {
        int n, m;
        scanf("%d%d", &n, &m);
        if (n % (m + 1)) {
            printf("first\n");
        }
        else {
            printf("second\n");
        }
    }
    return 0;
}
