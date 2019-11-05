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
typedef pair<int,int> P;
const int INF = 0x3f3f3f3f;
const int maxn = 1e5+5;
const double eps = 1e-5;
const double pi = asin(1.0)*2;
const double e = 2.718281828459;

ll n, k;
ll d;
ll judge;
ll sum;
ll sqr;

int main() {
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    d = -1;
    scanf("%lld%lld", &n, &k);
    if (k > 141420) {
        printf("-1");
        return 0;
    }
    judge = k * (k + 1) / 2;
    sum = k * (k - 1) / 2;
    sqr = sqrt(n);
    for (int i = 1; i <= sqr; ++i) {
        if (n % i) {
            continue;
        }
        if (i >= judge) {
            d = n / i;
            break;
        }
        if (n - i * sum > (k - 1) * i) {
            d = i;
        }
    }
    if (d == -1) {
        printf("-1");
    }
    else {
        for (int i = 1; i < k; ++i) {
            printf("%lld ", i * d);
        }
        printf("%lld", n - d * k * (k - 1) / 2);
    }
   return 0;
}
