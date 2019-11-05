#include <bits/stdc++.h>
using namespace std;
#define mem(a,b) memset(a,b,sizeof(a))
#define pb push_back
#define mp make_pair
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> P;
const int INF = 0x3f3f3f3f;
const int maxn = 1e3+5;
const int mod = 1e9+7;
const double eps = 1e-8;
const double pi = asin(1.0)*2;
const double e = 2.718281828459;
void fre() {
    freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
}

int t;
int n, m;
int ans;

// 模拟

int main(){
    //fre();
    scanf("%d", &t);
    for (int Case = 1; Case <= t; ++Case) {
        printf("Problem %d:\n", Case + 1000);
        scanf("%d%d", &n, &m);
        int a, b;
        ans = INF;
        for (int i = 0; i < n; ++i) {
            scanf("%d", &a);
            if (a < ans) {
                ans = a;
            }
        }
        printf("Shortest judge solution: %d bytes.\n", ans);
        ans = INF;
        if (m == 0) {
            printf("Shortest team solution: N/A bytes.\n");
        }
        else {
            for (int i = 0; i < m; ++i) {
                scanf("%d", &b);
                if (b < ans) {
                    ans = b;
                }
            }
            printf("Shortest team solution: %d bytes.\n", ans);
        }
    }
    return 0;
}
