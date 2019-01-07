#include <bits/stdc++.h>
using namespace std;
#define mem(a,b) memset(a,b,sizeof(a))
#define pb push_back
#define mp make_pair
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> P;
const int INF = 0x3f3f3f3f;
const int maxn = 1e2+5;
const int mod = 1e9+7;
const double eps = 1e-8;
const double pi = asin(1.0)*2;
const double e = 2.718281828459;
void fre() {
    freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
}

int t;
int n;
int ans;
int dp[maxn][maxn] = {0};

int main(){
    //fre();
    scanf("%d", &t);
    while (t--) {
        ans = -1;
        scanf("%d", &n);
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= i; ++j) {
                scanf("%d", &dp[i][j]);
                dp[i][j] += max(dp[i - 1][j - 1], dp[i - 1][j]);
                if (i == n && dp[i][j] > ans) {
                    ans = dp[i][j];
                }
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}
