#include <bits/stdc++.h>
using namespace std;
#define mem(a,b) memset(a,b,sizeof(a))
#define pb push_back
#define mp make_pair
#define lowbit(x) (x&(-x))
#define XDebug(x) cout<<#x<<"="<<x<<endl;
#define ArrayDebug(x,i) cout<<#x<<"["<<i<<"]="<<x[i]<<endl;
#define print(x) out(x);putchar('\n')
#define Fread(x) fastIO::read(x)
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
// 对这道题并不管用的读写挂
template <class T>
inline bool read(T &ret) {
    char c;
    int sgn;
    if (c = getchar(), c == EOF) {
        return false;
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
    return true;
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
// 超超超超超超级牛逼的读写挂
namespace fastIO {
	const int MX = 4e7;
	char buf[MX];
	int c, sz;
	void begin() {
		c = 0;
		sz = fread(buf, 1, MX, stdin);
	}
	template <class T>
	inline bool read(T &t) {
		while (c < sz && buf[c] != '-' && (buf[c] < '0' || buf[c] > '9')) {
			c++;
		}
		if (c >= sz) {
			return false;
		}
		bool flag = 0;
		if (buf[c] == '-') {
			flag = 1;
			c++;
		}
		for (t = 0; c < sz && '0' <= buf[c] && buf[c] <= '9'; ++c) {
			t = t * 10 + buf[c] - '0';
		}
		if (flag) {
			t = -t;
		}
		return true;
	}
}

int main(int argc, char *argv[]) {
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
	fastIO::begin();
	int T;
	Fread(T);
	for (int Case = 1, N, K; Case <= T; ++Case) {
		Fread(N); Fread(K);
		// 初始能力值
		int Able[6];
		for (int i = 0; i < K; ++i) {
			Fread(Able[i]);
		}
		// 优先队列分别存怪兽的最多五个属性
		priority_queue<PII, vector<PII>, greater<PII> > Monster[6];
		// 杀掉怪兽所获取的属性加强值
		int Profit[maxn][6];
		for (int i = 0; i < N; ++i) {
			for (int j = 0, X; j < K; ++j) {
				Fread(X);
				Monster[j].push(mp(X, i));
			}
			for (int j = 0; j < K; ++j) {
				Fread(Profit[i][j]);
			}
		}
		bool Flag = 1;
		int Cnt = 0;
		// 统计每个怪兽有哪些属性已经可以被击破
		int Statistic[maxn];
		mem(Statistic, 0);
		// 不断更新可以击杀的怪兽
		while (Flag) {
			Flag = 0;
			// 遍历K个属性
			for (int i = 0; i < K; ++i) {
				while (!(Monster[i].empty())) {
					PII Temp = Monster[i].top();
					// 若当前属性可以被击破
					if (Temp.first <= Able[i]) {
						// 弹出并统计
						Monster[i].pop();
						Statistic[Temp.second]++;
						// 若此怪兽所有属性都可被击破则获取属性加强
						if (Statistic[Temp.second] == K) {
							for (int i = 0; i < K; ++i) {
								Able[i] += Profit[Temp.second][i];
							}
							Cnt++;
							Flag = 1;
						}
					}
					else {
						break;
					}
				}
			}
		}
		print(Cnt);
		for (int i = 0; i < K; ++i) {
			out(Able[i]);
			if (i != K - 1) {
				putchar(' ');
			}
		}
		putchar('\n');
	}
#ifndef ONLINE_JUDGE
    fclose(stdin);
    fclose(stdout);
    system("gedit out.txt");
#endif
    return 0;
}

