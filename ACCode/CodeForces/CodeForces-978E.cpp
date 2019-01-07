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
const int maxn = 1e3+5;
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
    int n, w;
    scanf("%d%d", &n, &w);
    ll maxx = -INF, minn = INF, num = 0;
    int input;
    bool flag = 1;
    for (int i = 1; i <= n; ++i) {
        scanf("%d", &input);
        num += input;
        if (abs(num) > w) {
            flag = 0;
        }
        if (!flag) {
            continue;
        }
        if (num > maxx) {
            maxx = num;
        }
        if (num < minn) {
            minn = num;
        }
    }
    ll ans;
    if (maxx < 0) {
        ans = w - abs(minn) + 1;
    }
    else {
        if (minn < 0) {
            w -= maxx;
            ans = w - abs(minn) + 1;
        }
        else {
            ans = w - maxx + 1;
        }
    }
    if (!flag || ans < 0) {
        ans = 0;
    }
    printf("%I64d", ans);
    return 0;
}
