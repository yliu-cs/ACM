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
	int T;
	read(T);
	for (int Case = 1, N, K; Case <= T; ++Case) {
		read(N); read(K);
		// Sum[i]存数列前i项和
		vector<int> Sum(N + 1, 0);
		for (int i = 1, Num; i <= N; ++i) {
			read(Num);
			Sum[i] = Sum[i - 1] + Num;
		}
		// 特判所有数之和无法到达K值
		if (Sum[N] < K) {
			print(0);
			continue;
		}
		// 二分结果
		int Left = 0, Right = N;
		while (Left < Right) {
			int Mid = (Left + Right) / 2;
			// 查找此Mid长度下是否有数列大于等于K
			bool flag = 0;
			for (int i = 1; i <= N; ++i) {
				if (i + Mid - 1 > N) {
					break;
				}
				if (Sum[i + Mid - 1] - Sum[i - 1] >= K) {
					flag = 1;
					break;
				}
			}
			if (flag) {
				Right = Mid;
			}
			else {
				Left = Mid + 1;
			}
		}
		print(Left);
	}
#ifndef ONLINE_JUDGE
    fclose(stdin);
    fclose(stdout);
    system("gedit out.txt");
#endif
    return 0;
}

