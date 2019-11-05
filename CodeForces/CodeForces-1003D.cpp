#pragma comment(linker, "/STACK:102400000,102400000")
#include <bits/stdc++.h>
using namespace std;
#define mem(a,b) memset(a,b,sizeof(a))
#define pb push_back
#define mp make_pair
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> P;
const int INF = 0x3f3f3f3f;
const int maxn = 1e4+5;
const int mod = 1e6;
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
	int n, q;
	read(n); read(q);
	int x;
	map<int, int> amount;
	for (int i = 0; i < n; ++i) {
		read(x);
		amount[x]++;
	}
	int cnt;
	for (int i = 0; i < q; ++i) {
		read(x);
		cnt = 0;
		for (int j = 29; j >= 0; --j) {
			int num = (1 << j);
			if (num <= x) {
				int temp = x / num;
				if (temp <= amount[num]) {
					cnt += temp;
					x -= num * temp;
				}
				else {
					cnt += amount[num];
					x -= amount[num] * num;
				}
			}
		}
		if (!x) {
			printf("%d\n", cnt);
		}
		else {
			printf("-1\n");
		}
	}
#ifndef ONLINE_JUDGE
	fclose(stdin);
	fclose(stdout);
	system("gedit out.txt");
#endif
    return 0;
}
