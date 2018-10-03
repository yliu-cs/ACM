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
const int INF = 0x3f3f3f3f;
const int maxn = 1e5+5;
const int mod = 1e9+7;
const double eps = 1e-5;
const double pi = asin(1.0)*2;
const double e = 2.718281828459;
void fre() {
    freopen("in.txt", "r", stdin);
//    freopen("out.txt", "w", stdout);
}

int main() {
    //fre();
    int n;
    scanf("%d", &n);
    int a[maxn];
    for (int i = 0; i < n; ++i) {
        scanf("%d", &a[i]);
    }
    int ans = INF;
    int d, s, x, k;
    for (int i = -1; i < n; ++i) {
        for (int j = -1; j <= 1; ++j) {
            d = (a[1] + j) - (a[0] + i);
            s = abs(i);
            for (k = 1; k < n; ++k) {
                x = abs(a[k] - (a[0] + i + k * d));
                if (x > 1) {
                    break;
                }
                s += x;
            }
            if (k == n) {
                ans = min(ans, s);
            }
        }
    }
    ans = ans == INF ? -1 : ans;
    printf("%d", ans);
    return 0;
}
