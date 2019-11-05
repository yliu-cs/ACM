#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <vector>
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
const int maxn = 1e4 + 5;
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
	int N, K;
	while (~scanf("%d%d", &N, &K)) {
		// 木棒长度
		vector<double> Len(N);
		for (int i = 0; i < N; ++i) {
			scanf("%lf", &Len[i]);
		}
		// 二分结果
		double Left = 0, Right = 1e8;
		while (Right - Left > eps) {
			double Mid = (Left + Right) / 2;
			int Sum = 0;
			for (int i = 0; i < N; ++i) {
				Sum += Len[i] / Mid;
			}
			if (Sum >= K) {
				Left = Mid;
			}
			else {
				Right = Mid;
			}
		}
		// 不进位保留两位小数
		printf("%.2lf\n", floor(Right * 100) / 100);
	}
#ifndef ONLINE_JUDGE
    fclose(stdin);
	fclose(stdout);
    system("gedit out.txt");
#endif
    return 0;
}

