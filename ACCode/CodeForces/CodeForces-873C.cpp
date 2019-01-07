#include <bits/stdc++.h>
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
const int maxn = 1e2 + 5;
const int mod = 1e9 + 7;
const double eps = 1e-8;
const double pi = asin(1.0) * 2;
const double e = 2.718281828459;
bool Finish_read;
template<class T>inline void read(T &x) {
	Finish_read = 0;
	x = 0;
	int f = 1;
	char ch = getchar();
	while (!isdigit(ch)) {
		if (ch == '-') {
			f = -1;
		}
		if (ch == EOF) {
			return;
		}
		ch = getchar();
	}
	while (isdigit(ch)) {
		x = x * 10 + ch - '0';
		ch = getchar();
	}
	x *= f;
	Finish_read = 1;
};

int main(int argc, char *argv[]) {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#endif
	int n, m, k;
	read(n); read(m); read(k);
	int a[maxn][maxn];
	mem(a, 0);
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			read(a[i][j]);
		}
	}
	int count = 0;
	for (int j = 0; j < m; ++j) {
		int cnt = 0, index = 0;;
		for (int i = 0; i < n; ++i) {
			int temp = 0;
			for (int o = i, cnt = 0; cnt < k; ++o, ++cnt) {
				if (o >= n) {
					break;
				}
				temp += a[o][j];
			}
			if (temp >= k) {
				index = i;
				break;
			}
			if (temp > cnt) {
				cnt = temp;
				index = i;
			}
		}
		for (int h = 0; h < index; ++h) {
			if (a[h][j]) {
				a[h][j] = 0;
				count++;
			}
		}
	}
	int ans = 0;
	for (int j = 0; j < m; ++j) {
		for (int i = 0; i < n; ++i) {
			if (a[i][j]) {
				for (int o = i, cnt = 0; cnt < k; ++o, ++cnt) {
					if (o >= n) {
						break;
					}
					ans += a[o][j];
				}
				break;
			}
		}
	}
	printf("%d %d\n", ans, count);
#ifndef ONLINE_JUDGE
	fclose(stdin);
	fclose(stdout);
	system("gedit out.txt");
#endif
    return 0;
}
