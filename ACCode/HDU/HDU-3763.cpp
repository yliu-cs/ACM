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
	int N, M;
	while (read(N) && read(M) && N + M) {
		vector<int> Jack(N);
		for (int i = 0; i < N; ++i) {
			read(Jack[i]);
		}
		int ans = 0;
		for (int i = 0, Jill; i < M; ++i) {
			read(Jill);
			// 二分查找Jack中第一个编号大于等于Jill此CD编号的CD
			int Left = 0, Right = int(Jack.size());
			while (Left < Right) {
				int Mid = (Left + Right) / 2;
				if (Jack[Mid] < Jill) {
					Left = Mid + 1;
				}
				else {
					Right = Mid;
				}
			}
			// 若相等计数
			if (Jack[Left] == Jill) {
				ans++;
			}
		}
		print(ans);
	}
#ifndef ONLINE_JUDGE
    fclose(stdin);
    fclose(stdout);
    system("gedit out.txt");
#endif
    return 0;
}

