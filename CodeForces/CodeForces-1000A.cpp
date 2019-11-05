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
const int maxn = 1e5 + 5;
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
	map<string, int> m;
	m["XXXS"] = 0;
	m["XXS"] = 1;
	m["XS"] = 2;
	m["S"] = 3;
	m["M"] = 4;
	m["L"] = 5;
	m["XL"] = 6;
	m["XXL"] = 7;
	m["XXXL"] = 8;
	vector<int> ans(9, 0);
	int n;
	read(n);
	vector<string> s(n);
	string str;
	for (int i = 0; i < n; ++i) {
		cin >> s[i];
	}
	for (int i = 0; i < n; ++i) {
		cin >> str;
		ans[m[str]]++;
	}
	for (int i = 0; i < n; ++i) {
		if (ans[m[s[i]]]) {
			ans[m[s[i]]]--;
		}
	}
	printf("%d\n", accumulate(ans.begin(), ans.end(), 0));
#ifndef ONLINE_JUDGE
	fclose(stdin);
	fclose(stdout);
	system("gedit out.txt");
#endif
    return 0;
}
