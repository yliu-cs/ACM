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
const int mod = 1e6;
const double eps = 1e-8;
const double pi = asin(1.0)*2;
const double e = 2.718281828459;
bool Finish_read;
template<class T>inline void read(T &x){Finish_read=0;x=0;int f=1;char ch=getchar();while(!isdigit(ch)){if(ch=='-')f=-1;if(ch==EOF)return;ch=getchar();}while(isdigit(ch))x=x*10+ch-'0',ch=getchar();x*=f;Finish_read=1;}

int n, m;
int a, b, l;
int ans;
int dis[maxn];
bool vis[maxn];
vector<P> Adj[maxn];

void Prim() {
	mem(dis, INF);
	mem(vis, 0);
	dis[1] = 0;
	for (int i = 1; i <= n; ++i) {
		int u = -1, min = INF;
		for (int j = 1; j <= n; ++j) {
			if (!vis[j] && dis[j] < min) {
				u = j;
				min = dis[j];
			}
		}
		vis[u] = 1;
		ans = min > ans ? min : ans;
		for (int j = 0; j < int(Adj[u].size()); ++j) {
			int v = Adj[u][j].first;
			if (!vis[v] && Adj[u][j].second < dis[v]) {
				dis[v] = Adj[u][j].second;
			}
		}
	}
}

int main(int argc, char *argv[]) {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#endif
	read(n); read(m);
	for (int i = 1; i <= m; ++i) {
		read(a); read(b); read(l);
		Adj[a].pb(mp(b, l));
		Adj[b].pb(mp(a, l));
	}
	ans = -1;
	Prim();
	printf("%d\n", ans);
#ifndef ONLINE_JUDGE
	fclose(stdin);
	fclose(stdout);
	system("gedit out.txt");
#endif
    return 0;
}
