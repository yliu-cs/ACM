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
	for (ll Case = 1, N, K; Case <= T; ++Case) {
		read(N); read(K);
		vector<ll> IQ;
		ll Sum = 0;
		for (ll i = 0, M; i < N; ++i) {
			read(M);
			vector<ll> Class;
			for (ll j = 0, Iq; j < M; ++j) {
				read(Iq);
				IQ.pb(Iq);
				Class.pb(Iq);
			}
			// 排序
			sort(Class.begin(), Class.end());
			// 枚举班级里的每个人
			for (ll j = 0; j < M; ++j) {
				ll Target = K - Class[j];
				// 二分查找两个人之和大于K的个数
				ll Left = j, Right = M;
				while (Left < Right) {
					ll Mid = (Left + Right) / 2;
					if (Class[Mid] <= Target) {
						Left = Mid + 1;
					}
					else {
						Right = Mid;
					}
				}
				// 有序数列直接计数
				Sum += M - Left + 1;
			}
		}
		// 对所有人进行排序
		sort(IQ.begin(), IQ.end());
		ll Ans = 0;
		// 枚举每个人
		for (ll i = 0; i < ll(IQ.size()); ++i) {
			ll Target = K - IQ[i];
			// 二分查找两人之和大于K的个数
			ll Left = i, Right = ll(IQ.size());
			while (Left < Right) {
				ll Mid = (Left + Right) / 2;
				if (IQ[Mid] <= Target) {
					Left = Mid + 1;
				}
				else {
					Right = Mid;
				}
			}
			// 有序数列直接计数
			Ans += ll(IQ.size()) - Left + 1;
		}
		// 所有人两人之和大于K的数量减去同一个班级内两人之和大于K的数量
		print(Ans - Sum);
	}
#ifndef ONLINE_JUDGE
    fclose(stdin);
    fclose(stdout);
    system("gedit out.txt");
#endif
    return 0;
}

