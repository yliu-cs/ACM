#include <bits/stdc++.h>
using namespace std;
#define mem(a,b) memset(a,b,sizeof(a))
#define pb push_back
#define mp make_pair
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> P;
const int INF = 0x3f3f3f3f;
const int maxn = 1e6+5;
const int mod = 1000000000;
const double eps = 1e-8;
const double pi = asin(1.0)*2;
const double e = 2.718281828459;
bool Finish_read;
template<class T>inline void read(T &x){Finish_read=0;x=0;int f=1;char ch=getchar();while(!isdigit(ch)){if(ch=='-')f=-1;if(ch==EOF)return;ch=getchar();}while(isdigit(ch))x=x*10+ch-'0',ch=getchar();x*=f;Finish_read=1;}
inline void fre() {freopen("in.txt", "r", stdin);/*freopen("out.txt", "w", stdout);*/}

/*
 * 这道题目用母函数超时，所以采用递推法。
 * dp[i]记录i可以被组成的种类数。
 * 当i为奇数时:i可以被分为一个1和一个偶数，所以dp[i]=d[i-1]
 * 当i为偶数时有两种情况:
 * 有两个1，dp[i-2]
 * 全是偶数，显然等于dp[i/2]
 *
 * 所以dp[i]=dp[i-2]+dp[i/2]
 */

int main() {
//    fre();
    int n;
    while (~scanf("%d", &n)) {
        ll dp[maxn];
        mem(dp, 0);
        dp[0] = 1;
        for (int i = 1; i <= n; i <<= 1) {
            for (int j = i; j <= n; ++j) {
                dp[j] += dp[j - i];
                dp[j] %= mod;
//                printf("dp[%d]=%lld\n", j, dp[j]);
            }
        }
        printf("%lld\n", dp[n]);
    }
    return 0;
}
