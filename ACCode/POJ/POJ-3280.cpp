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
const int maxn = 2e3+5;
const int mod = 1e9+7;
const double eps = 1e-8;
const double pi = asin(1.0)*2;
const double e = 2.718281828459;
bool Finish_read;
template<class T>inline void read(T &x){Finish_read=0;x=0;int f=1;char ch=getchar();while(!isdigit(ch)){if(ch=='-')f=-1;if(ch==EOF)return;ch=getchar();}while(isdigit(ch))x=x*10+ch-'0',ch=getchar();x*=f;Finish_read=1;}
inline void fre() {freopen("in.txt", "r", stdin);/*freopen("out.txt", "w", stdout);*/}

int n, m;
string str;
char x;
int add, del;
int dp[maxn][maxn];
map<char, int> r;

inline int min(int a, int b, int c) {
	return min(min(a, b), c);
}

int main() {
//	fre();
	read(n); read(m);
	cin >> str;
	for (int i = 1; i <= n; ++i) {
		cin >> x;
		read(add); read(del);
		r[x] = add < del ? add : del;
	}
	mem(dp, 0);
	for (int k = 1; k < m; ++k) {
		for (int i = 0, j = k; j < m; ++i, ++j) {
			dp[i][j] = INF;
			if (str[i] == str[j]) {
				dp[i][j] = dp[i + 1][j - 1];
			}
			else {
				dp[i][j] = min(dp[i + 1][j] + r[str[i]], dp[i][j], dp[i][j - 1] + r[str[j]]);
			}
		}
	}
	printf("%d\n", dp[0][m - 1]);
    return 0;
}
