#include <bits/stdc++.h>
using namespace std;
#define mem(a,b) memset(a,b,sizeof(a))
#define pb push_back
#define mp make_pair
#define lowbit(x) (x&(-x))
#define XDebug(x) cout<<#x<<"="<<x<<endl;
#define ArrayDebug(x,i) cout<<#x<<"["<<i<<"]="<<x[i]<<endl;
#define print(x) out(x);putchar('\n')
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> PII;
typedef pair<double,double> PDD;
typedef pair<ll,ll> PLL;
const int INF = 0x3f3f3f3f;
const int maxn = 1e5 + 5;
const int mod = 1e9 + 7;
const double eps = 1e-8;
const double pi = asin(1.0) * 2;
const double e = 2.718281828459;
template <class T>
inline bool read(T &ret) {
    char c;
    int sgn;
    if (c = getchar(), c == EOF) {
        return 0;
    }
    while (c != '-' && (c < '0' || c > '9')) {
        c = getchar();
    }
    sgn = (c == '-') ? -1 : 1;
    ret = (c == '-') ? 0 : (c - '0');
    while (c = getchar(), c >= '0' && c <= '9') {
        ret = ret * 10 + (c - '0');
    }
    ret *= sgn;
    return 1;
}
template <class T>
inline void out(T x) {
    if (x < 0) {
        putchar('-');
        x = -x;
    }
    if (x > 9) {
        out(x / 10);
    }
    putchar(x % 10 + '0');
}

int main(int argc, char *argv[]) {
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
	ll T;
	read(T);
	for (ll Case = 1, N; Case <= T; ++Case) {
		read(N);
		vector<ll> Ary(N);
		for (ll i = 0; i < N; ++i) {
			read(Ary[i]);
		}
		// 二分结果
		ll Left = 0, Right = INF;
		while (Left <= Right) {
			ll Mid = (Left + Right) / 2;
			ll temp = 0;
			for (int i = 0; i < N; ++i) {
				// 若Ary[i]>Mid，则Ary[i]可提供一次-2操作
				if (Ary[i] > Mid) {
					temp += (Ary[i] - Mid) / 2;
				}
				// 否则Ary[i]需要增加到Mid
				else {
					temp += Ary[i] - Mid;
				}
			}
			// 最小值可以达到Mid或以上
			if (temp >= 0) {
				Left = Mid + 1;
			}
			// 最小值无法达到Mid
			else {
				Right = Mid - 1;
			}
		}
		print(Right);
	}
#ifndef ONLINE_JUDGE
    fclose(stdin);
    fclose(stdout);
    system("gedit out.txt");
#endif
    return 0;
}

