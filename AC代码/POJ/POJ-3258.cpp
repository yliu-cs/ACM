#include <iostream>
#include <cstdio>
#include <algorithm>
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
	int L, N, M;
	while (read(L) && read(N) && read(M)) {
		vector<int> Stone(N + 1, 0);
		for (int i = 1; i <= N; ++i) {
			read(Stone[i]);
		}
		// 按照距离升序排序
		sort(Stone.begin(), Stone.end());
		// 对结果二分
		int Left = 0, Right = L;
		while (Left <= Right) {
			int Mid = (Left + Right) / 2;
			int Keep = 0, Cnt = 0;
			for (int i = 1; i <= N; ++i) {
				// 更新记录选择的石头位置
				if (Stone[i] - Keep >= Mid) {
					Keep = Stone[i];
				}
				// 统计未选择石头个数
				else {
					Cnt++;
				}
			}
			if (L - Keep < Mid || Cnt > M) {
				Right = Mid - 1;
			}
			else {
				Left = Mid + 1;
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

