#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <algorithm>
#include <iomanip>
#include <cctype>
#include <cmath>
#include <stack>
#include <queue>
#include <vector>
#include <cstdlib>
#include <sstream>
#include <set>
#include <map>
using namespace std;
#define mem(a,b) memset(a,b,sizeof(a))
#define pb push_back
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> p;
const int inf = 0x3f3f3f3f;
const int maxn = 2e5+5;
const int mod = 1e9+7;
const double eps = 1e-5;
const double pi = asin(1.0)*2;
const double e = 2.718281828459;
void fre() {
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
}

int main() {
    //fre();
    int n, m;
    scanf("%d%d", &n, &m);
    ll a[maxn], sum[maxn];
    scanf("%I64d", &a[1]);
    sum[1] = a[1];
    for (int i = 2; i <= n; ++i) {
        scanf("%I64d", &a[i]);
        sum[i] = a[i] + sum[i - 1];
    }
    while (m--) {
        ll ask;
        scanf("%I64d", &ask);
        ll _left = 0, _right = n;
        while (_left < _right) {
            ll mid = (_left + _right) >> 1;
            if (sum[mid] >= ask) {
                _right = mid;
            }
            else {
                _left = mid + 1;
            }
        }
        printf("%I64d %I64d\n", _left, ask - sum[_left - 1]);
    }
    return 0;
}
