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
const double eps = 1e-7;
const double pi = acos(-1.0);
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
	int T;
	read(T);
	for (int Case = 1, N, F; Case <= T; ++Case) {
		read(N); read(F);
		// 加上自己
		F++;
		// 读入半径，计算面积
		vector<double> S(N);
		for (int i = 0, R; i < N; ++i) {
			read(R);
			S[i] = pi * R * R;
		}
		// 二分结果，Right=1e8会WA
		double Left = 0, Right = 1e9;
		// eps=1e-4会WA,1e-8会TLE
		while (Right - Left > eps) {
			double Mid = (Left + Right) / 2;
			int Cnt = 0;
			for (int i = 0; i < N; ++i) {
				Cnt += int(S[i] / Mid);
			}
			// 可再分
			if (Cnt >= F) {
				Left = Mid;
			}
			// 不可再分
			else {
				Right = Mid;
			}
		}
		printf("%.4lf\n", Left);
	}
#ifndef ONLINE_JUDGE
    fclose(stdin);
    fclose(stdout);
    system("gedit out.txt");
#endif
    return 0;
}

