#include <bits/stdc++.h>
using namespace std;
#define mem(a,b) memset(a,b,sizeof(a))
#define pb push_back
#define mp make_pair
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> P;
const int INF = 0x3f3f3f3f;
const int maxn = 2600;
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
    int n;
    scanf("%d", &n);
    while (n--) {
        double a[3];
        scanf("%lf%lf%lf", &a[0], &a[1], &a[2]);
        sort(a, a + 3);
        if (a[0] + a[1] > a[2]) {
            printf("YES\n");
        }
        else {
            printf("NO\n");
        }
    }
    return 0;
}
