#pragma comment(linker, "/STACK:102400000,102400000")
#include <bits/stdc++.h>
using namespace std;
#define mem(a,b) memset(a,b,sizeof(a))
#define pb push_back
#define mp make_pair
#define lowbit(x) (x&(-x))
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> PII;
typedef pair<double,double> PDD;
const int INF = 0x3f3f3f3f;
const int maxn = 1e5+5;
const int mod = 1e9+7;
const double eps = 1e-8;
const double pi = asin(1.0)*2;
const double e = 2.718281828459;
bool Finish_read;
template<class T>inline void read(T &x){Finish_read=0;x=0;int f=1;char ch=getchar();while(!isdigit(ch)){if(ch=='-')f=-1;if(ch==EOF)return;ch=getchar();}while(isdigit(ch))x=x*10+ch-'0',ch=getchar();x*=f;Finish_read=1;}
 
int main(int argc, char *argv[]) {
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    int q, k;
    read(q); read(k);
    ll dp[maxn][2];
    mem(dp, 0);
    dp[0][0] = 1;
    ll ans[maxn];
    mem(ans, 0);
    for (int i = 1; i < maxn; ++i) {
        dp[i][0] = dp[i - 1][0] % mod + dp[i - 1][1] % mod;
        if (i - k >= 0) {
            dp[i][1] = dp[i - k][0] % mod;
        }
        ans[i] = ans[i - 1] + dp[i][0] + dp[i][1];
    }
    for (int i = 1, l, r; i <= q; ++i) {
        read(l); read(r);
        printf("%lld\n", (ans[r] - ans[l - 1]) % mod);
    }
#ifndef ONLINE_JUDGE
    fclose(stdin);
    fclose(stdout);
    system("gedit out.txt");
#endif
    return 0;
}
