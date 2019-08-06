#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
using namespace std;
#define mem(a,b) memset(a,b,sizeof(a))
#define pb push_back
#define mp make_pair
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> P;
const int INF = 0x3f3f3f3f;
const int maxn = 400;
const int mod = 1e9+7;
const double eps = 1e-8;
const double pi = asin(1.0)*2;
const double e = 2.718281828459;
bool Finish_read;
template<class T>inline void read(T &x){Finish_read=0;x=0;int f=1;char ch=getchar();while(!isdigit(ch)){if(ch=='-')f=-1;if(ch==EOF)return;ch=getchar();}while(isdigit(ch))x=x*10+ch-'0',ch=getchar();x*=f;Finish_read=1;}
inline void fre() {freopen("in.txt", "r", stdin);/*freopen("out.txt", "w", stdout);*/}

int n;
int x;
int dp[maxn][maxn];
int ans;

int main() {
    //fre();
	read(n);
	mem(dp, 0);
	ans = 0;
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= i; ++j) {
			read(x);
			if (i == 1) {
				dp[i][j] = x;
			}
			else {
				dp[i][j] = x + max(dp[i - 1][j - 1], dp[i - 1][j]);
			}
			if (i == n) {
				if (dp[i][j] > ans) {
					ans = dp[i][j];
				}
			}
		}
	}
	printf("%d\n", ans);
    return 0;
}
