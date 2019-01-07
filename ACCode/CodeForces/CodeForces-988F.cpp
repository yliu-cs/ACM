#include <bits/stdc++.h>
using namespace std;
#define mem(a,b) memset(a,b,sizeof(a))
#define pb push_back
#define mp make_pair
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> P;
const int INF = 0x3f3f3f3f;
const int maxn = 2e3+5;
const int mod = 1e9+7;
const double eps = 1e-8;
const double pi = asin(1.0)*2;
const double e = 2.718281828459;
void fre() {
    freopen("C_IN.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
}

int a, n, m;
// rain[i]==1为i点有雨,rain[i]==0为i点无雨
bool rain[maxn];
// wi[i]为编号为i伞的重量
int wi[maxn];
// dp[i][j]带便拿着j伞走到i点的最小疲劳值,j=0代表不拿伞
int dp[maxn][maxn];
// um[i]存储i位置上的所有伞编号
vector<int> um[maxn];

int main(){
    //fre();
    mem(rain, 0);
    mem(wi, 0);
    scanf("%d%d%d", &a, &n, &m);
    for (int i = 1; i <= n; ++i) {
        int input_l, input_r;
        scanf("%d%d", &input_l, &input_r);
        // 左闭右开区间标记下雨段
        for (int j = input_l; j < input_r; ++j) {
            rain[j] = 1;
        }
    }
    for (int i = 1; i <= a; ++i) {
        um[i].pb(0);
    }
    // 将伞编号从1开始标记,因为dp[i][0]代表不拿伞而不是拿0编号的伞
    for (int i = 1; i <= m; ++i) {
        int input_x;
        scanf("%d%d", &input_x, &wi[i]);
        um[input_x].pb(i);
    }
    // 位置i
    for (int i = 0; i <= a; ++i) {
        // 伞j
        for (int j = 0; j <= m; ++j) {
            // 判断i点是否有伞j
            bool flag = 0;
            for (int k = 0; k < um[i].size(); ++k) {
                if (um[i][k] == j) {
                    flag = 1;
                }
            }
            // 若i点有雨将dp[i][0]初始化为INF
            if (rain[i] && j == 0){
                dp[i][j] = INF;
            }
            // 特判0点
            else if (i == 0) {
                // 若起点没有伞j将dp[0][j]初始化为INF，否则为0
                if (!flag && j != 0) {
                    dp[i][j] = INF;
                }
                else {
                    dp[i][j] = 0;
                }
            }
            // 若i点有伞j
            else if (flag) {
                // 寻找带上伞j的最小疲劳值
                int cost = INF;
                for (int k = 0; k <= m; ++k) {
                    cost = min(cost, dp[i - 1][k] + wi[k]);
                }
                dp[i][j] = cost;
            }
            else {
                dp[i][j] = min(INF, dp[i - 1][j] + wi[j]);
            }
        }
    }
    int ans = INF;
    for (int i = 0; i <= m; ++i) {
        ans = min(ans, dp[a][i]);
    }
    ans = ans == INF ? -1 : ans;
    printf("%d", ans);
    return 0;
}
