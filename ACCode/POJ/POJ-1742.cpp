#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <climits>
#include <stdlib.h>
#include <deque>
#include <queue>
#include <stack>
#include <algorithm>
#include <list>
#include <map>
#include <set>
#include <utility>
#include <sstream>
#include <complex>
#include <string>
#include <vector>
#include <bitset>
#include <complex>
#include <functional>
#include <fstream>
#include <ctime>
#include <stdexcept>
using namespace std;
#define mem(a,b) memset(a,b,sizeof(a))
#define pb push_back
#define mp make_pair
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> P;
const int INF = 0x3f3f3f3f;
const int maxn = 1e5+5;
const int mod = 1e9+7;
const double eps = 1e-8;
const double pi = asin(1.0)*2;
const double e = 2.718281828459;
bool Finish_read;
template<class T>inline void read(T &x){Finish_read=0;x=0;int f=1;char ch=getchar();while(!isdigit(ch)){if(ch=='-')f=-1;if(ch==EOF)return;ch=getchar();}while(isdigit(ch))x=x*10+ch-'0',ch=getchar();x*=f;Finish_read=1;}
inline void fre() {freopen("in.txt", "r", stdin);/*freopen("out.txt", "w", stdout);*/}

int main() {
//	fre();
	int n, m;
	while (scanf("%d%d", &n, &m), n + m) {
		vector<int> a(n + 1);
		int c;
		bitset<maxn> s;
		s.set(0);
		for (int i = 1; i <= n; ++i) {
			read(a[i]);
		}
		for (int i = 1; i <= n; ++i) {
			read(c);
			for (int j = 1; j <= c; j *= 2) {
				s |= s << (a[i] * j);
				c -= j;
			}
			s |= s << (a[i] * c);
		}
		int ans = 0;
		for (int i = 1; i <= m; ++i) {
			if (s[i]) {
				ans++;
			}
		}
		printf("%d\n", ans);
	}
    return 0;
}
