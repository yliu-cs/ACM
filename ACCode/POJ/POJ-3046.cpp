#pragma comment(linker, "/STACK:102400000,102400000")
//#include <bits/stdc++.h>
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
const int maxn = 1e4+5;
const int mod = 1e6;
const double eps = 1e-8;
const double pi = asin(1.0)*2;
const double e = 2.718281828459;
bool Finish_read;
template<class T>inline void read(T &x){Finish_read=0;x=0;int f=1;char ch=getchar();while(!isdigit(ch)){if(ch=='-')f=-1;if(ch==EOF)return;ch=getchar();}while(isdigit(ch))x=x*10+ch-'0',ch=getchar();x*=f;Finish_read=1;}

int t, a, s, b;
int x;
int cnt;
int ans;
int dp[maxn][maxn];
map<int, int> amount;

int main(int argc, char *argv[]) {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#endif
	read(t); read(a); read(s); read(b);
	for (int i = 1; i <= a; ++i) {
		read(x);
		amount[x]++;
	}
	dp[0][0] = 1;
	cnt = amount[0];
	for (int i = 1; i <= t; ++i) {
		cnt += amount[i];
		for (int k = 0; k <= amount[i]; ++k) {
			for (int j = cnt; j >= k; --j) {
				dp[i][j] += dp[i - 1][j - k];
				dp[i][j] %= mod;
			}
		}
	}
	ans = 0;
	for (int i = s; i <= b; ++i) {
		ans += dp[t][i];
		ans %= mod;
	}
	printf("%d\n", ans);
#ifndef ONLINE_JUDGE
	fclose(stdin);
	fclose(stdout);
	system("gedit out.txt");
#endif
    return 0;
}
