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
const int maxn = 1e3+5;
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
	int n, k;
	read(n); read(k);
	vector<PII> res(n);
	vector<int> a(n);
	for (int i = 0; i < n; ++i) {
		read(res[i].first);
		a[i] = res[i].first;
		res[i].second = i + 1;
	}
	sort(res.begin(), res.end(), [&] (const PII &a, const PII &b) {
		return a.first > b.first;
	});
	if (k == 1) {
		printf("%d\n%d\n", res[0].first, n);
		return 0;
	}
	sort(res.begin(), res.begin() + k, [&] (const PII &a, const PII &b) {
		return a.second < b.second;
	});
	vector<int> ans(k);
	int sum = res[0].first + res[k - 1].first;
	ans[0] = res[1].second - 1;
	ans[k - 1] = n - res[k - 1].second + 1;
	for (int i = 1; i < k - 1; ++i) {
		sum += res[i].first;
		ans[i] = res[i + 1].second - res[i].second;
	}
	printf("%d\n", sum);
	for (int i = 0; i < k; ++i) {
		printf("%d ", ans[i]);
	}
	printf("\n");
#ifndef ONLINE_JUDGE
	fclose(stdin);
	fclose(stdout);
	system("gedit out.txt");
#endif
    return 0;
}
