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
const int maxn = 3e2+5;
const int mod = 1e6;
const double eps = 1e-8;
const double pi = asin(1.0)*2;
const double e = 2.718281828459;
bool Finish_read;
template<class T>inline void read(T &x){Finish_read=0;x=0;int f=1;char ch=getchar();while(!isdigit(ch)){if(ch=='-')f=-1;if(ch==EOF)return;ch=getchar();}while(isdigit(ch))x=x*10+ch-'0',ch=getchar();x*=f;Finish_read=1;}

int n, m;
int q;
int ans;
int plat[maxn][maxn];
int res[maxn];

void Floyd() {
	for (int k = 1; k <= n; ++k) {
		for (int i = 1; i <= n; ++i) {
			for (int j = 1; j <= n; ++j) {
				plat[i][j] = min(plat[i][j], plat[i][k] + plat[k][j]);
			}
		}
	}
}

int main(int argc, char *argv[]) {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#endif
	while (~scanf("%d%d", &n, &m)) {
		mem(res, 0);
		for (int i = 0; i <= n; ++i) {
			for (int j = 0; j <= n; ++j) {
				if (i == j) {
					plat[i][j] = 0;
				}
				else {
					plat[i][j] = INF;
				}
			}
		}
		for (int i = 1; i <= m; ++i) {
			read(q);
			vector<int> m(q + 1);
			for (int j = 1; j <= q; ++j) {
				read(m[j]);
			}
			for (int j = 1; j <= q; ++j) {
				for (int k = j + 1; k <= q; ++k) {
					plat[m[j]][m[k]] = 1;
					plat[m[k]][m[j]] = 1;
				}
			}
		}
		Floyd();
		ans = INF;
		for (int i = 1; i <= n; ++i) {
			for (int j = 1; j <= n; ++j) {
				res[i] += plat[i][j];
			}
			ans = res[i] < ans ? res[i] : ans;
		}
		printf("%d\n", ans * 100 / (n - 1));
	}
#ifndef ONLINE_JUDGE
	fclose(stdin);
	fclose(stdout);
	system("gedit out.txt");
#endif
    return 0;
}
