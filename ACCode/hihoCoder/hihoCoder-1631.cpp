#include <bits/stdc++.h>
using namespace std;
#define mem(a,b) memset(a,b,sizeof(a))
#define pb push_back
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> P;
const int INF = 0x3f3f3f3f;
const int maxn = 5e3+5;
const double eps = 1e-5;
const double pi = asin(1.0)*2;
const double e = 2.718281828459;

int m, n, x;
int c[maxn];
int a;
int cnt;
int _time[maxn];
int temp;

int main() {
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    while (scanf("%d%d%d", &m, &n, &x) != EOF) {
        mem(_time, 0);
        a = 0; cnt = 0;
        for (int i= 0; i < n; ++i) {
            scanf("%d", &c[i]);
        }
        sort(c, c + n);
        for (int i = 0; i < n; ++i) {
            _time[i] += c[i];
        }
        temp = m < n ? m : n;
        cnt = temp;
        for (int i = 1; i <= x; ++i) {
            for (int j = 0; j < temp; ++j) {
                if (_time[j] == i) {
                    a++;
                    if (cnt >= m) {
                        continue;
                    }
                    _time[j] += c[j];
                    if (i != x) {
                        cnt++;
                    }
                }
            }
        }
        printf("%d %d\n", m - cnt, cnt - a);
    }
   return 0;
}
