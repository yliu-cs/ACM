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
    int t;
    read(t);
    while (t--) {
        int n;
        read(n);
        vector<int> a(n + 1);
        read(a[1]);
        ll dp[maxn][4];
        mem(dp, 0);
        dp[1][0] = -a[1];
        dp[1][2] = 1;
        dp[1][1] = 0;
        ll bmax = -a[1], smax = 0;
        int bindex = 1, sindex = 1;
        for (int i = 2; i <= n; ++i) {
            read(a[i]);
            dp[i][0] = smax - a[i];
            dp[i][1] = bmax + a[i];
            if (dp[i][0] > bmax) {
                bmax = dp[i][0];
                dp[i][2] = dp[sindex][3] + 1;
                bindex = i;
            }
            if (dp[i][1] > smax) {
                smax = dp[i][1];
                dp[i][3] = dp[bindex][2] + 1;
                sindex = i;
            }
        }
        printf("%lld %lld\n", smax, dp[sindex][3]);
    }
#ifndef ONLINE_JUDGE
    fclose(stdin);
    fclose(stdout);
    system("gedit out.txt");
#endif
    return 0;
}
