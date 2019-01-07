#pragma comment(linker, "/STACK:102400000,102400000")
#include <bits/stdc++.h>
using namespace std;
#define mem(a,b) memset(a,b,sizeof(a))
#define pb push_back
#define mp make_pair
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> PII;
typedef pair<double,double> PDD;
const int INF = 0x3f3f3f3f;
const int maxn = 1e5+5;
const int mod = 1e9+7;
const double eps = 1e-8;
const double pi = asin(1.0)*2;
const double e = 2.718281828459;
bool Finish_read;
template<class T>inline void read(T &x){Finish_read=0;x=0;int f=1;char ch=getchar();while(!isdigit(ch)){if(ch=='-')f=-1;if(ch==EOF)return;ch=getchar();}while(isdigit(ch))x=x*10+ch-'0',ch=getchar();x*=f;Finish_read=1;}

struct edge {
	double u;
	double v;
	double d;
	edge(double _u = 0, double _v = 0, double _d = 0): u(_u), v(_v), d(_d) {}
	bool operator < (const edge &a) const {
		return d > a.d;
	}
};

int n, m;
int tu, tv;
double ans;
PDD co[maxn];
int pre[maxn];
vector<edge> q;

void init() {
	for (int i = 1; i <= n; ++i) {
		pre[i] = i;
	}
}

int find(int x) {
	if (x == pre[x]) {
		return pre[x];
	}
	else {
		pre[x] = find(pre[x]);
		return pre[x];
	}
}

double caldis(PDD a, PDD b) {
	return sqrt((a.first - b.first) * (a.first - b.first) + (a.second - b.second) * (a.second - b.second));
}

int main(int argc, char *argv[]) {
//#ifndef ONLINE_JUDGE
//	freopen("in.txt", "r", stdin);
//	freopen("out.txt", "w", stdout);
//#endif
	read(n); read(m);
	init();
	for (int i = 1; i <= n; ++i) {
		read(co[i].first);
		read(co[i].second);
	}
	for (int i = 1; i <= m; ++i) {
		read(tu); read(tv);
		q.pb(edge(tu, tv, caldis(co[tu], co[tv])));
	}
	sort(q.begin(), q.end());
	ans = 0;
	for (int i = 0; i < int (q.size()); ++i) {
		int x = find(q[i].u), y = find(q[i].v);
		if (x != y) {
			pre[x] = y;
		}
		else {
			ans += q[i].d;
		}
	}
	printf("%.3lf\n", ans);
//#ifndef ONLINE_JUDGE
//	fclose(stdin);
//	fclose(stdout);
//	system("gedit out.txt");
//#endif
    return 0;
}
