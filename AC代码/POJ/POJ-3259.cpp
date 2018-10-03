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
const int maxn = 5e2+5;
const int mod = 1e6;
const double eps = 1e-8;
const double pi = asin(1.0)*2;
//const double e = 2.718281828459;
bool Finish_read;
template<class T>inline void read(T &x){Finish_read=0;x=0;int f=1;char ch=getchar();while(!isdigit(ch)){if(ch=='-')f=-1;if(ch==EOF)return;ch=getchar();}while(isdigit(ch))x=x*10+ch-'0',ch=getchar();x*=f;Finish_read=1;}

struct Edge {
	int u;
	int v;
	int cost;
	Edge(int _u = 0, int _v = 0, int _cost = 0): u(_u), v(_v), cost(_cost) {}
};

int T;
int n, m, w;
int s, e, t;
int dist[maxn];
vector<Edge> E;

bool BellmanFord() {
	mem(dist, INF);
	dist[1]= 0;
	for (int i = 1; i < n; ++i) {
		bool flag = 0;
		for (int j = 0; j < int(E.size()); ++j) {
			int u = E[j].u;
			int v = E[j].v;
			int cost = E[j].cost;
			if (dist[v] > dist[u] + cost) {
				dist[v] = dist[u] + cost;
				flag = 1;
			}
		}
		if (!flag) {
			return 1;
		}
	}
	for (int j = 0; j < int(E.size()); ++j) {
		if (dist[E[j].v] > dist[E[j].u] + E[j].cost) {
			return 0;
		}
	}
	return 1;
}

int main(int argc, char *argv[]) {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#endif
	read(T);
	while (T--) {
		read(n); read(m); read(w);
		for (int i = 1; i <= m; ++i) {
			read(s); read(e); read(t);
			Edge add;
			add.u = s;
			add.v = e;
			add.cost = t;
			E.pb(add);
			add.u = e;
			add.v = s;
			E.pb(add);
		}
		for (int i = 1; i <= w; ++i) {
			read(s); read(e); read(t);
			Edge add;
			add.u = s;
			add.v = e;
			add.cost = -t;
			E.pb(add);
		}
		if (BellmanFord()) {
			printf("NO\n");
		}
		else {
			printf("YES\n");
		}
		E.clear();
	}
#ifndef ONLINE_JUDGE
	fclose(stdin);
	fclose(stdout);
	system("gedit out.txt");
#endif
    return 0;
}
