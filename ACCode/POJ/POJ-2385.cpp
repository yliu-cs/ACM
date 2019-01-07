#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <climits>
#include <stdlib.h>
#include <deque>
#include <queue>
#include <stack>
#include <algorithm>
#include <list>
#include <map>
#include <set>
#include <utility>
#include <sstream>
#include <complex>
#include <string>
#include <vector>
#include <bitset>
#include <complex>
#include <functional>
#include <fstream>
#include <ctime>
#include <stdexcept>
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
bool Finish_read;
template<class T>inline void read(T &x){Finish_read=0;x=0;int f=1;char ch=getchar();while(!isdigit(ch)){if(ch=='-')f=-1;if(ch==EOF)return;ch=getchar();}while(isdigit(ch))x=x*10+ch-'0',ch=getchar();x*=f;Finish_read=1;}
inline void fre() {freopen("in.txt", "r", stdin);/*freopen("out.txt", "w", stdout);*/}

int main() {
//	fre();
	int t, w;
	read(t); read(w);
	int dp[maxn][35];
	mem(dp, 0);
	vector<int> a(t + 1);
	for (int i = 1; i <= t; ++i) {
		read(a[i]);
	}
	if (a[1] == 1) {
		dp[1][0] = 1;
		dp[1][1] = 0;
	}
	else {
		dp[1][0] = 0;
		dp[1][1] = 1;
	}
	int ans = 0;
	for (int i = 2; i <= t; ++i) {
		for (int j = 0; j <= w; ++j) {
			if (j == 0) {
				dp[i][j] = dp[i - 1][j];
				if (a[i] == 1) {
					dp[i][j]++;
				}
			}
			else {
				dp[i][j] = max(dp[i - 1][j - 1], dp[i - 1][j]);
				if (j % 2 + 1 == a[i]) {
					dp[i][j]++;
				}
			}
			if (i == t) {
				if (dp[i][j] > ans) {
					ans = dp[i][j];
				}
			}
		}
	}
	printf("%d\n", ans);
    return 0;
}
