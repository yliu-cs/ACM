#include <bits/stdc++.h>
using namespace std;
#define mem(a,b) memset(a,b,sizeof(a))
#define pb push_back
#define mp make_pair
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> P;
const int INF = 0x3f3f3f3f;
const int maxn = 2e2+5;
const int mod = 1e9+7;
const double eps = 1e-8;
const double pi = asin(1.0)*2;
const double e = 2.718281828459;
void fre() {
    freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
}

// 30000ms的时间限制，直接暴力模拟
/*
 * 开一个vector结构体容器
 * t=-1遍历删除第一个符号要求的结构体
 * t=1放入一个新结构体
 * t=0遍历计算p*x+q*y求出最大值即可
 */

struct candy {
    ll p, q;
};

vector<candy> vec;

int main() {
    //fre();
    ll n;
    while (cin >> n, n) {
        vec.clear();
        while (n--) {
            ll t, x, y;
            cin >> t >> x >> y;
            if (t == -1) {
                for (vector<candy>::iterator it = vec.begin(); it != vec.end(); ) {
                    candy temp = *it;
                    if (temp.p == x && temp.q == y) {
                        vec.erase(it);
                        break;
                    }
                    ++it;
                }
            }
            else if (t == 1) {
                candy temp;
                temp.p = x;
                temp.q = y;
                vec.pb(temp);
            }
            else if (t == 0) {
                ll ans = -INF;
                for (auto it : vec) {
                    ll temp = it.p * x + it.q * y;
                    if (temp > ans) {
                        ans = temp;
                    }
                }
                cout << ans << endl;
            }
        }
    }
    return 0;
}
