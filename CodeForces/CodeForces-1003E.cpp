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
const int maxn = 4e5+5;
const int mod = 1e9+7;
const double eps = 1e-8;
const double pi = asin(1.0)*2;
const double e = 2.718281828459;
bool Finish_read;
template<class T>inline void read(T &x){Finish_read=0;x=0;int f=1;char ch=getchar();while(!isdigit(ch)){if(ch=='-')f=-1;if(ch==EOF)return;ch=getchar();}while(isdigit(ch))x=x*10+ch-'0',ch=getchar();x*=f;Finish_read=1;}

int main(int argc, char *argv[]) {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#endif
	int n, d, k;
	read(n); read(d); read(k);
	if (d >= n) {
		printf("NO\n");
		return 0;
	}
	vector<int> deg(n);
	vector<PII> ans;
	set<PII> q;
	for (int i = 0; i < d; ++i) {
		++deg[i];
		++deg[i + 1];
		if (deg[i] > k || deg[i + 1] > k) {
			printf("NO\n");
			return 0;
		}
		ans.pb(mp(i, i + 1));
	}
	for (int i = 1; i < d; ++i) {
		q.insert(mp(max(i, d - i), i));
	}
	for (int i = d + 1; i < n; ++i) {
		while (!q.empty() && deg[q.begin() -> second] == k) {
			q.erase(q.begin());
		}
		if (q.empty() || q.begin() -> first == d) {
			printf("NO\n");
			return 0;
		}
		++deg[i];
		++deg[q.begin() -> second];
		ans.pb(mp(i, q.begin() -> second));
		q.insert(mp(q.begin() -> first + 1, i));
	}
	printf("YES\n");
	for (int i = 0; i < n - 1; ++i) {
		printf("%d %d\n", ans[i].first + 1, ans[i].second + 1);
	}
#ifndef ONLINE_JUDGE
	fclose(stdin);
	fclose(stdout);
	system("gedit out.txt");
#endif
    return 0;
}
