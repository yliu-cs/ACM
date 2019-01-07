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
const int maxn = 21;
const int mod = 1e9+7;
const double eps = 1e-8;
const double pi = asin(1.0)*2;
const double e = 2.718281828459;
bool Finish_read;
template<class T>inline void read(T &x){Finish_read=0;x=0;int f=1;char ch=getchar();while(!isdigit(ch)){if(ch=='-')f=-1;if(ch==EOF)return;ch=getchar();}while(isdigit(ch))x=x*10+ch-'0',ch=getchar();x*=f;Finish_read=1;}
inline void fre() {freopen("in.txt", "r", stdin);/*freopen("out.txt", "w", stdout);*/}

struct ac {
	int s, e, eff;
	bool operator < (const ac &a) const {
		return e < a.e;
	}
};

int main() {
//	fre();
	int n, m, r;
	read(n); read(m); read(r);
	vector<ac> a(m + 1);
	a[0].s = 0; a[0].e = 0; a[0].eff = 0;
	for (int i = 1; i <= m; ++i) {
		read(a[i].s); read(a[i].e); read(a[i].eff);
		a[i].e += r;
	}
	sort(a.begin(), a.end());
	vector<int> dp(m + 1);
	dp[0] = 0;
	int ans = 0;
	for (int i = 1; i <= m; ++i) {
		dp[i] = 0;
		for (int j = 0; j < i; ++j) {
			if (a[j].e <= a[i].s) {
				dp[i] = max(dp[i], dp[j] + a[i].eff);
			}
		}
		if (dp[i] > ans) {
			ans = dp[i];
		}
	}
	printf("%d\n", ans);
    return 0;
}
