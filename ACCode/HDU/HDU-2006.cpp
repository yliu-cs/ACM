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

int main(){
    //fre();
    int n;
    while (~scanf("%d", &n)) {
        int ans = 1, input;
        for (int i = 0; i < n; ++i) {
            scanf("%d", &input);
            if (input % 2) {
                ans *= input;
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}
