//#pragma comment(linker, "/STACK:102400000,102400000")
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
	int n;
	read(n);
	string a, b;
	cin >> a >> b;
	int ans = 0;
	for (int i = 0; i < n / 2; ++i) {
		if (a[i] == b[i] && a[n - i - 1] == b[n - i - 1]) {
			continue;
		}
		else if (a[i] == b[n - i - 1] && a[n - i - 1] == b[i]) {
			continue;
		}
		else if (a[i] == a[n - i - 1] && b[i] == b[n - i - 1]) {
			continue;
		}
		else if (a[i] == b[i] || a[i] == b[n - i - 1] || a[n - i - 1] == b[i] || a[n - i - 1] == b[n - i - 1] || b[i] == b[n - i -1]) {
			ans++;
		}
		else {
			ans += 2;
		}
	}
	if (n % 2) {
		if (a[n / 2] != b[n / 2]) {
			ans++;
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
