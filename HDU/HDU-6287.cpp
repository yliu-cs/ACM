#include <bits/stdc++.h>
using namespace std;
#define mem(a,b) memset(a,b,sizeof(a))
#define pb push_back
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> P;
const int INF = 0x3f3f3f3f;
const int maxn = 1e5+5;
const int mod = 1e9+7;
const double eps = 1e-8;
const double pi = asin(1.0)*2;
const double e = 2.718281828459;
void fre() {
    freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
}

/*
 * 将输入的每个a数组分解质因数、记录
 * 对d分解质因数判断a数组是否有足够的因数能够相乘满足成为输入d的倍数
 */

int t;
int n, m;
vector<int> G[maxn];

int query(int l, int r, int x) {
    return upper_bound(G[x].begin(), G[x].end(), r) - lower_bound(G[x].begin(), G[x].end(), l);
}

bool solve(int l, int r, int d) {
    for (int i = 2; i * i <= d; ++i) {
        if (d % i == 0) {
            int cnt = 0;
            while (d % i == 0) {
                cnt++;
                d /= i;
            }
            if (cnt > query(l, r, i)) {
                return 0;
            }
        }
    }
    if (d > 1) {
        if (query(l, r, d) < 1) {
            return 0;
        }
    }
    return 1;
}

int main(){
    //fre();
    scanf("%d", &t);
    for (int Case = 1; Case <= t; ++Case) {
        if (Case != 1) {
            for (int i = 0; i < maxn; ++i) {
                G[i].clear();
            }
        }
        scanf("%d%d", &n, &m);
        for (int i = 1, x; i <= n; ++i) {
            scanf("%d", &x);
            for (int j = 2; j * j <= x; ++j) {
                while (x % j == 0) {
                    x /= j;
                    G[j].pb(i);
                }
            }
            if (x > 1) {
                G[x].pb(i);
            }
        }
        while (m--) {
            int l, r, d;
            scanf("%d%d%d", &l, &r, &d);
            puts(solve(l, r, d) ? "Yes" : "No");
        }
    }
    return 0;
}
