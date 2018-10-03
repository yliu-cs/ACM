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
const int maxn = 1e3+5;
const int mod = 1e6;
const double eps = 1e-8;
const double pi = asin(1.0)*2;
const double e = 2.718281828459;
bool Finish_read;
template<class T>inline void read(T &x){Finish_read=0;x=0;int f=1;char ch=getchar();while(!isdigit(ch)){if(ch=='-')f=-1;if(ch==EOF)return;ch=getchar();}while(isdigit(ch))x=x*10+ch-'0',ch=getchar();x*=f;Finish_read=1;}

int n, m, x;
int a, b, t;
int ans;
int Dis[maxn];
int Vis[maxn];
int BackDis[maxn];
bool BackVis[maxn];
vector<P> Adj[maxn];

struct cmp {
	template<typename T, typename U>
	bool operator() (T const &a, U const &b) {
		return a.second > b.second;
	}
};

int Dijkstra(int s) {
	mem(Dis, INF);
	mem(Vis, 0);
	Dis[s] = 0;
	priority_queue<P, vector<P>, cmp> que;
	que.push(mp(s, 0));
	while (!que.empty()) {
		P keep = que.top();
		que.pop();
		int v = keep.first;
		if (Dis[v] < keep.second || Vis[v]) {
			continue;
		}
		if (v == x) {
			return Dis[v];
		}
		Vis[v] = 1;
		for (int i = 0; i < int(Adj[v].size()); ++i) {
			P e = Adj[v][i];
			if (!Vis[e.first] && Dis[e.first] > Dis[v] + e.second) {
				Dis[e.first] = Dis[v] + e.second;
				que.push(mp(e.first, Dis[e.first]));
			}
		}
	}
	return -1;
}

void BackDijkstra() {
	mem(BackDis, INF);
	mem(BackVis, 0);
	BackDis[x] = 0;
	priority_queue<P, vector<P>, cmp> que;
	que.push(mp(x, 0));
	while (!que.empty()) {
		P keep = que.top();
		que.pop();
		int v = keep.first;
		if (BackDis[v] < keep.second || BackVis[v]) {
			continue;
		}
		BackVis[v] = 1;
		for (int i = 0; i < int(Adj[v].size()); ++i) {
			P e = Adj[v][i];
			if (!BackVis[e.first] && BackDis[e.first] > BackDis[v] + e.second) {
				BackDis[e.first] = BackDis[v] + e.second;
				que.push(mp(e.first, BackDis[e.first]));
			}
		}
	}
}

int main(int argc, char *argv[]) {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#endif
	read(n); read(m); read(x);
	for (int i = 1; i <= m; ++i) {
		read(a); read(b); read(t);
		Adj[a].pb(mp(b, t));
	}
	BackDijkstra();
	ans = -1;
	for (int i = 1; i <= n; ++i) {
		if (i != x) {
			int temp = Dijkstra(i) + BackDis[i];
			ans = temp > ans ? temp : ans;
		}
	}
	printf("%d\n", ans);
#ifndef ONLINE_JUDGE
	fclose(stdin);
	fclose(stdout);
	system("gedit out.txt");
#endif
    return 0;
}
