#pragma comment(linker, "/STACK:102400000,102400000")
//#include <bits/stdc++.h>
#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
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
const int maxn = 1e3+10;
const int mod = 1e9+7;
const double eps = 1e-8;
const double pi = asin(1.0)*2;
const double e = 2.718281828459;
bool Finish_read;
template<class T>inline void read(T &x){Finish_read=0;x=0;int f=1;char ch=getchar();while(!isdigit(ch)){if(ch=='-')f=-1;if(ch==EOF)return;ch=getchar();}while(isdigit(ch))x=x*10+ch-'0',ch=getchar();x*=f;Finish_read=1;}

struct link {
	int x, y;
};

int t;
int n, m, k;
ll ans;
link edge[1003*1002];
ll sum[maxn];

bool cmp(link a, link b) {
	if (a.x == b.x) {
		return a.y <= b.y;
	}
	return a.x < b.x;
}

void update(int x) {
	while (x <= m) {
		sum[x]++;
		x += lowbit(x);
	}
}

ll getSum(int x) {
	ll res = 0;
	while (x > 0) {
		res += sum[x];
		x -= lowbit(x);
	}
	return res;
}

int main(int argc, char *argv[]) {
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
	read(t);
	for (int Case = 1; Case <= t; ++Case) {
		read(n); read(m); read(k);
		for (int i = 0; i < k; ++i) {
			read(edge[i].x); read(edge[i].y);
		}
		sort(edge, edge + k, cmp);
		ans = 0;
		mem(sum, 0);
		for (int i = 0; i < k; ++i) {
			update(edge[i].y);
			ans += getSum(m) - getSum(edge[i].y);
		}
		printf("Test case %d: %lld\n", Case, ans);
 	}
#ifndef ONLINE_JUDGE
    fclose(stdin);
    fclose(stdout);
    system("gedit out.txt");
#endif
    return 0;
}
